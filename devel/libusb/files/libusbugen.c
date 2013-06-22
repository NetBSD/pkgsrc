/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright (c) 2004, 2011, Oracle and/or its affiliates. All rights reserved.
 */

/*
 * This library can either be used stand-alone or as plugin
 * to the libusb wrapper library.
 * The libusb API 0.1.0.10 has been implemented using all original code
 * which was not derived from opensource.
 *
 * XXX issues:
 *	- timeout thru signal
 *	- usb_interrupt/bulk_write/read should have common code
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>
#include <dirent.h>
#include <stdarg.h>
#include <strings.h>
#include <sys/stat.h>
#include <regex.h>

#include <sys/usb/clients/ugen/usb_ugen.h>
#include "usb.h"
#include "libusbugen_impl.h"

/* global variables */
usb_bus_t *usb_busses = NULL;
const char *libusb_version = "1.1";

/* error handling */
static	char usb_error_string[1024];
static	int usb_error_errno;
static	usb_error_type_t usb_error_type = USB_ERROR_TYPE_NONE;

/* debugging */
static	int libusb_debug = DEBUG_NONE;

/* api binding */
static	int libusb_api = API_RELAXED;

/* internal function prototypes */
static	void usb_error_str(int x, char *format, ...);
static	int usb_error(int x);
static	void usb_dprintf(int level, char *format, ...);
static	void usb_dump_data(char *data, int size);

static	int usb_open_ep0(usb_dev_handle_impl_t *hdl);
static	void usb_close_ep0(usb_dev_handle_impl_t *hdl);
static	int usb_check_access(usb_dev_handle *dev);
static	int usb_search_dev_usb(usb_device_t **new_devices);
static	int usb_do_io(int fd, int stat_fd, char *data, size_t size, int flag);
static	int usb_send_msg(int fd, int stat_fd, int requesttype, int request,
	int value, int index, char *data, int size);
static	int usb_check_device_and_status_open(usb_dev_handle *dev,
	int ep, int ep_type, int mode);
static	int usb_get_status(int fd);
static	void usb_set_ep_iface_alts(usb_dev_handle_impl_t *hdl,
	usb_dev_handle_info_t *info, int index, int interface, int alternate);

static	int usb_setup_all_configs(usb_dev_handle_impl_t *hdl);
static	void usb_free_all_configs(usb_device_t *device);
static	int usb_parse_config(usb_dev_handle_impl_t *hdl, uint_t index);
static	void usb_free_config(usb_device_t *device, uint_t index);
static	int usb_parse_interface(usb_dev_handle_impl_t *hdl, uint_t index,
	uint_t iface, char *cloud);
static	void usb_free_interface(usb_device_t *device, uint_t index,
	uint_t iface);
static	int usb_parse_alternate(usb_dev_handle_impl_t *hdl, uint_t index,
	uint_t iface, uint_t alt, char *cloud);
static	void usb_free_alternate(usb_device_t *device, uint_t index,
	uint_t iface, uint_t alt);
static	int usb_parse_endpoint(usb_dev_handle_impl_t *hdl, int index,
	int iface, int alt, int ep, char *cloud);
static	void usb_find_extra(uchar_t *buf, size_t buflen,
	unsigned char **extra, int *extralen);

static	void usb_close_all_eps(usb_dev_handle_impl_t *hdl);
static	void usb_add_device(usb_device_t **list, usb_device_t *dev);
static	void usb_remove_device(usb_device_t **list, usb_device_t *dev);
static	int usb_check_device_in_list(usb_device_t *list, usb_device_t *dev);

static	void usb_free_dev(usb_device_t *dev);
static	void usb_free_bus(usb_bus_t *bus);

static size_t usb_parse_dev_descr(uchar_t *buf, size_t buflen,
	struct usb_device_descriptor *ret_descr, size_t	ret_buf_len);
static size_t usb_parse_cfg_descr(uchar_t *buf, size_t buflen,
	usb_cfg_descr_t	*ret_descr, size_t ret_buf_len,
	unsigned char **extra, int *extralen);
static size_t usb_parse_if_descr(uchar_t *buf, size_t buflen,
	uint_t if_number, uint_t alt_if_setting,
	usb_if_descr_t *ret_descr, size_t ret_buf_len,
	unsigned char **extra, int *extralen);
static size_t usb_parse_ep_descr(uchar_t *buf, size_t buflen,
	uint_t if_number, uint_t alt_if_setting, uint_t ep_index,
	usb_ep_descr_t *ret_descr, size_t ret_buf_len,
	unsigned char **extra, int *extralen);
static uchar_t usb_ep_index(uint8_t ep_addr);

/*
 * libusb_init:
 *
 * Returns: 0 or ENOSUP if we cannot support any bus
 */
int
libusb_init(void)
{
	return (0);
}

/*
 * libusb_fini:
 *
 * Returns: always returns 0
 */
int
libusb_fini(void)
{
	return (0);
}

/*
 * Entry points:
 *
 * usb_set_debug:
 *	sets debug level for tracing
 */
void
usb_set_debug(int level)
{
	if (getenv("SUN_LIBUSBUGEN_DEBUG")) {

		level =	atoi(getenv("SUN_LIBUSBUGEN_DEBUG"));

	} else if (getenv("SUN_LIBUSB_DEBUG")) {

		level = atoi(getenv("SUN_LIBUSB_DEBUG"));
	}

	if (level < 0)
		return;

	libusb_debug = level;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_set_debug(): "
	    "Setting debugging level to %d (%s)\n",
	    level, level ? "on" : "off");
}

/*
 * usb_init:
 *	not much to initialize. just set debug level
 */
void
usb_init(void)
{
	if (getenv("LIBUSB_API_STRICT")) {
		libusb_api = API_STRICT;
	}

	usb_set_debug(libusb_debug);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_init(): "
	    "libusb version=%s\n", libusb_version);
}

/*
 * usb_get_busses:
 * Returns: usb_busses pointer
 */
usb_bus_t *
usb_get_busses(void)
{
	return (usb_busses);
}

/*
 * usb_find_busses:
 *	finds all busses in the system. On solaris we have
 *	only one flat name space, /dev/usb
 *
 * Returns: change in number of busses or negative errno
 */
int
usb_find_busses(void)
{
	usb_bus_t *bus;

	/* we only have one name space for all USB busses */
	if (usb_busses == NULL) {
		/* never freed */
		if ((bus = calloc(sizeof (*bus), 1)) == NULL) {

			return (usb_error(ENOMEM));
		}

		(void) strncpy(bus->dirname, "/dev/usb",
		    sizeof (bus->dirname));

		usb_dprintf(DEBUG_FUNCTIONS, "usb_find_busses(): "
		    "found %s\n", bus->dirname);

		usb_busses = bus;

		return (1);
	}

	return (0);
}

/*
 * usb_find_devices:
 *	finds all devices that have appeared and removes devices
 *	from the list that are no longer there
 *
 * Returns: change in number of devices or a negative errno
 */
int
usb_find_devices(void)
{
	int i, rval, found;
	int changes = 0;
	usb_device_t *new_devices;
	usb_device_t *dev, *next_dev, *new, *next_new;

	new_devices = NULL;

	rval = usb_search_dev_usb(&new_devices);
	if (rval != 0) {

		return (usb_error(rval));
	}

	/* is any of devices on the new list also on the old list? */
	for (dev = usb_busses->devices; dev != NULL; dev = next_dev) {
		next_dev = dev->next;
		found = 0;
		for (new = new_devices; new != NULL; new = next_new) {
			next_new = new->next;
			if (strncmp(dev->filename, new->filename,
			    sizeof (dev->filename)) == 0) {
				usb_remove_device(&new_devices, new);
				usb_free_dev(new);
				found++;
				break;
			}
		}

		/* the device must have been hot removed */
		if (!found) {
			usb_remove_device(&usb_busses->devices, dev);
			usb_free_dev(dev);
		}
	}

	/* add all new_devices to the old_devices list */
	usb_dprintf(DEBUG_DETAILED, "moving new to old\n");

	for (new = new_devices; new != NULL; new = next_new) {
		next_new = new->next;
		usb_remove_device(&new_devices, new);
		usb_add_device(&usb_busses->devices, new);
		(void) usb_close(usb_open(new));
		changes++;
	}

	usb_dprintf(DEBUG_DETAILED, "usb_devices list:\n");
	for (i = 0, dev = usb_busses->devices; dev != NULL;
	    i++, dev = next_dev) {
		next_dev = dev->next;
		usb_dprintf(DEBUG_DETAILED, "%d: %s\n", i, dev->filename);
	}

	return (changes);
}

/*
 * usb_device:
 *	 included because sane uses this
 * Returns: usb_device structure associated with handle
 */
struct usb_device *
usb_device(usb_dev_handle *dev)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;

	return ((hdl != NULL) ? hdl->device : NULL);
}

/*
 * usb_open:
 *	opens the device for access
 *
 * Returns: a usb device handle or NULL
 */
usb_dev_handle *
usb_open(usb_device_t *dev)
{
	usb_dev_handle_impl_t	*hdl;
	usb_dev_handle_info_t	*info;
	int			i, rval;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_open():\n");

	if (usb_check_device_in_list(usb_busses->devices,
	    dev) == 0) {
		usb_dprintf(DEBUG_ERRORS, "usb_open(): "
		    "illegal usb_device pointer\n");

		return (NULL);
	}

	/* create a handle and info structure */
	if ((hdl = calloc(sizeof (*hdl), 1)) == NULL) {

		return (NULL);
	}
	hdl->device = dev;
	if ((info = calloc(sizeof (*info), 1)) == NULL) {
		free(hdl);

		return (NULL);
	}

	hdl->info = info;

	/* set all file descriptors to "closed" */
	for (i = 0; i < USB_MAXENDPOINTS; i++) {
		hdl->info->ep_fd[i] = -1;
		hdl->info->ep_status_fd[i] = -1;
		if (i > 0) {
			hdl->info->ep_interface[i] = -1;
		}
	}

	/* open default control ep and keep it open */
	if ((rval = usb_open_ep0(hdl)) != 0) {
		usb_dprintf(DEBUG_ERRORS, "usb_open_ep0 failed: %d\n", rval);
		free(info);
		free(hdl);

		return (NULL);
	}

	/*
	 * setup config info: trees of configs, interfaces, alternates
	 * and endpoints structures
	 */
	if (usb_setup_all_configs(hdl) != 0) {
		usb_free_all_configs(hdl->device);
		usb_close_ep0(hdl);
		free(info);
		free(hdl);

		return (NULL);
	}

	/* set when the app claims an interface */
	info->configuration_value =
	    info->claimed_interface = info->alternate = -1;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_open(): hdl=0x%x\n", (int)hdl);

	return ((usb_dev_handle *)hdl);
}

/*
 * usb_close:
 *	closes the device and free resources
 *
 * Returns: 0
 */
int
usb_close(usb_dev_handle *dev)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_close(): hdl=0x%x\n", hdl);

	if (hdl) {
		info = hdl->info;

		usb_dprintf(DEBUG_DETAILED,
		    "usb_close(): claimed %d\n",
		    info->claimed_interface);

		if (info->claimed_interface != -1) {
			(void) usb_release_interface(dev,
			    info->claimed_interface);
		}
		usb_close_all_eps(hdl);
		usb_close_ep0(hdl);

		free(info);
		free(hdl);

		return (0);
	}

	return (usb_error(EINVAL));
}

/*
 * usb_control_msg:
 *	sends a control message
 *
 * Returns: actual number of data bytes transferred or
 *	    a negative errno
 */
/*ARGSUSED*/
int
usb_control_msg(usb_dev_handle *dev, int requesttype, int request,
    int value, int index, char *data, int size, int timeout)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	int additional;
	int rval;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_control_msg():\n");

	if ((hdl == NULL) || (size < 0)) {

		return (usb_error(EINVAL));
	}
	info = hdl->info;

	/*
	 * no need to do validation since ep0 is always open and
	 * we do not need to claim an interface first
	 *
	 * usb_send_msg returns #bytes xferred or negative errno
	 */
	rval = usb_send_msg(info->ep_fd[0], info->ep_status_fd[0],
	    requesttype, request, value, index, data, size);

	/* less than setup bytes transferred? */
	if (rval < 8) {
		usb_error_str(errno,
		    "error sending control message: %d", rval);

		return ((rval >= 0) ?
		    usb_error(EIO) : usb_error(-rval));
	}

	rval -= 8; /* substract setup length */

	/* for IN requests, now transfer the remaining bytes */
	if ((size) && (requesttype & USB_DEV_REQ_DEV_TO_HOST)) {
		additional = usb_do_io(info->ep_fd[0],
		    info->ep_status_fd[0], data, size, READ);
	} else {
		additional = rval;
	}

	usb_dprintf(DEBUG_FUNCTIONS,
	    "usb_control_msg(): additional 0x%x bytes\n", additional);

	return (additional);
}

/*
 * usb_bulk_write:
 *	writes to a bulk endpoint
 *
 * Returns: actual number of data bytes transferred or negative errno
 */
/* ARGSUSED */
int
usb_bulk_write(usb_dev_handle *dev, int ep, char *data, int size,
    int timeout)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	int sent, rval;
	int ep_index = usb_ep_index(ep);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_bulk_write(): ep=0x%x\n", ep);

	if ((hdl == NULL) || (data == NULL) || (size <= 0)) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_bulk_write(): NULL handle or data\n");

		return (usb_error(EINVAL));
	}
	info = hdl->info;

	/* do some validation first */
	if ((rval = usb_check_device_and_status_open(dev, ep,
	    USB_ENDPOINT_TYPE_BULK, O_WRONLY)) != 0) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_check_device_and_status_open() failed\n");

		return (usb_error(rval));
	}

	/* now write out the bytes */
	sent = usb_do_io(info->ep_fd[ep_index], info->ep_status_fd[ep_index],
	    data, size, WRITE);

	return (sent);
}

/*
 * usb_bulk_read:
 *	reads from a bulk endpoint
 *
 * Returns: actual number of data bytes transferred or negative errno
 */
/* ARGSUSED */
int
usb_bulk_read(usb_dev_handle *dev, int ep, char *data, int size,
    int timeout)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	int ep_index, received, rval;

	ep |= USB_ENDPOINT_IN;
	ep_index = usb_ep_index(ep);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_bulk_read(): ep=0x%x\n", ep);

	if ((hdl == NULL) || (data == NULL) || (size <= 0)) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_bulk_read(): NULL handle or data\n");

		return (usb_error(EINVAL));
	}
	info = hdl->info;

	/* do some validation first */
	if ((rval = usb_check_device_and_status_open(dev, ep,
	    USB_ENDPOINT_TYPE_BULK, O_RDONLY)) != 0) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_check_device_and_status_open() failed\n");

		return (usb_error(rval));
	}

	/* now read in the bytes */
	received = usb_do_io(info->ep_fd[ep_index],
	    info->ep_status_fd[ep_index],
	    data, size, READ);

	return (received);
}

/*
 * usb_interrupt_write:
 *	writes data to an interrupt endpoint
 *
 * Returns: actual number of data bytes transferred or negative errno
 */
/* ARGSUSED */
int
usb_interrupt_write(usb_dev_handle *dev, int ep, char *data, int size,
    int timeout)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	int sent, rval;
	int ep_index = usb_ep_index(ep);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_interrupt_write(): ep=0x%x\n", ep);

	if ((hdl == NULL) || (data == NULL) || (size <= 0)) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_interrupt_write(): NULL handle or data\n");

		return (usb_error(EINVAL));
	}
	info = hdl->info;

	/* do some validation first */
	if ((rval = usb_check_device_and_status_open(dev, ep,
	    USB_ENDPOINT_TYPE_INTERRUPT, O_WRONLY)) != 0) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_check_device_and_status_open() failed\n");

		return (usb_error(rval));
	}

	/* now transfer the bytes */
	sent = usb_do_io(info->ep_fd[ep_index],
	    info->ep_status_fd[ep_index],
	    data, size, WRITE);

	return (sent);
}

/*
 * usb_interrupt_read:
 *	reads data from an interrupt endpoint
 *
 * Returns: actual number of data bytes transferred or negative errno
 */
/* ARGSUSED */
int
usb_interrupt_read(usb_dev_handle *dev, int ep, char *data, int size,
    int timeout)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	int ep_index, received, rval;

	ep |= USB_ENDPOINT_IN;
	ep_index = usb_ep_index(ep);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_interrrupt_read(): ep=0x%x\n", ep);

	if ((hdl == NULL) || (data == NULL) || (size <= 0)) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_interrupt_read(): NULL handle or data\n");

		return (usb_error(EINVAL));
	}
	info = hdl->info;

	/* do some validation first */
	if ((rval = usb_check_device_and_status_open(dev, ep,
	    USB_ENDPOINT_TYPE_INTERRUPT, O_RDONLY)) != 0) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_check_device_and_status_open() failed\n");

		return (usb_error(rval));
	}

	/* now transfer the bytes */
	received = usb_do_io(info->ep_fd[ep_index],
	    info->ep_status_fd[ep_index],
	    data, size, READ);

	/* close the endpoint so we stop polling the endpoint now */
	(void) close(info->ep_fd[ep_index]);
	(void) close(info->ep_status_fd[ep_index]);
	info->ep_fd[ep_index] = -1;
	info->ep_status_fd[ep_index] = -1;

	return (received);
}

/*
 * usb_get_string:
 *	gets a raw unicode string
 *
 * Returns: number of bytes transferred or negative errno
 */
int
usb_get_string(usb_dev_handle *dev, int index, int langid, char *buf,
    size_t buflen)
{
	/*
	 * We can't use usb_get_descriptor() because it's lacking the index
	 * parameter. This will be fixed in libusb 1.0
	 */
	usb_dprintf(DEBUG_FUNCTIONS,
	    "usb_get_string(): index=%d langid=0x%x len=%d\n",
	    index, langid, buflen);

	if ((dev == NULL) || (buf == NULL) || (buflen == 0)) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_get_string(): NULL handle or data\n");

		return (usb_error(EINVAL));
	}


	return (usb_control_msg(dev, USB_DEV_REQ_DEV_TO_HOST,
	    USB_REQ_GET_DESCRIPTOR, (USB_DT_STRING << 8) + index,
	    langid, buf, (int)buflen, 1000));
}

/*
 * usb_get_string_simple:
 *	gets a cooked ascii string
 *
 * Returns:  number of bytes transferred or negative errno
 */
int
usb_get_string_simple(usb_dev_handle *dev, int index, char *buf,
    size_t buflen)
{
	char tbuf[256];
	int ret, langid, si, di;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_get_string_simple(): index=%d\n",
	    index);

	if ((dev == NULL) || (buf == NULL) || (buflen == 0)) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_get_string_simple(): NULL handle or data\n");

		return (usb_error(EINVAL));
	}

	(void) memset(buf, 0, buflen);

	/*
	 * Asking for the zero'th index is special - it returns a string
	 * descriptor that contains all the language IDs supported by the
	 * device. Typically there aren't many - often only one. The
	 * language IDs are 16 bit numbers, and they start at the third byte
	 * in the descriptor. See USB 2.0 specification, section 9.6.7, for
	 * more information on this.
	 */
	ret = usb_get_string(dev, index, 0, tbuf, sizeof (tbuf));
	usb_dprintf(DEBUG_DETAILED, "usb_get_string() returned %d\n", ret);

	if (ret < 4) {
		langid = 0x409;
	} else {
		langid = tbuf[2] | (tbuf[3] << 8);
	}

	usb_dprintf(DEBUG_DETAILED, "using langid=0x%x\n", langid);

	ret = usb_get_string(dev, index, langid, tbuf, sizeof (tbuf));
	if (ret < 0) {

		return (ret);
	}
	if (tbuf[1] != USB_DT_STRING) {

		return (-EIO);
	}
	if (tbuf[0] > ret) {

		return (-EFBIG);
	}

	for (di = 0, si = 2; si < tbuf[0]; si += 2) {
		if (di >= ((int)buflen - 1)) {
			break;
		}

		if (tbuf[si + 1]) {  /* high byte */
			buf[di++] = '?';
		} else {
			buf[di++] = tbuf[si];
		}
	}

	buf[di] = 0;

	return (di);
}

/*
 * usb_get_descriptor_by_endpoint:
 * usb_get_descriptor:
 *	get a descriptor. by_endpoint does not appear to make
 *	much sense.
 *
 * Returns: number of bytes transferred or negative errno
 */
int
usb_get_descriptor_by_endpoint(usb_dev_handle *udev, int ep,
    uchar_t type, uchar_t index, void *buf, int size)
{
	if ((udev == NULL) || (buf == NULL) || (size <= 0)) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_get_descriptor_by_endpoint(): "
		    "NULL handle or data\n");

		return (usb_error(EINVAL));
	}

	(void) memset(buf, 0, size);

	return (usb_control_msg(udev,
	    ep | USB_ENDPOINT_IN, USB_REQ_GET_DESCRIPTOR,
	    (type << 8) + index, 0, buf, size, 1000));
}

int
usb_get_descriptor(usb_dev_handle *udev, uchar_t type,
    uchar_t index, void *buf, int size)
{
	if ((udev == NULL) || (buf == NULL) || (size <= 0)) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_get_string_simple(): NULL handle or data\n");

		return (usb_error(EINVAL));
	}

	(void) memset(buf, 0, size);

	return (usb_control_msg(udev,
	    USB_ENDPOINT_IN, USB_REQ_GET_DESCRIPTOR,
	    (type << 8) + index, 0, buf, size, 1000));
}

/*
 * usb_set_altinterface:
 *	switches to the alternate interface for the device
 *	Note that ugen does not really need this. It does implicit
 *	cfg and alt switches when the endpoint is opened.
 *
 * Returns: 0 or negative errno
 */
/* ARGSUSED */
int
usb_set_altinterface(usb_dev_handle *dev, int alt)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	usb_device_specific_t *dev_specific;
	int index, iface, err;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_set_altinterface(): "
	    "hdl=0x%x alt=%d\n", hdl, alt);

	if (hdl == NULL) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_set_altinterface(): NULL handle\n");

		return (usb_error(EINVAL));
	}

	info = hdl->info;

	if (libusb_api == API_RELAXED) {
		if (info->claimed_interface == -1) {
			/*
			 * usb_claim_interface() should always be called
			 * prior usb_set_altinterface(), but some apps
			 * do not do this, hence we call it here assuming
			 * the default interface.
			 */
			if ((err = usb_claim_interface(dev, 0))) {

				return (err);
			}
		}
	}

	iface = info->claimed_interface;
	dev_specific = (usb_device_specific_t *)(hdl->device->dev);

	usb_dprintf(DEBUG_DETAILED, "claimed=%d, cfgvalue=%d, hdl=0x%x\n",
	    info->claimed_interface, info->configuration_value,
	    dev_specific->claimed_interfaces[iface], hdl);

	if ((info->claimed_interface == -1) ||
	    (info->configuration_value == -1) ||
	    (hdl != dev_specific->claimed_interfaces[iface])) {

		return (usb_error(EACCES));
	}

	usb_close_all_eps(hdl);

	/* find the conf index */
	for (index = 0; index < hdl->device->descriptor.bNumConfigurations;
	    index++) {
		if (info->configuration_value ==
		    hdl->device->config[index].bConfigurationValue) {
			break;
		}
	}

	usb_dprintf(DEBUG_DETAILED,
	    "cfg value=%d index=%d, iface=%d, alt=%d #alts=%d\n",
	    info->configuration_value, index, iface, alt,
	    hdl->device->config[index].interface[iface].num_altsetting);

	if ((alt < 0) || (alt >= hdl->device->
	    config[index].interface[iface].num_altsetting)) {

		return (usb_error(EINVAL));
	}

	info->alternate = alt;

	usb_set_ep_iface_alts(hdl, info, index, iface, alt);

	return (0);
}

/*
 * usb_set_configuration:
 *	sets the configuration for the device.
 *	ugen implicitly switches configuration and rejects
 *	set configuration requests
 *
 * Returns: 0
 */
/* ARGSUSED */
int
usb_set_configuration(usb_dev_handle *dev, int configuration)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	int index, i;

	usb_dprintf(DEBUG_FUNCTIONS,
	    "usb_set_configuration(): config = %d\n", configuration);

	if (hdl == NULL) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_set_configuration(): NULL handle\n");

		return (usb_error(EINVAL));
	}
	info = hdl->info;

	/* find the conf index */
	for (index = 0; index < hdl->device->descriptor.bNumConfigurations;
	    index++) {
		if (configuration ==
		    hdl->device->config[index].bConfigurationValue) {
			break;
		}
	}

	if (index >= hdl->device->descriptor.bNumConfigurations) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_set_configuration(): invalid\n");

		return (usb_error(EINVAL));
	}

	usb_close_all_eps(hdl);
	info->configuration_value = configuration;
	info->configuration_index = index;

	/* reset ep arrays */
	for (i = 0; i < USB_MAXENDPOINTS; i++) {
		info->ep_interface[i] = -1;
	}
	if (info->claimed_interface != -1) {
		(void) usb_release_interface(dev, info->claimed_interface);
	}

	return (0);
}

/*
 * usb_clear_halt:
 *	clears a halted endpoint
 *	ugen has auto clearing but we send the request anyways
 *
 * Returns: 0 or negative errno
 */
/* ARGSUSED */
int
usb_clear_halt(usb_dev_handle *dev, unsigned int ep)
{
	int rval;
	int index = usb_ep_index(ep);
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_clear_halt(): ep=0x%x\n", ep);

	if (dev == NULL) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_clear_halt(): NULL handle\n");

		return (usb_error(EINVAL));
	}
	info = hdl->info;

	usb_dprintf(DEBUG_DETAILED, "index=0x%x, ep_intf=%d\n",
	    index, info->ep_interface[index]);

	if (info->ep_interface[index] == -1) {

		return (usb_error(EINVAL));
	}


	/* only check for ep > 0 */
	if (ep && ((rval = usb_check_access(dev) != 0))) {

		return (usb_error(rval));
	}

	rval = usb_control_msg(dev,
	    USB_DEV_REQ_HOST_TO_DEV | USB_RECIP_ENDPOINT,
	    USB_REQ_CLEAR_FEATURE, 0, ep, NULL, 0, 0);

	if (rval < 0) {
		usb_error_str(errno, "could not clear feature on ep=0x%x", ep);
	}

	return (rval);
}

/*
 * usb_claim_interface:
 *	ugen does not have a claim interface concept but all endpoints
 *	are opened exclusively. This provides some exclusion. However,
 *	the interrupt IN endpoint is closed after the read
 *
 * Returns: 0 or negative errno
 */
int
usb_claim_interface(usb_dev_handle *dev, int interface)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	usb_device_specific_t *dev_specific;
	int index;

	if (hdl == NULL) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_claim_interface(): NULL handle\n");

		return (usb_error(EINVAL));
	}
	info = hdl->info;
	dev_specific = (usb_device_specific_t *)(hdl->device->dev);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_claim_interface(): hdl=0x%x: "
	    "interface = %d\n", hdl, interface);

	if (info->configuration_value == -1) {
		index = 0;
	} else {
		/* find the conf index */
		for (index = 0;
		    index < hdl->device->descriptor.bNumConfigurations;
		    index++) {
			if (info->configuration_value ==
			    hdl->device->config[index].bConfigurationValue) {
				break;
			}
		}
	}
	info->configuration_value =
	    hdl->device->config[index].bConfigurationValue;
	info->configuration_index = index;

	usb_dprintf(DEBUG_DETAILED, "configuration_value=%d, index=%d\n",
	    info->configuration_value, index);

	/* is this a valid interface? */
	if ((interface < 0) || (interface > 255) ||
	    (interface >= hdl->device->config[index].bNumInterfaces)) {

		return (usb_error(EINVAL));
	}

	/* already claimed? */
	if (dev_specific->claimed_interfaces[interface] == hdl) {

		return (0);
	}

	if (info->claimed_interface != -1) {

		return (usb_error(EBUSY));
	}

	if (dev_specific->claimed_interfaces[interface] != 0) {

		return (usb_error(EBUSY));
	}

	usb_dprintf(DEBUG_DETAILED, "usb_claim_interface(): hdl=0x%x: "
	    "interface = %d, claimed by this udev=%d, by hdl=0x%x\n",
	    hdl, interface, info->claimed_interface,
	    dev_specific->claimed_interfaces[interface]);


	info->claimed_interface = interface;
	info->alternate = 0;
	dev_specific->claimed_interfaces[interface] = hdl;

	usb_set_ep_iface_alts(hdl, info, index, interface, 0);

	return (0);
}

/*
 * usb_release_interface:
 *	releases the acquired interface
 *
 * Returns: 0 or negative errno
 */
/* ARGSUSED */
int
usb_release_interface(usb_dev_handle *dev, int interface)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info;
	usb_device_specific_t *dev_specific;

	if (hdl == NULL) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_release_interface(): NULL handle\n");

		return (usb_error(EINVAL));
	}

	info = hdl->info;
	dev_specific = (usb_device_specific_t *)(hdl->device->dev);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_release_interface(): hdl=0x%x: "
	    "interface = %d\n", hdl, interface);

	if ((info->claimed_interface == -1) ||
	    (info->claimed_interface != interface)) {

		return (usb_error(EINVAL));
	}

	usb_dprintf(DEBUG_DETAILED, "usb_release_interface(): hdl=0x%x: "
	    "interface = %d, claimed by this udev=%d, by hdl=0x%x\n",
	    hdl, interface, info->claimed_interface,
	    dev_specific->claimed_interfaces[interface]);

	dev_specific->claimed_interfaces[interface] = 0;
	info->claimed_interface = -1;

	return (0);
}

/*
 * usb_resetep
 *	resets the endpoint
 *
 * Returns: 0 or negative errno
 */
int
usb_resetep(usb_dev_handle *dev, unsigned int ep)
{
	usb_dprintf(DEBUG_FUNCTIONS, "usb_resetep(): ep=0x%x\n", ep);

	return (usb_clear_halt(dev, ep));
}

/*
 * usb_reset:
 *	resets the device
 * Returns: -ENOTSUP
 */
/* ARGSUSED */
int
usb_reset(usb_dev_handle * dev)
{
	int rval;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_reset():\n");

	if (dev == NULL) {
		usb_dprintf(DEBUG_ERRORS,
		    "usb_reset(): NULL handle\n");

		return (usb_error(EINVAL));
	}

	if ((rval = usb_check_access(dev)) != 0) {

		return (usb_error(rval));
	}

	return (usb_error(ENOTSUP));
}

/*
 * Helper functions
 *
 * usb_send_msg:
 *	creates setup data and send it
 *
 * Returns: number of bytes transferred or negative errno
 */
static int
usb_send_msg(int fd, int stat_fd, int requesttype, int request, int value,
    int index, char *data, int size)
{
	uint8_t req[8];
	int rval;

	usb_dprintf(DEBUG_DETAILED, "usb_send_msg():\n"
	    "\trequesttype 0x%x\n"
	    "\trequest	   0x%x\n"
	    "\tvalue	   0x%x\n"
	    "\tindex	   0x%x\n"
	    "\tsize	   0x%x\n",
	    requesttype, request, value, index, size);

	req[0] = (uint8_t)requesttype;
	req[1] = (uint8_t)request;
	req[2] = (uint8_t)value;
	req[3] = (uint8_t)(value >> 8);
	req[4] = (uint8_t)index;
	req[5] = (uint8_t)(index >> 8);
	req[6] = (uint8_t)size;
	req[7] = (uint8_t)(size >> 8);

	if (requesttype & USB_DEV_REQ_DEV_TO_HOST) {
		rval = usb_do_io(fd, stat_fd, (char *)&req,
		    sizeof (req), WRITE);
	} else {
		/* append the write data */
		char *buffer;

		if ((buffer = malloc(size + 8)) == NULL) {

			return (usb_error(ENOMEM));
		}

		(void) memcpy(buffer, &req, 8);
		(void) memcpy(&buffer[8], data, size);
		rval = usb_do_io(fd, stat_fd, buffer,
		    (uint_t)sizeof (req) + size, WRITE);
		free(buffer);
	}
	usb_dprintf(DEBUG_FUNCTIONS, "usb_send_msg(): rval=%d\n", rval);

	return (rval);
}

/*
 * usb_do_io:
 *	performs i/o to/from an endpoint and check the
 *	status of the device if error or short xfer.
 *
 * Returns: bytes transferred or negative errno
 */
static int
usb_do_io(int fd, int stat_fd, char *data, size_t size, int flag)
{
	int error;
	ssize_t ret;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_do_io(): size=0x%x flag=%d\n",
	    size, flag);

	if (size == 0) {

		return (0);
	}

	switch (flag) {
	case READ:
		ret = read(fd, data, size);
		usb_dump_data(data, (int)size);
		break;
	case WRITE:
		usb_dump_data(data, (int)size);
		ret = write(fd, data, size);
		break;
	}
	if (ret < 0) {
		int save_errno = errno;

		/* usb_get_status will do a read and overwrite errno */
		error = usb_get_status(stat_fd);
		usb_error_str(save_errno, "error %d doing io: errno=%d",
		    error, save_errno);

		return (-save_errno);
	}

	usb_dprintf(DEBUG_FUNCTIONS, "usb_do_io(): amount=%d\n", ret);

	return ((int)ret);
}

/*
 * usb_check_access:
 *	basically checks if the interface has been claimed
 *
 * Returns: 0 or EACCES/EINVAL
 */
static int
usb_check_access(usb_dev_handle *dev)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info = hdl->info;

	if (hdl == NULL) {

		return (EINVAL);
	}
	info = hdl->info;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_check_access(): "
	    "hdl=0x%x conf=%d claimed=%d alternate=%d\n",
	    (int)hdl, info->configuration_value,
	    info->claimed_interface, info->alternate);

	if ((info->configuration_value == -1) ||
	    (info->claimed_interface == -1) ||
	    (info->alternate == -1)) {

		return (EACCES);
	}

	return (0);
}

/*
 * usb_set_ep_iface_alts:
 *	initialize ep_interface arrays
 */
static void
usb_set_ep_iface_alts(usb_dev_handle_impl_t *hdl, usb_dev_handle_info_t *info,
    int index, int interface, int alternate)
{
	struct usb_interface_descriptor *if_descr;
	struct usb_endpoint_descriptor *ep_descr;
	int i;

	/* reinitialize endpoint arrays */
	for (i = 0; i < USB_MAXENDPOINTS; i++) {
		info->ep_interface[i] = -1;
	}

	/*
	 * for the current config, this interface and alt,
	 * which endpoints are available
	 */
	if_descr = &hdl->device->config[index].interface[interface].
	    altsetting[alternate];

	usb_dprintf(DEBUG_DETAILED, "cfg%d.%d.%d has %d endpoints\n",
	    info->configuration_value, interface, alternate,
	    if_descr->bNumEndpoints);

	for (i = 0; i < if_descr->bNumEndpoints; i++)  {
		ep_descr = &hdl->device->config[index].interface[interface].
		    altsetting[alternate].endpoint[i];
		info->ep_interface[usb_ep_index(
		    ep_descr->bEndpointAddress)] = interface;
	}

	usb_dprintf(DEBUG_DETAILED, "ep_interface:\n");
	for (i = 0; i < USB_MAXENDPOINTS; i++) {
		usb_dprintf(DEBUG_DETAILED, "%d ",
		    info->ep_interface[i]);
	}
	usb_dprintf(DEBUG_DETAILED, "\n");
}

/*
 * usb_check_device_and_status_open:
 *	Make sure that the endpoint and status device for the endpoint
 *	can be opened, or have already been opened.
 *
 * Returns: errno
 */
static int
usb_check_device_and_status_open(usb_dev_handle *dev, int ep, int ep_type,
    int mode)
{
	usb_dev_handle_impl_t *hdl = (usb_dev_handle_impl_t *)dev;
	usb_dev_handle_info_t *info = hdl->info;
	char *filename, *statfilename, cfg_num[16], alt_num[16];
	int fd, fdstat, index, rval;

	index = usb_ep_index(ep);

	usb_dprintf(DEBUG_FUNCTIONS,
	    "usb_check_device_and_status_open(): "
	    "ep=0x%x mode=%d index=%d\n", ep, mode, index);

	if ((rval = usb_check_access(dev)) != 0) {

		return (rval);
	}

	if ((index < 0) || (index > 31)) {

		return (EINVAL);
	}

	usb_dprintf(DEBUG_DETAILED, "claimed=%d ep_interface=%d\n",
	    info->claimed_interface, info->ep_interface[index]);

	if (info->claimed_interface != info->ep_interface[index]) {

		return (EINVAL);
	}

	if ((info->ep_fd[index] > 0) && (info->ep_status_fd[index] > 0)) {

		return (0);
	}

	if (ep == 0) {
		/* should already be open */

		return (0);
	}

	if ((filename = malloc(PATH_MAX+1)) == NULL) {

		return (ENOMEM);
	}
	if ((statfilename = malloc(PATH_MAX+1)) == NULL) {
		free(filename);

		return (ENOMEM);
	}

	usb_dprintf(DEBUG_DETAILED, "cfgvalue=%d\n",
	    info->configuration_value);

	/* create filename */
	if (info->configuration_index > 0) {
		(void) snprintf(cfg_num, sizeof (cfg_num), "cfg%d",
		    info->configuration_value);
	} else {
		(void) memset(cfg_num, 0, sizeof (cfg_num));
	}

	if (info->alternate > 0) {
		(void) snprintf(alt_num, sizeof (alt_num), ".%d",
		    info->alternate);
	} else {
		(void) memset(alt_num, 0, sizeof (alt_num));
	}

	(void) snprintf(filename, PATH_MAX, "%s/%s/%sif%d%s%s%d",
	    hdl->device->bus->dirname, hdl->device->filename,
	    cfg_num, info->ep_interface[index],
	    alt_num, (ep & USB_EP_DIR_MASK) ? "in" :
	    "out", (ep & USB_EP_NUM_MASK));

	usb_dprintf(DEBUG_DETAILED,
	    "usb_check_device_and_status_open: %s\n", filename);

	/*
	 * for interrupt IN endpoints, we need to enable one xfer
	 * mode before opening the endpoint
	 */
	(void) snprintf(statfilename, PATH_MAX, "%sstat", filename);

	if ((ep_type == USB_ENDPOINT_TYPE_INTERRUPT) &&
	    (ep & USB_ENDPOINT_IN)) {
		char control = USB_EP_INTR_ONE_XFER;
		ssize_t count;

		/* open the status device node for the ep first RDWR */
		if ((fdstat = open(statfilename, O_RDWR)) == -1) {
			usb_error_str(errno, "can't open %s RDWR: %d",
			    statfilename, errno);

			/* might be an older ugen version, try RDONLY */
			if ((fdstat = open(statfilename,
			    O_RDONLY)) == -1) {
				usb_error_str(errno,
				    "can't open %s RDONLY: %d",
				    filename, errno);
				free(filename);
				free(statfilename);

				return (errno);
			}
		} else {
			count = write(fdstat, &control, sizeof (control));

			if (count != 1) {
				/* this should have worked */
				usb_error_str(errno, "can't write to %s: %d",
				    filename, errno);
				free(filename);
				free(statfilename);
				(void) close(fdstat);

				return (errno);
			}
		}
	} else {
		if ((fdstat = open(statfilename, O_RDONLY)) == -1) {
			usb_error_str(errno, "can't open %s: %d",
			    statfilename, errno);
			free(filename);
			free(statfilename);

			return (errno);
		}
	}

	/* open the ep */
	if ((fd = open(filename, mode)) == -1) {
		usb_error_str(errno, "can't open %s: %d",
		    filename, errno);
		(void) close(fdstat);
		free(filename);
		free(statfilename);

		return (errno);
	}

	free(filename);
	free(statfilename);
	info->ep_fd[index] = fd;
	info->ep_status_fd[index] = fdstat;


	return (0);
}

/*
 * usb_ep_index:
 *	creates an index from endpoint address that can
 *	be used to index into endpoint lists
 *
 * Returns: ep index (a number between 0 and 31)
 */
static uchar_t
usb_ep_index(uint8_t ep_addr)
{
	return ((ep_addr & USB_EP_NUM_MASK) +
	    ((ep_addr & USB_EP_DIR_MASK) ? 16 : 0));
}

/*
 * usb_open_ep0:
 *	opens default pipe
 *
 * Returns: errno
 */
static int
usb_open_ep0(usb_dev_handle_impl_t *hdl)
{
	char *filename;
	usb_device_specific_t *dev_specific =
	    (usb_device_specific_t *)(hdl->device->dev);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_open_ep0():\n");

	if (dev_specific->ep0_fd) {
		dev_specific->ref_count++;
		hdl->info->ep_fd[0] = dev_specific->ep0_fd;
		hdl->info->ep_status_fd[0] = dev_specific->ep0_fd_stat;

		usb_dprintf(DEBUG_DETAILED,
		    "usb_open_ep0(): already open, ref=%d\n",
		    dev_specific->ref_count);

		return (0);
	}

	if ((filename = malloc(PATH_MAX+1)) == NULL) {

		return (ENOMEM);
	}

	(void) snprintf(filename, PATH_MAX, "%s/%s/cntrl0",
	    hdl->device->bus->dirname, hdl->device->filename);

	usb_dprintf(DEBUG_DETAILED, "opening %s\n", filename);

	hdl->info->ep_fd[0] = open(filename, O_RDWR);
	if (hdl->info->ep_fd[0] < 0) {
		usb_dprintf(DEBUG_ERRORS, "opening ep0 failed, %d\n",
		    hdl->info->ep_fd[0]);
		free(filename);

		return (errno);
	}

	(void) snprintf(filename, PATH_MAX, "%s/%s/cntrl0stat",
	    hdl->device->bus->dirname, hdl->device->filename);

	usb_dprintf(DEBUG_DETAILED, "opening %s\n", filename);

	hdl->info->ep_status_fd[0] = open(filename, O_RDONLY);
	if (hdl->info->ep_status_fd[0] < 0) {
		free(filename);

		return (errno);
	}

	/* allow sharing between multiple opens */
	dev_specific->ep0_fd = hdl->info->ep_fd[0];
	dev_specific->ep0_fd_stat = hdl->info->ep_status_fd[0];
	dev_specific->ref_count++;

	usb_dprintf(DEBUG_DETAILED, "ep0 opened\n");

	free(filename);

	return (0);
}

/*
 * usb_close_ep0:
 *	closes default ep0
 */
static void
usb_close_ep0(usb_dev_handle_impl_t *hdl)
{
	usb_device_specific_t *dev_specific =
	    (usb_device_specific_t *)(hdl->device->dev);

	usb_dprintf(DEBUG_FUNCTIONS, "usb_close_ep0():\n");

	if (dev_specific->ep0_fd) {
		if (--(dev_specific->ref_count) > 0) {
			usb_dprintf(DEBUG_DETAILED,
			    "usb_close_ep0(): ref_count=%d\n",
			    dev_specific->ref_count);

			return;
		}
	}

	if (hdl->info->ep_fd[0] != -1) {
		(void) close(hdl->info->ep_fd[0]);
		hdl->info->ep_fd[0] = -1;
	}
	if (hdl->info->ep_status_fd[0] != -1) {
		(void) close(hdl->info->ep_status_fd[0]);
		hdl->info->ep_status_fd[0] = -1;
	}
	dev_specific->ep0_fd = 0;
	dev_specific->ep0_fd_stat = 0;
}

/*
 * usb_close_all_eps:
 *	closes all open endpoints except 0
 */
static void
usb_close_all_eps(usb_dev_handle_impl_t *hdl)
{
	int i;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_close_all_eps():\n");

	for (i = 1; i < USB_MAXENDPOINTS; i++) {
		if (hdl->info->ep_fd[i] != -1) {
			(void) close(hdl->info->ep_fd[i]);
			hdl->info->ep_fd[i] = -1;
		}
		if (hdl->info->ep_status_fd[i] != -1) {
			(void) close(hdl->info->ep_status_fd[i]);
			hdl->info->ep_status_fd[i] = -1;
		}
	}
}

/*
 * usb_setup_all_configs:
 *	parses config cloud for each config
 *
 * Returns: errno
 */
static int
usb_setup_all_configs(usb_dev_handle_impl_t *hdl)
{
	char buffer[USB_DEV_DESCR_SIZE];
	int rval, len;
	uint_t index;

	if (hdl->device->config) {

		return (0);
	}

	usb_dprintf(DEBUG_FUNCTIONS, "usb_setup_all_configs():\n");

	/* get device descriptor */
	rval = usb_control_msg((usb_dev_handle *)hdl,
	    USB_DEV_REQ_DEV_TO_HOST | USB_TYPE_STANDARD,
	    USB_REQ_GET_DESCRIPTOR, USB_DESCR_TYPE_SETUP_DEV,
	    0, buffer, USB_DEV_DESCR_SIZE, 0);

	usb_dprintf(DEBUG_DETAILED, "dev descr rval=%d\n", rval);

	if (rval != USB_DEV_DESCR_SIZE) {

		return (EIO);
	}

	/* parse device descriptor */
	rval = (int)usb_parse_dev_descr((uchar_t *)buffer, sizeof (buffer),
	    (struct usb_device_descriptor *)&hdl->device->descriptor,
	    sizeof (struct usb_device_descriptor));

	usb_dprintf(DEBUG_DETAILED, "parse dev descr rval=%d\n", rval);

	if (rval != (int)sizeof (struct usb_device_descriptor)) {

		return (EIO);
	}

	/* allocate config array */
	len = (int) sizeof (struct usb_config_descriptor) *
	    hdl->device->descriptor.bNumConfigurations;

	if ((hdl->device->config = calloc(len, 1)) == NULL) {

		return (ENOMEM);
	}

	/* parse each config cloud */
	for (index = 0; index < hdl->device->descriptor.bNumConfigurations;
	    index++) {
		if ((rval = usb_parse_config(hdl, index)) != 0) {

			return (rval);
		}
	}

	return (0);
}

/*
 * usb_free_all_configs:
 *	frees all allocated resources
 */
static void
usb_free_all_configs(usb_device_t *dev)
{
	uint_t index;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_free_all_configs(): "
	    "dev=0x%x config=0x%x #conf=%d\n",
	    dev, dev->config, dev->descriptor.bNumConfigurations);

	if (dev->config) {
		for (index = 0; index < dev->descriptor.bNumConfigurations;
		    index++) {
			usb_free_config(dev, index);
		}
		free(dev->config);
		dev->config = NULL;
	}
}

/*
 * usb_parse_config:
 *	parse config descriptor and get cloud
 *
 * Returns: errno
 */
static int
usb_parse_config(usb_dev_handle_impl_t *hdl, uint_t index)
{
	int rval;
	uint_t iface, len;
	char buffer[USB_CFG_DESCR_SIZE];
	char *cloud;
	unsigned char *extra;
	int extralen;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_parse_config(): index=%d\n",
	    index);

	rval = usb_control_msg((usb_dev_handle *)hdl,
	    USB_DEV_REQ_DEV_TO_HOST | USB_TYPE_STANDARD,
	    USB_REQ_GET_DESCRIPTOR, USB_DESCR_TYPE_SETUP_CFG | index,
	    0, buffer, USB_CFG_DESCR_SIZE, 0);

	usb_dprintf(DEBUG_DETAILED, "config descr rval=%d expecting %d\n",
	    rval, USB_CFG_DESCR_SIZE);

	if (rval < USB_CFG_DESCR_SIZE) {

		return (EIO);
	}

	rval = (int)usb_parse_cfg_descr((uchar_t *)buffer, sizeof (buffer),
	    (usb_cfg_descr_t *)&hdl->device->config[index],
	    sizeof (usb_cfg_descr_t), &extra, &extralen);

	usb_dprintf(DEBUG_DETAILED, "config descr rval=%d expecting %d\n",
	    rval, sizeof (usb_cfg_descr_t));

	if (rval < USB_CFG_DESCR_SIZE) {

		return (EIO);
	}

	usb_dprintf(DEBUG_DETAILED,
	    "cfg%d: len=%d type=%d total=%d #if=%d cf=%d\n", index,
	    hdl->device->config[index].bLength,
	    hdl->device->config[index].bDescriptorType,
	    hdl->device->config[index].wTotalLength,
	    hdl->device->config[index].bNumInterfaces,
	    hdl->device->config[index].bConfigurationValue);

	if ((cloud = malloc(hdl->device->config[index].wTotalLength)) ==
	    NULL) {

		return (ENOMEM);
	}

	/* get complete cloud */
	rval = usb_control_msg((usb_dev_handle *)hdl,
	    USB_DEV_REQ_DEV_TO_HOST | USB_TYPE_STANDARD,
	    USB_REQ_GET_DESCRIPTOR, USB_DESCR_TYPE_SETUP_CFG | index,
	    0, (char *)cloud,
	    hdl->device->config[index].wTotalLength, 0);

	if (rval != hdl->device->config[index].wTotalLength) {
		free(cloud);

		return (EIO);
	}

	/* parse descriptor again to get extra descriptors */
	rval = (int)usb_parse_cfg_descr((uchar_t *)cloud,
	    hdl->device->config[index].wTotalLength,
	    (usb_cfg_descr_t *)&hdl->device->config[index],
	    sizeof (usb_cfg_descr_t), &extra, &extralen);

	if (extralen) {
		usb_dprintf(DEBUG_DETAILED,
		    "cfg%d: extra descriptors length=%d:\n",
		    index, extralen);
		usb_dump_data((char *)extra, extralen);

		if ((hdl->device->config[index].extra =
		    calloc(extralen, 1)) == NULL) {
			free(cloud);

			return (ENOMEM);
		}

		(void) memcpy(hdl->device->config[index].extra, extra,
		    extralen);
		hdl->device->config[index].extralen = extralen;
	}

	/* allocate interface array */
	len = hdl->device->config[index].bNumInterfaces *
	    (int)sizeof (struct usb_interface);
	if ((hdl->device->config[index].interface = calloc(len, 1)) ==
	    NULL) {
		free(cloud);

		return (ENOMEM);
	}

	for (iface = 0; iface < hdl->device->config[index].bNumInterfaces;
	    iface++) {
		rval = usb_parse_interface(hdl, index, iface, cloud);
		if (rval != 0) {
			free(cloud);

			return (rval);
		}
	}
	free(cloud);

	return (0);
}

/*
 * usb_free_config:
 *	frees all allocated config resources
 */
static void
usb_free_config(usb_device_t *device, uint_t index)
{
	uint_t iface;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_free_config(): index=%d\n",
	    index);

	if (device->config[index].interface) {
		for (iface = 0; iface < device->config[index].bNumInterfaces;
		    iface++) {
			usb_free_interface(device, index, iface);
		}
		if (device->config[index].extralen) {
			free(device->config[index].extra);
		}
		free(device->config[index].interface);
	}
}

/*
 * usb_parse_interface:
 *	parse an interface descriptor
 *
 * Returns: errno
 */
static int
usb_parse_interface(usb_dev_handle_impl_t *hdl, uint_t index, uint_t iface,
    char *cloud)
{
	usb_if_descr_t if_descr;
	int rval;
	uint_t alt, max_alt, len;
	unsigned char *extra;
	int extralen;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_parse_interface(): "
	    "index=%d, iface=%d\n", index, iface);

	/* count the number of alternates for this interface */
	for (max_alt = alt = 0; alt < USB_MAXALTSETTING; alt++) {
		rval = (int)usb_parse_if_descr((uchar_t *)cloud,
		    hdl->device->config[index].wTotalLength,
		    iface, alt, &if_descr, sizeof (if_descr),
		    &extra, &extralen);

		usb_dprintf(DEBUG_DETAILED, "usb_parse_interface: "
		    "alt %d: rval=%d expecting %d\n",
		    alt, rval, sizeof (if_descr));

		if (rval != (int)sizeof (if_descr)) {

			break;
		}
		max_alt = alt;
	}

	usb_dprintf(DEBUG_DETAILED,
	    "usb_parse_interface: max_alt=%d\n", max_alt);

	/* allocate alt interface setting array */
	len = ++max_alt * (int)sizeof (struct usb_interface_descriptor);
	if ((hdl->device->config[index].interface[iface].altsetting =
	    calloc(len, 1)) == NULL) {

		return (ENOMEM);
	}
	hdl->device->config[index].interface[iface].num_altsetting =
	    max_alt;
	for (alt = 0; alt < max_alt; alt++) {
		rval = usb_parse_alternate(hdl, index, iface, alt, cloud);
		if (rval != 0) {

			return (rval);
		}
	}

	return (0);
}

/*
 * usb_free_interface:
 *	frees interface resources
 *
 * Returns: errno
 */
static void
usb_free_interface(usb_device_t *device, uint_t index, uint_t iface)
{
	uint_t alt, max_alt;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_free_interface(): "
	    "index=%d, iface=%d\n", index, iface);

	if (device->config[index].interface[iface].altsetting) {
		max_alt = device->config[index].interface[iface].
		    num_altsetting;
		for (alt = 0; alt < max_alt; alt++) {
			usb_free_alternate(device, index, iface, alt);
		}
		free(device->config[index].interface[iface].altsetting);
	}
}

/*
 * usb_parse_alternate:
 *	parses each alternate descriptor
 *
 * Returns: errno
 */
static int
usb_parse_alternate(usb_dev_handle_impl_t *hdl, uint_t index, uint_t iface,
    uint_t alt, char *cloud)
{
	uint_t ep, len;
	usb_if_descr_t if_descr;
	int rval;
	unsigned char *extra;
	int extralen;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_parse_alternate(): "
	    "index=%d, iface=%d, alt=%d\n", index, iface, alt);

	rval = (int)usb_parse_if_descr((uchar_t *)cloud,
	    hdl->device->config[index].wTotalLength,
	    iface, alt, &if_descr, sizeof (if_descr), &extra, &extralen);

	if (rval != (int)sizeof (if_descr)) {
		usb_dprintf(DEBUG_ERRORS, "usb_parse_alternate: rval=%d\n",
		    rval);

		return (EIO);
	}

	usb_dprintf(DEBUG_DETAILED,
	    "cfg%d.if%d.%d: len=%d type=%d num=%d alt=%d #ep=%d c=%d"
	    " sc=%d p=%d i=%d\n", index, iface, alt,
	    if_descr.bLength,
	    if_descr.bDescriptorType,
	    if_descr.bInterfaceNumber,
	    if_descr.bAlternateSetting,
	    if_descr.bNumEndpoints,
	    if_descr.bInterfaceClass,
	    if_descr.bInterfaceSubClass,
	    if_descr.bInterfaceProtocol,
	    if_descr.iInterface);

	(void) memcpy(
	    &hdl->device->config[index].interface[iface].altsetting[alt],
	    &if_descr, sizeof (if_descr));

	if (extralen) {
		usb_dprintf(DEBUG_DETAILED,
		    "cfg%d.if%d.%d: extralen=%d:\n", index, iface, alt,
		    extralen);
		usb_dump_data((char *)extra, extralen);

		if ((hdl->device->config[index].interface[iface].
		    altsetting[alt].extra = calloc(extralen, 1)) == NULL) {

			return (ENOMEM);
		}
		(void) memcpy(
		    hdl->device->config[index].interface[iface].
		    altsetting[alt].extra, extra, extralen);
		hdl->device->config[index].interface[iface].
		    altsetting[alt].extralen = extralen;
	}

	if (if_descr.bNumEndpoints == 0) {

		return (0);
	}

	/* allocate endpoint array for this alternate */
	len = if_descr.bNumEndpoints *
	    (int)sizeof (struct usb_endpoint_descriptor);
	if ((hdl->device->config[index].interface[iface].altsetting[alt].
	    endpoint = calloc(len, 1)) == NULL) {

		return (ENOMEM);
	}

	for (ep = 0; ep < if_descr.bNumEndpoints; ep++) {
		rval = usb_parse_endpoint(hdl, index, iface, alt, ep, cloud);

		if (rval != 0) {

			return (rval);
		}
	}

	return (0);
}

/*
 * usb_free_alternate:
 *	frees all alternate resources
 */
static void
usb_free_alternate(usb_device_t *device, uint_t index, uint_t iface,
	uint_t alt)
{
	usb_dprintf(DEBUG_FUNCTIONS, "usb_free_alternate(): "
	    "index=%d, iface=%d, alt=%d\n", index, iface, alt);

	if (device->config[index].interface[iface].altsetting[alt].
	    endpoint) {
		uint_t ep;
		struct usb_interface_descriptor *if_descr =
		    &device->config[index].
		    interface[iface].altsetting[alt];

		for (ep = 0; ep < if_descr->bNumEndpoints; ep++) {
			if (if_descr->extralen) {
				free(if_descr->extra);
			}
		}

		if (device->config[index].interface[iface].altsetting[alt].
		    extralen) {
			free(device->config[index].interface[iface].
			    altsetting[alt].extra);
		}
		free(device->config[index].interface[iface].altsetting[alt].
		    endpoint);
	}
}

/*
 * usb_parse_endpoint:
 *	 parses an endpoint descriptor
 *
 * Returns: errno
 */
static int
usb_parse_endpoint(usb_dev_handle_impl_t *hdl, int index, int iface,
    int alt, int ep, char *cloud)
{
	usb_ep_descr_t ep_descr;
	int rval;
	unsigned char *extra;
	int extralen;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_parse_endpoint(): "
	    "index=%d, iface=%d, alt=%d, ep=0x%x\n",
	    index, iface, alt, ep);

	rval = (int)usb_parse_ep_descr((uchar_t *)cloud,
	    hdl->device->config[index].wTotalLength,
	    iface, alt, ep, &ep_descr, sizeof (ep_descr),
	    &extra, &extralen);

	if (rval < USB_EP_DESCR_SIZE) {
		usb_dprintf(DEBUG_ERRORS, "usb_parse_endpoint: rval=%d, "
		    "expecting %d\n", rval, USB_EP_DESCR_SIZE);

		return (rval);
	}

	usb_dprintf(DEBUG_DETAILED,
	    "\tl=%d t=%d a=0x%x attr=0x%x max=%d int=%d\n",
	    ep_descr.bLength, ep_descr.bDescriptorType,
	    ep_descr.bEndpointAddress, ep_descr.bmAttributes,
	    ep_descr.wMaxPacketSize, ep_descr.bInterval);

	(void) memcpy(&hdl->device->
	    config[index].interface[iface].altsetting[alt].endpoint[ep],
	    &ep_descr, sizeof (ep_descr));

	if (extralen) {
		usb_dprintf(DEBUG_DETAILED,
		    "cfg%d.if%d.%d.ep%d: extralen=%d:\n",
		    index, iface, alt, ep, extralen);
		usb_dump_data((char *)extra, extralen);

		if ((hdl->device->config[index].interface[iface].
		    altsetting[alt].endpoint[ep].extra =
		    calloc(extralen, 1)) == NULL) {

			return (ENOMEM);
		}
		(void) memcpy(hdl->device->config[index].interface[iface].
		    altsetting[alt].endpoint[ep].extra, extra, extralen);
		hdl->device->config[index].interface[iface].
		    altsetting[alt].endpoint[ep].extralen = extralen;
	}

	return (0);
}

/*
 * usb_add_device:
 *	adds dev to the beginning of the list
 */
static void
usb_add_device(usb_device_t **list, usb_device_t *dev)
{
	if (*list) {
		dev->next = *list;
		dev->next->prev = dev;
	} else {
		dev->next = NULL;
	}
	dev->prev = NULL;
	*list = dev;
}

/*
 * usb_remove_device:
 *	removes dev from a list
 */
static void
usb_remove_device(usb_device_t **list, usb_device_t *dev)
{
	if (dev->prev) {
		dev->prev->next = dev->next;
	} else {
		*list = dev->next;
	}
	if (dev->next) {
		dev->next->prev = dev->prev;
	}
	dev->prev = dev->next = NULL;
}

/*
 * usb_check_device_in_list:
 *	checks if dev is in list
 *
 * Returns: 1 (yes), 0 (no)
 */
static int
usb_check_device_in_list(usb_device_t *list, usb_device_t *dev)
{
	usb_device_t *d = list;

	while (d != NULL) {
		if (d == dev) {

			return (1);
		}
		d = d->next;
	}

	return (0);
}

/*
 * usb_free_bus:
 *	frees the entire bus structure, not used, just for
 *	completeness
 */
static void
usb_free_bus(usb_bus_t *bus)
{
	free(bus);
}

/*
 * usb_free_dev:
 *	frees all configs and then the device structure itself
 */
static void
usb_free_dev(usb_device_t *dev)
{
	usb_dprintf(DEBUG_FUNCTIONS, "usb_free_dev(): 0x%x\n", (int)dev);

	usb_free_all_configs(dev);
	free(dev->dev);
	free(dev);
}

/*
 * usb_get_device_status:
 *	gets status of device
 *
 * Returns: ugen dev status values
 */
static int
usb_get_device_status(int fd)
{
	int status, error;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_get_device_status():\n");

	error = (int)read(fd, &status, (size_t)sizeof (status));
	if (error != (int)sizeof (status)) {
		usb_error_str(errno, "Could not read device status: %d",
		    error);

		return (USB_DEV_STAT_UNAVAILABLE);
	} else {
		switch (status) {
		case USB_DEV_STAT_ONLINE:
			usb_dprintf(DEBUG_DETAILED, "Device is available\n");
			break;
		case USB_DEV_STAT_DISCONNECTED:
			usb_dprintf(DEBUG_DETAILED, "Device has been "
			    "disconnected\n");
			break;
		case USB_DEV_STAT_RESUMED:
			usb_dprintf(DEBUG_DETAILED,
			    "Device has been resumed\n");
			break;
		case USB_DEV_STAT_UNAVAILABLE:
			usb_dprintf(DEBUG_DETAILED,
			    "Device is powered down\n");
			break;
		default:
			usb_dprintf(DEBUG_DETAILED,
			    "Device status=%d\n", status);
		}
	}

	return (status);
}

/*
 * usb_search_dev_usb:
 *	finds all names of devices in the /usb/dev tree
 *	this will be the VID/PID and instance no
 *
 * Returns: errno
 */
static int
usb_search_dev_usb(usb_device_t **new_devices)
{
	DIR			*dir, *subdir;
	struct dirent		*dir_entry, *subdir_entry;
	char			*device, *filename;
	usb_bus_t		*bus = usb_busses;
	struct stat		statbuf;
	regex_t			regex;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_search_dev_usb():\n");

	if ((device = malloc(PATH_MAX+1)) == NULL) {

		return (ENOMEM);
	}

	if ((filename = malloc(PATH_MAX+1)) == NULL) {
		free(device);

		return (ENOMEM);
	}

	if (!(dir = opendir(bus->dirname))) {
		free(device);
		free(filename);

		usb_error_str(errno,
		    "couldn't opendir %s: %d", bus->dirname, errno);

		return (errno);
	}

	/* make sure we only open ugen directories */
	if ((regcomp(&regex, "/dev/usb/[0-9a-f]+[.][0-9a-f]+",
	    REG_EXTENDED) != 0)) {

		return (EINVAL);
	}

	/* search for devices */
	while ((dir_entry = readdir(dir)) != NULL) {

		usb_dprintf(DEBUG_FUNCTIONS, "usb_search_dev_usb(): dir=%s\n",
		    dir_entry->d_name);

		if (dir_entry->d_name[0] == '.') {
			continue;
		}
		(void) snprintf(device, PATH_MAX, "%s/%s", bus->dirname,
		    dir_entry->d_name);

		/*
		 * make sure we don't accidentily open /dev/usb/hid* nodes
		 * which will get them unlinked from the virtual console
		 */
		if (lstat(device, &statbuf) == -1) {
			continue;
		}
		if (!S_ISDIR(statbuf.st_mode)) {
			continue;
		}

		if (regexec(&regex, device, 0, NULL, 0) != 0) {
			continue;
		}

		usb_dprintf(DEBUG_FUNCTIONS, "checking %s\n", device);

		/* need to search instances */
		if (!(subdir = opendir(device))) {
			continue;
		}

		while ((subdir_entry = readdir(subdir)) != NULL) {
			usb_device_t *dev;
			usb_device_specific_t *dev_specific;
			int fd;

			if (subdir_entry->d_name[0] == '.') {
				continue;
			}

			if ((dev = calloc(sizeof (*dev), 1)) == NULL) {
				free(device);
				free(filename);
				regfree(&regex);
				(void) closedir(subdir);
				(void) closedir(dir);

				return (ENOMEM);
			}
			if ((dev_specific = calloc(sizeof (*dev_specific),
			    1)) == NULL) {
				free(device);
				free(filename);
				free(dev);
				regfree(&regex);
				(void) closedir(subdir);
				(void) closedir(dir);

				return (ENOMEM);
			}

			dev->dev = (void *)dev_specific;
			dev->bus = bus;
			(void) snprintf(dev->filename, PATH_MAX, "%s/%s",
			    dir_entry->d_name, subdir_entry->d_name);

			/* See if the device is online */
			(void) snprintf(filename, PATH_MAX, "%s/%s/devstat",
			    bus->dirname, dev->filename);

			usb_dprintf(DEBUG_DETAILED, "filename %s\n", filename);
			usb_dprintf(DEBUG_DETAILED, "dev filename %s\n",
			    dev->filename);

			if ((fd = open(filename, O_RDONLY|O_EXCL)) < 0) {
				usb_dprintf(DEBUG_ERRORS,
				    "usb_search_dev_usb: Couldn't open %s\n",
				    filename);
				free(dev_specific);
				free(dev);
				continue;
			}
			if (usb_get_device_status(fd) != USB_DEV_STAT_ONLINE) {
				(void) close(fd);
				usb_error_str(EIO, "Device %s is not online",
				    dev->filename);

				free(dev_specific);
				free(dev);
				continue;
			}
			(void) close(fd);

			usb_add_device(new_devices, dev);
		}

		(void) closedir(subdir);
	}

	regfree(&regex);
	free(filename);
	free(device);
	(void) closedir(dir);

	return (0);
}

/*
 * usb_get_status:
 *	gets status of endpoint
 *
 * Returns: ugen's last cmd status
 */
static int
usb_get_status(int fd)
{
	int status, error;

	usb_dprintf(DEBUG_FUNCTIONS, "usb_get_status(): fd=%d\n", fd);

	error = (int)read(fd, &status, sizeof (status));
	if (error == (int)sizeof (status)) {
		switch (status) {
		case USB_LC_STAT_NOERROR:
			usb_dprintf(DEBUG_DETAILED, "No Error\n");
			break;
		case USB_LC_STAT_CRC:
			usb_dprintf(DEBUG_ERRORS, "CRC Timeout Detected\n");
			break;
		case USB_LC_STAT_BITSTUFFING:
			usb_dprintf(DEBUG_ERRORS, "Bit Stuffing Violation\n");
			break;
		case USB_LC_STAT_DATA_TOGGLE_MM:
			usb_dprintf(DEBUG_ERRORS, "Data Toggle Mismatch\n");
			break;
		case USB_LC_STAT_STALL:
			usb_dprintf(DEBUG_ERRORS, "End Point Stalled\n");
			break;
		case USB_LC_STAT_DEV_NOT_RESP:
			usb_dprintf(DEBUG_ERRORS, "Device is Not Responding\n");
			break;
		case USB_LC_STAT_PID_CHECKFAILURE:
			usb_dprintf(DEBUG_ERRORS, "PID Check Failure\n");
			break;
		case USB_LC_STAT_UNEXP_PID:
			usb_dprintf(DEBUG_ERRORS, "Unexpected PID\n");
			break;
		case USB_LC_STAT_DATA_OVERRUN:
			usb_dprintf(DEBUG_ERRORS, "Data Exceeded Size\n");
			break;
		case USB_LC_STAT_DATA_UNDERRUN:
			usb_dprintf(DEBUG_ERRORS, "Less data received\n");
			break;
		case USB_LC_STAT_BUFFER_OVERRUN:
			usb_dprintf(DEBUG_ERRORS, "Buffer Size Exceeded\n");
			break;
		case USB_LC_STAT_BUFFER_UNDERRUN:
			usb_dprintf(DEBUG_ERRORS, "Buffer Underrun\n");
			break;
		case USB_LC_STAT_TIMEOUT:
			usb_dprintf(DEBUG_ERRORS, "Command Timed Out\n");
			break;
		case USB_LC_STAT_NOT_ACCESSED:
			usb_dprintf(DEBUG_ERRORS, "Not Accessed by h/w\n");
			break;
		case USB_LC_STAT_UNSPECIFIED_ERR:
			usb_dprintf(DEBUG_ERRORS, "Unspecified Error\n");
			break;
		case USB_LC_STAT_NO_BANDWIDTH:
			usb_dprintf(DEBUG_ERRORS, "No Bandwidth\n");
			break;
		case USB_LC_STAT_HW_ERR:
			usb_dprintf(DEBUG_ERRORS,
			    "Host Controller h/w Error\n");
			break;
		case USB_LC_STAT_SUSPENDED:
			usb_dprintf(DEBUG_ERRORS, "Device was Suspended\n");
			break;
		case USB_LC_STAT_DISCONNECTED:
			usb_dprintf(DEBUG_ERRORS, "Device was Disconnected\n");
			break;
		case USB_LC_STAT_INTR_BUF_FULL:
			usb_dprintf(DEBUG_ERRORS,
			    "Interrupt buffer was full\n");
			break;
		case USB_LC_STAT_INVALID_REQ:
			usb_dprintf(DEBUG_ERRORS, "Request was Invalid\n");
			break;
		case USB_LC_STAT_INTERRUPTED:
			usb_dprintf(DEBUG_ERRORS, "Request was Interrupted\n");
			break;
		case USB_LC_STAT_NO_RESOURCES:
			usb_dprintf(DEBUG_ERRORS, "No resources available for "
			    "request\n");
			break;
		case USB_LC_STAT_INTR_POLLING_FAILED:
			usb_dprintf(DEBUG_ERRORS, "Failed to Restart Poll");
			break;
		default:
			usb_dprintf(DEBUG_ERRORS, "Error Not Determined %d\n",
			    status);
			break;
		}
	}

	return (status);
}

/*
 * Descriptor parsing functions, taken from USBA code
 *
 * usb_parse_data:
 *	take a raw buffer and pads it according to format
 *
 * Returns: USB_PARSE_ERROR or length parsed
 */
static size_t
usb_parse_data(char *format, uchar_t *data, size_t datalen,
    void *structure, size_t structlen)
{
	int	fmt;
	size_t	counter = 1;
	int	multiplier = 0;
	uchar_t	*dataend = data + datalen;
	char	*structstart = (char *)structure;
	void	*structend = (void *)((intptr_t)structstart + structlen);

	if ((format == NULL) || (data == NULL) || (structure == NULL)) {

		return (USB_PARSE_ERROR);
	}

	while ((fmt = *format) != '\0') {

		/*
		 * Could some one pass a "format" that is greater than
		 * the structlen? Conversely, one could pass a ret_buf_len
		 * that is less than the "format" length.
		 * If so, we need to protect against writing over memory.
		 */
		if (counter++ > structlen) {
			break;
		}

		if (fmt == 'c') {
			uint8_t	*cp = (uint8_t *)structure;

			cp = (uint8_t *)(((uintptr_t)cp + _CHAR_ALIGNMENT - 1) &
			    ~(_CHAR_ALIGNMENT - 1));
			if (((data + 1) > dataend) ||
			    ((cp + 1) > (uint8_t *)structend))
				break;

			*cp++ = *data++;
			structure = (void *)cp;
			if (multiplier) {
				multiplier--;
			}
			if (multiplier == 0) {
				format++;
			}
		} else if (fmt == 's') {
			uint16_t	*sp = (uint16_t *)structure;

			sp = (uint16_t *)
			    (((uintptr_t)sp + _SHORT_ALIGNMENT - 1) &
			    ~(_SHORT_ALIGNMENT - 1));
			if (((data + 2) > dataend) ||
			    ((sp + 1) > (uint16_t *)structend))
				break;

			*sp++ = (data[1] << 8) + data[0];
			data += 2;
			structure = (void *)sp;
			if (multiplier) {
				multiplier--;
			}
			if (multiplier == 0) {
				format++;
			}
		} else if (fmt == 'l') {
			uint32_t	*lp = (uint32_t *)structure;

			lp = (uint32_t *)
			    (((uintptr_t)lp + _INT_ALIGNMENT - 1) &
			    ~(_INT_ALIGNMENT - 1));
			if (((data + 4) > dataend) ||
			    ((lp + 1) > (uint32_t *)structend))
				break;

			*lp++ = (((((
			    (uint32_t)data[3] << 8) | data[2]) << 8) |
			    data[1]) << 8) | data[0];
			data += 4;
			structure = (void *)lp;
			if (multiplier) {
				multiplier--;
			}
			if (multiplier == 0) {
				format++;
			}
		} else if (fmt == 'L') {
			uint64_t	*llp = (uint64_t *)structure;

			llp = (uint64_t *)
			    (((uintptr_t)llp + _LONG_LONG_ALIGNMENT - 1) &
			    ~(_LONG_LONG_ALIGNMENT - 1));
			if (((data + 8) > dataend) ||
			    ((llp + 1) >= (uint64_t *)structend))
				break;

			*llp++ = (((((((((((((data[7] << 8) |
			    data[6]) << 8) | data[5]) << 8) |
			    data[4]) << 8) | data[3]) << 8) |
			    data[2]) << 8) | data[1]) << 8) |
			    data[0];
			data += 8;
			structure = (void *)llp;
			if (multiplier) {
				multiplier--;
			}
			if (multiplier == 0) {
				format++;
			}
		} else if (isdigit(fmt)) {
			multiplier = (multiplier * 10) + (fmt - '0');
			counter--;
			format++;
		} else {
			multiplier = 0;
			break;
		}
	}

	return ((intptr_t)structure - (intptr_t)structstart);
}

/*
 * usb_nth_descr:
 *	finds pointer to n-th descriptor of
 *	type descr_type, unless the end of the buffer or a descriptor
 *	of type	stop_descr_type1 or stop_descr_type2 is encountered first.
 *
 * Returns: returns pointer to n-th descriptor
 */
static uchar_t *
usb_nth_descr(uchar_t *buf, size_t buflen, int descr_type, uint_t n,
    int	stop_descr_type1, int stop_descr_type2)
{
	uchar_t	*bufstart = buf;
	uchar_t *bufend = buf + buflen;

	if (buf == NULL) {

		return (NULL);
	}

	while (buf + 2 <= bufend) {
		if ((buf != bufstart) && ((buf[1] == stop_descr_type1) ||
		    (buf[1] == stop_descr_type2))) {

			return (NULL);
		}

		if ((descr_type == USB_DESCR_TYPE_ANY) ||
		    (buf[1] == descr_type)) {
			if (n-- == 0) {

				return (buf);
			}
		}

		/*
		 * Check for a bad buffer.
		 * If buf[0] is 0, then this will be an infite loop
		 */
		INCREMENT_BUF(buf);
	}

	return (NULL);
}

/*
 * usb_parse_dev_descr:
 *	parse device descriptor
 *
 * Returns: #bytes parsed
 */
static size_t
usb_parse_dev_descr(uchar_t *buf, size_t buflen,
    struct usb_device_descriptor *ret_descr, size_t ret_buf_len)
{
	if ((buf == NULL) || (ret_descr == NULL) ||
	    (buflen < 2) || (buf[1] != USB_DESCR_TYPE_DEV)) {

		return (USB_PARSE_ERROR);
	}

	return (usb_parse_data("ccsccccssscccc",
	    buf, buflen, ret_descr, ret_buf_len));
}

/*
 * usb_parse_cfg_descr:
 *	parse config descriptor
 *
 * Returns: #bytes parsed
 */
static size_t
usb_parse_cfg_descr(uchar_t *buf, size_t buflen, usb_cfg_descr_t *ret_descr,
    size_t ret_buf_len, unsigned char **extra, int *extralen)
{
	size_t rval;

	if ((buf == NULL) || (ret_descr == NULL) ||
	    (buflen < 2) || (buf[1] != USB_DESCR_TYPE_CFG)) {

		return (USB_PARSE_ERROR);
	}

	rval = usb_parse_data("ccsccccc",
	    buf, buflen, ret_descr, ret_buf_len);

	usb_find_extra(buf, buflen, extra, extralen);

	return (rval);
}

/*
 * usb_parse_if_descr:
 *	parse interface descriptor
 *
 * Returns: #bytes parsed
 */
static size_t
usb_parse_if_descr(uchar_t *buf, size_t	buflen, uint_t if_number,
    uint_t alt_if_setting, usb_if_descr_t *ret_descr, size_t ret_buf_len,
    unsigned char **extra, int *extralen)
{
	uchar_t *bufend = buf + buflen;
	size_t rval;

	if ((buf == NULL) || (ret_descr == NULL)) {

		return (USB_PARSE_ERROR);
	}

	while (buf + 4 <= bufend) {
		if ((buf[1] == USB_DESCR_TYPE_IF) &&
		    (buf[2] == if_number) &&
		    (buf[3] == alt_if_setting)) {

			rval = usb_parse_data("ccccccccc",
			    buf, ((uintptr_t)bufend - (uintptr_t)buf),
			    ret_descr, ret_buf_len);

			usb_find_extra(buf,
			    ((uintptr_t)bufend - (uintptr_t)buf),
			    extra, extralen);

			return (rval);
		}

		/*
		 * Check for a bad buffer.
		 * If buf[0] is 0, then this will be an infinite loop
		 */
		INCREMENT_BUF(buf);
	}

	return (USB_PARSE_ERROR);
}


/*
 * usb_parse_ep_descr:
 *	parse config descriptor
 *	the endpoint index is relative to the interface. index 0 is
 *	the first endpoint
 *
 * Returns: #bytes parsed
 */
size_t
usb_parse_ep_descr(uchar_t *buf, size_t buflen, uint_t if_number,
    uint_t alt_if_setting, uint_t ep_index, usb_ep_descr_t *ret_descr,
    size_t ret_buf_len, unsigned char **extra, int *extralen)
{
	uchar_t *bufend = buf + buflen;
	size_t rval;

	if ((buf == NULL) || (ret_descr == NULL)) {

		return (USB_PARSE_ERROR);
	}

	while ((buf + 4) <= bufend) {
		if (buf[1] == USB_DESCR_TYPE_IF &&
		    buf[2] == if_number &&
		    buf[3] == alt_if_setting) {
			if ((buf = usb_nth_descr(buf,
			    (uintptr_t)bufend - (uintptr_t)buf,
			    USB_DESCR_TYPE_EP, ep_index,
			    USB_DESCR_TYPE_IF, -1)) == NULL) {

				break;
			}

			rval = usb_parse_data("ccccsccc", buf,
			    (uintptr_t)bufend - (uintptr_t)buf,
			    ret_descr, ret_buf_len);
			usb_find_extra(buf, (uintptr_t)bufend - (uintptr_t)buf,
			    extra, extralen);

			return (rval);
		}

		/*
		 * Check for a bad buffer.
		 * If buf[0] is 0, then this will be an infinite loop
		 */
		INCREMENT_BUF(buf);
	}

	return (USB_PARSE_ERROR);
}

/*
 * extra descriptor handling
 *
 * usb_find_extra:
 *	finds any non-standard descriptor after the current
 *	standard descriptor and puts a pointer in extra argument
 *	and the length in extralen
 */
static	void
usb_find_extra(uchar_t *buf, size_t buflen,
    unsigned char **extra, int *extralen)
{
	uchar_t *next = buf + buf[0];

	*extralen = 0;
	*extra = next;

	while (((uintptr_t)next - (uintptr_t)buf + 1) < buflen) {
		if ((next[1] == USB_DT_CONFIG) ||
		    (next[1] == USB_DT_INTERFACE) ||
		    (next[1] == USB_DT_ENDPOINT)) {
			*extralen = (int)((uintptr_t)next -
			    (uintptr_t)buf - buf[0]);

			return;
		}
		next += next[0];
	}
}

/*
 * error handling
 *
 * usb_strerror:
 *	lookup error string
 *
 * Returns: error string
 */
char *
usb_strerror(void)
{
	usb_dprintf(DEBUG_FUNCTIONS, "usb_strerror(): "
	    "usb_error_type=%d, errno=%d\n", usb_error_type, usb_error_errno);

	switch (usb_error_type) {
	case USB_ERROR_TYPE_NONE:
		return ("No error");

	case USB_ERROR_TYPE_STRING:
		return (usb_error_string);

	case USB_ERROR_TYPE_ERRNO:
		if (usb_error_errno > 0) {

			return (strerror(usb_error_errno));
		}
	default:
		break;
	}

	return ("Unknown error");
}

/*
 * usb_error:
 *	stores the error number in the global usb_error_errno
 *
 * Returns: negative error number
 */
static int
usb_error(int x)
{
	usb_dprintf(DEBUG_FUNCTIONS, "usb_error(): error=%d\n", x);

	usb_error_type = USB_ERROR_TYPE_ERRNO;
	usb_error_errno = x;

	return (-x);
}

/*
 * usb_error_str:
 *	creates error string
 */
static void
usb_error_str(int x, char *format, ...)
{
	va_list ap;

	va_start(ap, format);

	usb_error_type = USB_ERROR_TYPE_ERRNO;
	usb_error_errno = x;

	(void) vsnprintf(usb_error_string, sizeof (usb_error_string),
	    format, ap);

	usb_dprintf(DEBUG_ERRORS, "USB error (%d): %s\n", x, usb_error_string);

	va_end(ap);
}

/*
 * usb_dprintf:
 *	prints out tracing messages according to level
 */
static void
usb_dprintf(int level, char *format, ...)
{
	va_list ap;
	char buf[512];

	va_start(ap, format);

	(void) vsnprintf(buf, sizeof (buf), format, ap);
	if (libusb_debug >= level) {
		(void) fprintf(stderr, buf);
	}
	va_end(ap);
}

/*
 * usb_dump_data:
 *	print data buffer
 */
static void
usb_dump_data(char *data, int size)
{
	int i;

	if (libusb_debug >= DEBUG_DATA_DUMP) {
		(void) fprintf(stderr, "data dump:");
		for (i = 0; i < size; i++) {
			if (i % 16 == 0) {
				(void) fprintf(stderr, "\n%08x	", i);
			}
			(void) fprintf(stderr, "%02x ", (uchar_t)data[i]);
		}
		(void) fprintf(stderr, "\n");
	}
}
