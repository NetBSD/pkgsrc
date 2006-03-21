/* $NetBSD: pthread-stubs.c,v 1.1.1.1 2006/03/21 19:23:08 drochner Exp $ */

#include <sys/cdefs.h>

int __pthstub_mutex_noop(void);

__weak_alias(pthread_mutex_init,__pthstub_noop)
__weak_alias(pthread_mutex_lock,__pthstub_noop)
__weak_alias(pthread_mutex_trylock,__pthstub_noop)
__weak_alias(pthread_mutex_unlock,__pthstub_noop)
__weak_alias(pthread_mutex_destroy,__pthstub_noop)
__weak_alias(pthread_key_create,__pthstub_noop)
__weak_alias(pthread_self,__pthstub_noop)

int
__pthstub_noop()
{

	return (0);
}

__weak_alias(pthread_setspecific,__pthstub_setspecific)
__weak_alias(pthread_getspecific,__pthstub_getspecific)
static void *__pthstub_localdata;

int
__pthstub_setspecific(int k, void *v)
{

	__pthstub_localdata = v;
	return (0);
}

void *
__pthstub_getspecific()
{

	return (__pthstub_localdata);
}

__weak_alias(pthread_once,__pthstub_once)
static int __once_done;

int
__pthstub_once(void *oc, void (*f)(void))
{

	if (!__once_done) {
		(*f)();
		__once_done = 1;
	}
	return (0);
}
