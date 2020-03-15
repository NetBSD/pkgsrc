/*
 * Copyright © 2008 Kristian Høgsberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "config.h"

#ifndef container_of
#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) * __mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })
#endif

#ifdef HAVE_SYS_EVENT_H
#include <stddef.h>
#include <stdio.h>
#include <err.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <unistd.h>
#include "wayland-util.h"
#include "wayland-private.h"
#include "wayland-server-core.h"
#include "wayland-os.h"

/** \cond INTERNAL */

struct wl_event_loop {
	int event_fd;
	struct wl_list check_list;
	struct wl_list idle_list;
	struct wl_list destroy_list;

	struct wl_signal destroy_signal;
};

struct wl_event_source_interface {
	int (*dispatch)(struct wl_event_source *source,
			struct kevent *ev);
};

struct wl_event_source {
	struct wl_event_source_interface *interface;
	struct wl_event_loop *loop;
	struct wl_list link;
	void *data;
	int fd;
};

struct wl_event_source_fd {
	struct wl_event_source base;
	wl_event_loop_fd_func_t func;
	int fd;
};

/** \endcond */

static int
wl_event_source_fd_dispatch(struct wl_event_source *source,
			    struct kevent *ev)
{
	struct wl_event_source_fd *fd_source = (struct wl_event_source_fd *) source;
	uint32_t mask;

	mask = 0;
	if (ev->filter == EVFILT_READ)
		mask |= WL_EVENT_READABLE;
	if (ev->filter == EVFILT_WRITE)
		mask |= WL_EVENT_WRITABLE;
	if (ev->flags & EV_EOF)
		mask |= WL_EVENT_HANGUP;
	if (ev->flags & EV_ERROR)
		mask |= WL_EVENT_ERROR;

	return fd_source->func(source->fd, mask, source->data);
}

struct wl_event_source_interface fd_source_interface = {
	wl_event_source_fd_dispatch,
};

static struct wl_event_source *
add_source(struct wl_event_loop *loop,
	   struct wl_event_source *source, uint32_t mask, void *data)
{
	source->loop = loop;
	source->data = data;
	wl_list_init(&source->link);

	return source;
}

/** Create a file descriptor event source
 *
 * \param loop The event loop that will process the new source.
 * \param fd The file descriptor to watch.
 * \param mask A bitwise-or of which events to watch for: \c WL_EVENT_READABLE,
 * \c WL_EVENT_WRITABLE.
 * \param func The file descriptor dispatch function.
 * \param data User data.
 * \return A new file descriptor event source.
 *
 * The given file descriptor is initially watched for the events given in
 * \c mask. This can be changed as needed with wl_event_source_fd_update().
 *
 * If it is possible that program execution causes the file descriptor to be
 * read while leaving the data in a buffer without actually processing it,
 * it may be necessary to register the file descriptor source to be re-checked,
 * see wl_event_source_check(). This will ensure that the dispatch function
 * gets called even if the file descriptor is not readable or writable
 * anymore. This is especially useful with IPC libraries that automatically
 * buffer incoming data, possibly as a side-effect of other operations.
 *
 * \sa wl_event_loop_fd_func_t
 * \memberof wl_event_source
 */
WL_EXPORT struct wl_event_source *
wl_event_loop_add_fd(struct wl_event_loop *loop,
		     int fd, uint32_t mask,
		     wl_event_loop_fd_func_t func,
		     void *data)
{
	struct wl_event_source_fd *source;

	struct kevent events[2];
	unsigned int num_events = 0;

	source = malloc(sizeof *source);
	if (source == NULL)
		return NULL;

	source->base.interface = &fd_source_interface;
	source->base.fd = wl_os_dupfd_cloexec(fd, 0);
	source->func = func;
	source->fd = fd;
	add_source(loop, &source->base, mask, data);

	if (source->base.fd < 0) {
		fprintf(stderr, "could not add source\n: %s", strerror(errno));
		free(source);
		return NULL;
	}

	if (mask & WL_EVENT_READABLE) {
		EV_SET(&events[num_events], source->base.fd, EVFILT_READ,
		      EV_ADD | EV_ENABLE, 0, 0, &source->base);
		num_events++;
	}

	if (mask & WL_EVENT_WRITABLE) {
		EV_SET(&events[num_events], source->base.fd, EVFILT_WRITE,
		      EV_ADD | EV_ENABLE, 0, 0, &source->base);
		num_events++;
	}

	if (kevent(loop->event_fd, events, num_events, NULL, 0, NULL) < 0) {
		fprintf(stderr, "error adding source %i (%p) to loop %p: %s\n",
		       source->fd, source, loop, strerror(errno));
		close(source->base.fd);
		free(source);
		return NULL;
	}

	return &source->base;
}

/** Update a file descriptor source's event mask
 *
 * \param source The file descriptor event source to update.
 * \param mask The new mask, a bitwise-or of: \c WL_EVENT_READABLE,
 * \c WL_EVENT_WRITABLE.
 * \return 0 on success, -1 on failure.
 *
 * This changes which events, readable and/or writable, cause the dispatch
 * callback to be called on.
 *
 * File descriptors are usually writable to begin with, so they do not need to
 * be polled for writable until a write actually fails. When a write fails,
 * the event mask can be changed to poll for readable and writable, delivering
 * a dispatch callback when it is possible to write more. Once all data has
 * been written, the mask can be changed to poll only for readable to avoid
 * busy-looping on dispatch.
 *
 * \sa wl_event_loop_add_fd()
 * \memberof wl_event_source
 */
WL_EXPORT int
wl_event_source_fd_update(struct wl_event_source *source, uint32_t mask)
{
	struct wl_event_loop *loop = source->loop;
	struct kevent events[2];
	unsigned int num_events = 0;

	if (mask & WL_EVENT_READABLE) {
		EV_SET(&events[num_events], source->fd, EVFILT_READ,
		       EV_ADD | EV_ENABLE, 0, 0, source);
		num_events++;
	}

	if (mask & WL_EVENT_WRITABLE) {
		EV_SET(&events[num_events], source->fd, EVFILT_WRITE,
		       EV_ADD | EV_ENABLE, 0, 0, source);
		num_events++;
	}

	return kevent(loop->event_fd, events, num_events, NULL, 0, NULL);
}

/** \cond INTERNAL */

struct wl_event_source_timer {
	struct wl_event_source base;
	wl_event_loop_timer_func_t func;
};

/** \endcond */

static int
wl_event_source_timer_dispatch(struct wl_event_source *source,
			       struct kevent *ev)
{
	struct wl_event_source_timer *timer_source =
		(struct wl_event_source_timer *) source;
	return timer_source->func(timer_source->base.data);
}

struct wl_event_source_interface timer_source_interface = {
	wl_event_source_timer_dispatch,
};

/** Create a timer event source
 *
 * \param loop The event loop that will process the new source.
 * \param func The timer dispatch function.
 * \param data User data.
 * \return A new timer event source.
 *
 * The timer is initially disarmed. It needs to be armed with a call to
 * wl_event_source_timer_update() before it can trigger a dispatch call.
 *
 * \sa wl_event_loop_timer_func_t
 * \memberof wl_event_source
 */
WL_EXPORT struct wl_event_source *
wl_event_loop_add_timer(struct wl_event_loop *loop,
			wl_event_loop_timer_func_t func,
			void *data)
{
	static int next_timer_id = 0;
	struct wl_event_source_timer *source;

	source = malloc(sizeof *source);
	if (source == NULL)
		return NULL;
	source->base.interface = &timer_source_interface;
	source->base.fd = next_timer_id++;
	source->base.loop = loop;
	source->base.data = data;
	source->func = func;
	wl_list_init(&source->base.link);

	return &source->base;
}

/** Arm or disarm a timer
 *
 * \param source The timer event source to modify.
 * \param ms_delay The timeout in milliseconds.
 * \return 0 on success, -1 on failure.
 *
 * If the timeout is zero, the timer is disarmed.
 *
 * If the timeout is non-zero, the timer is set to expire after the given
 * timeout in milliseconds. When the timer expires, the dispatch function
 * set with wl_event_loop_add_timer() is called once from
 * wl_event_loop_dispatch(). If another dispatch is desired after another
 * expiry, wl_event_source_timer_update() needs to be called again.
 *
 * \memberof wl_event_source
 */
WL_EXPORT int
wl_event_source_timer_update(struct wl_event_source *source, int ms_delay)
{
	struct kevent ev;

	if (ms_delay == 0) {
		EV_SET(&ev, source->fd, EVFILT_TIMER, EV_DISABLE, 0,
		       ms_delay, source);
	} else {
		EV_SET(&ev, source->fd, EVFILT_TIMER,
		       EV_ADD | EV_ENABLE | EV_DISPATCH, 0, ms_delay, source);
	}

	if (kevent(source->loop->event_fd, &ev, 1, NULL, 0, NULL) < 0) {
		fprintf(stderr, "could not set kqueue timer: %s",
		        strerror(errno));
		return -1;
	}

	return 0;
}

/** \cond INTERNAL */

struct wl_event_source_signal {
	struct wl_event_source base;
	int signal_number;
	wl_event_loop_signal_func_t func;
};

/** \endcond */

static int
wl_event_source_signal_dispatch(struct wl_event_source *source,
				struct kevent *ev)
{
	struct wl_event_source_signal *signal_source;

	signal_source = (struct wl_event_source_signal *) source;

	return signal_source->func(signal_source->base.fd,
	                           signal_source->base.data);
}

struct wl_event_source_interface signal_source_interface = {
	wl_event_source_signal_dispatch,
};

/** Create a POSIX signal event source
 *
 * \param loop The event loop that will process the new source.
 * \param signal_number Number of the signal to watch for.
 * \param func The signal dispatch function.
 * \param data User data.
 * \return A new signal event source.
 *
 * This function blocks the normal delivery of the given signal in the calling
 * thread, and creates a "watch" for it. Signal delivery no longer happens
 * asynchronously, but by wl_event_loop_dispatch() calling the dispatch
 * callback function \c func.
 *
 * It is the caller's responsibility to ensure that all other threads have
 * also blocked the signal.
 *
 * \sa wl_event_loop_signal_func_t
 * \memberof wl_event_source
 */
WL_EXPORT struct wl_event_source *
wl_event_loop_add_signal(struct wl_event_loop *loop,
			int signal_number,
			wl_event_loop_signal_func_t func,
			void *data)
{
	struct wl_event_source_signal *source;
	sigset_t mask;
	struct kevent ev;

	source = malloc(sizeof *source);
	if (source == NULL)
		return NULL;

	source->base.interface = &signal_source_interface;
	source->signal_number = signal_number;
	source->func = func;

	sigemptyset(&mask);
	sigaddset(&mask, signal_number);
	sigprocmask(SIG_BLOCK, &mask, NULL);

	source->base.fd = 0;
	add_source(loop, &source->base, WL_EVENT_READABLE, data);

	EV_SET(&ev, signal_number, EVFILT_SIGNAL, EV_ADD | EV_ENABLE, 0, 0,
	       source);

	if (kevent(loop->event_fd, &ev, 1, NULL, 0, NULL) < 0) {
		fprintf(stderr, "error adding signal for %i (%p), %p: %s\n",
			signal_number, source, loop, strerror(errno));
		free(source);
		return NULL;
	}

	return &source->base;
}

/** \cond INTERNAL */

struct wl_event_source_idle {
	struct wl_event_source base;
	wl_event_loop_idle_func_t func;
};

/** \endcond */

struct wl_event_source_interface idle_source_interface = {
	NULL,
};

/** Create an idle task
 *
 * \param loop The event loop that will process the new task.
 * \param func The idle task dispatch function.
 * \param data User data.
 * \return A new idle task (an event source).
 *
 * Idle tasks are dispatched before wl_event_loop_dispatch() goes to sleep.
 * See wl_event_loop_dispatch() for more details.
 *
 * Idle tasks fire once, and are automatically destroyed right after the
 * callback function has been called.
 *
 * An idle task can be cancelled before the callback has been called by
 * wl_event_source_remove(). Calling wl_event_source_remove() after or from
 * within the callback results in undefined behaviour.
 *
 * \sa wl_event_loop_idle_func_t
 * \memberof wl_event_source
 */
WL_EXPORT struct wl_event_source *
wl_event_loop_add_idle(struct wl_event_loop *loop,
		       wl_event_loop_idle_func_t func,
		       void *data)
{
	struct wl_event_source_idle *source;

	source = malloc(sizeof *source);
	if (source == NULL)
		return NULL;

	source->base.interface = &idle_source_interface;
	source->base.loop = loop;
	source->base.fd = -1;

	source->func = func;
	source->base.data = data;

	wl_list_insert(loop->idle_list.prev, &source->base.link);

	return &source->base;
}

/** Mark event source to be re-checked
 *
 * \param source The event source to be re-checked.
 *
 * This function permanently marks the event source to be re-checked after
 * the normal dispatch of sources in wl_event_loop_dispatch(). Re-checking
 * will keep iterating over all such event sources until the dispatch
 * function for them all returns zero.
 *
 * Re-checking is used on sources that may become ready to dispatch as a
 * side-effect of dispatching themselves or other event sources, including idle
 * sources. Re-checking ensures all the incoming events have been fully drained
 * before wl_event_loop_dispatch() returns.
 *
 * \memberof wl_event_source
 */
WL_EXPORT void
wl_event_source_check(struct wl_event_source *source)
{
	wl_list_insert(source->loop->check_list.prev, &source->link);
}

/** Remove an event source from its event loop
 *
 * \param source The event source to be removed.
 * \return Zero.
 *
 * The event source is removed from the event loop it was created for,
 * and is effectively destroyed. This invalidates \c source .
 * The dispatch function of the source will no longer be called through this
 * source.
 *
 * \memberof wl_event_source
 */
WL_EXPORT int
wl_event_source_remove(struct wl_event_source *source)
{
	struct wl_event_loop *loop = source->loop;
	int ret = 0, saved_errno = 0;

	/*
	 * Since BSD doesn't treat all event sources as FDs, we need to
	 * differentiate by source interface.
	 */
	if (source->interface == &fd_source_interface && source->fd >= 0) {
		struct kevent ev[2];
		int _ret[2], _saved_errno[2];

		/*
		 * We haven't stored state about the mask used when adding the
		 * source, so we have to try and remove both READ and WRITE
		 * filters. One may fail, which is OK. Removal of the source has
		 * only failed if _both_ kevent() calls fail. We have to do two
		 * kevent() calls so that we can get independent return values
		 * for the two kevents.
		 */
		EV_SET(&ev[0], source->fd, EVFILT_READ, EV_DELETE, 0, 0,
		      source);
		EV_SET(&ev[1], source->fd, EVFILT_WRITE, EV_DELETE, 0, 0,
		      source);

		_ret[0] = kevent(loop->event_fd, &ev[0], 1, NULL, 0, NULL);
		_saved_errno[0] = errno;
		_ret[1] = kevent(loop->event_fd, &ev[1], 1, NULL, 0, NULL);
		_saved_errno[1] = errno;

		if (_ret[0] >= _ret[1]) {
			ret = _ret[0];
			saved_errno = _saved_errno[0];
		} else {
			ret = _ret[1];
			saved_errno = _saved_errno[1];
		}

		close(source->fd);
	} else if (source->interface == &timer_source_interface) {
		struct kevent ev;

		EV_SET(&ev, source->fd, EVFILT_TIMER, EV_DELETE, 0, 0, source);
		ret = kevent(loop->event_fd, &ev, 1, NULL, 0, NULL);
		saved_errno = errno;
	} else if (source->interface == &signal_source_interface) {
		struct kevent ev;
		int signal_number;
		struct wl_event_source_signal *_source;

		/* Only one kevent() call needed. */
		_source = (struct wl_event_source_signal *) source;
		signal_number = _source->signal_number;

		EV_SET(&ev, signal_number, EVFILT_SIGNAL, EV_DELETE, 0, 0,
		      source);
		ret = kevent(loop->event_fd, &ev, 1, NULL, 0, NULL);
		saved_errno = errno;
	}

	/* Handle any errors from kevent() calls. */
	if (ret < 0) {
		fprintf(stderr,
		        "error removing event (%i) from kqueue: %s\n",
		        source->fd, strerror(saved_errno));
	}

	/* Tidy up the source. */
	source->fd = -1;

	wl_list_remove(&source->link);
	wl_list_insert(&loop->destroy_list, &source->link);

	return 0;
}

static void
wl_event_loop_process_destroy_list(struct wl_event_loop *loop)
{
	struct wl_event_source *source, *next;

	wl_list_for_each_safe(source, next, &loop->destroy_list, link)
		free(source);

	wl_list_init(&loop->destroy_list);
}

/** Create a new event loop context
 *
 * \return A new event loop context object.
 *
 * This creates a new event loop context. Initially this context is empty.
 * Event sources need to be explicitly added to it.
 *
 * Normally the event loop is run by calling wl_event_loop_dispatch() in
 * a loop until the program terminates. Alternatively, an event loop can be
 * embedded in another event loop by its file descriptor, see
 * wl_event_loop_get_fd().
 *
 * \memberof wl_event_loop
 */
WL_EXPORT struct wl_event_loop *
wl_event_loop_create(void)
{
	struct wl_event_loop *loop;

	loop = malloc(sizeof *loop);
	if (loop == NULL)
		return NULL;

	loop->event_fd = wl_os_queue_create_cloexec();
	if (loop->event_fd < 0) {
		free(loop);
		return NULL;
	}
	wl_list_init(&loop->check_list);
	wl_list_init(&loop->idle_list);
	wl_list_init(&loop->destroy_list);

	wl_signal_init(&loop->destroy_signal);

	return loop;
}

/** Destroy an event loop context
 *
 * \param loop The event loop to be destroyed.
 *
 * This emits the event loop destroy signal, closes the event loop file
 * descriptor, and frees \c loop.
 *
 * If the event loop has existing sources, those cannot be safely removed
 * afterwards. Therefore one must call wl_event_source_remove() on all
 * event sources before destroying the event loop context.
 *
 * \memberof wl_event_loop
 */
WL_EXPORT void
wl_event_loop_destroy(struct wl_event_loop *loop)
{
	wl_signal_emit(&loop->destroy_signal, loop);

	wl_event_loop_process_destroy_list(loop);
	close(loop->event_fd);
	free(loop);
}

static bool
post_dispatch_check(struct wl_event_loop *loop)
{
	struct kevent ev;
	struct wl_event_source *source, *next;
	bool needs_recheck = false;

	wl_list_for_each_safe(source, next, &loop->check_list, link) {
		int dispatch_result;

		dispatch_result = source->interface->dispatch(source, &ev);
		if (dispatch_result < 0) {
			wl_log("Source dispatch function returned negative value!");
			wl_log("This would previously accidentally suppress a follow-up dispatch");
		}
		needs_recheck |= dispatch_result != 0;
	}

	return needs_recheck;
}

/** Dispatch the idle sources
 *
 * \param loop The event loop whose idle sources are dispatched.
 *
 * \sa wl_event_loop_add_idle()
 * \memberof wl_event_loop
 */
WL_EXPORT void
wl_event_loop_dispatch_idle(struct wl_event_loop *loop)
{
	struct wl_event_source_idle *source;

	while (!wl_list_empty(&loop->idle_list)) {
		source = container_of(loop->idle_list.next,
				      struct wl_event_source_idle, base.link);
		source->func(source->base.data);
		wl_event_source_remove(&source->base);
	}
}

/** Wait for events and dispatch them
 *
 * \param loop The event loop whose sources to wait for.
 * \param timeout The polling timeout in milliseconds.
 * \return 0 for success, -1 for polling error.
 *
 * All the associated event sources are polled. This function blocks until
 * any event source delivers an event (idle sources excluded), or the timeout
 * expires. A timeout of -1 disables the timeout, causing the function to block
 * indefinitely. A timeout of zero causes the poll to always return immediately.
 *
 * All idle sources are dispatched before blocking. An idle source is destroyed
 * when it is dispatched. After blocking, all other ready sources are
 * dispatched. Then, idle sources are dispatched again, in case the dispatched
 * events created idle sources. Finally, all sources marked with
 * wl_event_source_check() are dispatched in a loop until their dispatch
 * functions all return zero.
 *
 * \memberof wl_event_loop
 */
WL_EXPORT int
wl_event_loop_dispatch(struct wl_event_loop *loop, int timeout)
{
	struct kevent ev[64];
	struct wl_event_source *source;
	int i, count;
	struct timespec timeout_spec;

	wl_event_loop_dispatch_idle(loop);

	/* timeout is provided in milliseconds */
	timeout_spec.tv_sec = timeout / 1000;
	timeout_spec.tv_nsec = (timeout % 1000) * 1000000;

	count = kevent(loop->event_fd, NULL, 0, ev, ARRAY_LENGTH(ev),
	               (timeout != -1) ? &timeout_spec : NULL);
	if (count < 0)
		return -1;

	for (i = 0; i < count; i++) {
		source = ev[i].udata;
		if (source->fd != -1) {
		       source->interface->dispatch(source, &ev[i]);
		}
	}

	wl_event_loop_process_destroy_list(loop);

	wl_event_loop_dispatch_idle(loop);

	while (post_dispatch_check(loop));

	return 0;
}

/** Get the event loop file descriptor
 *
 * \param loop The event loop context.
 * \return The aggregate file descriptor.
 *
 * This function returns the aggregate file descriptor, that represents all
 * the event sources (idle sources excluded) associated with the given event
 * loop context. When any event source makes an event available, it will be
 * reflected in the aggregate file descriptor.
 *
 * When the aggregate file descriptor delivers an event, one can call
 * wl_event_loop_dispatch() on the event loop context to dispatch all the
 * available events.
 *
 * \memberof wl_event_loop
 */
WL_EXPORT int
wl_event_loop_get_fd(struct wl_event_loop *loop)
{
	return loop->event_fd;
}

/** Register a destroy listener for an event loop context
 *
 * \param loop The event loop context whose destruction to listen for.
 * \param listener The listener with the callback to be called.
 *
 * \sa wl_listener
 * \memberof wl_event_loop
 */
WL_EXPORT void
wl_event_loop_add_destroy_listener(struct wl_event_loop *loop,
				   struct wl_listener *listener)
{
	wl_signal_add(&loop->destroy_signal, listener);
}

/** Get the listener struct for the specified callback
 *
 * \param loop The event loop context to inspect.
 * \param notify The destroy callback to find.
 * \return The wl_listener registered to the event loop context with
 * the given callback pointer.
 *
 * \memberof wl_event_loop
 */
WL_EXPORT struct wl_listener *
wl_event_loop_get_destroy_listener(struct wl_event_loop *loop,
				   wl_notify_func_t notify)
{
	return wl_signal_get(&loop->destroy_signal, notify);
}
#endif
