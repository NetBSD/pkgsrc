/* $NetBSD: usbprog.c,v 1.2 2010/08/03 15:22:27 drochner Exp $ */

/* Written by Matthias Drochner. Public domain. */

#include "sysdep.h"

#include "cable.h"
#include "chain.h"

#include "generic.h"
#include "generic_usbconn.h"

#include "usbconn.h"
#include "usbconn/libusb.h"

#include <errno.h>
#include <string.h>

/* for use with the "usbprogJTAG" firmware */
#define PIN_TDI   7
#define PIN_SRST  6
#define PIN_TRST  5
#define PIN_TMS   4
#define PIN_TCK   2
#define PIN_TDO   0

static int
usbprog_xfer(usb_dev_handle *h, char *d, int len, int rd)
{
	int res;
	unsigned char buf[2];

	res = usb_bulk_write(h, 3, d, len, 100);
	if (res != len) {
		fprintf(stderr, "xfer wr: %d\n", res);
		return (-1);
	}
	if (!rd)
		return 0;
	res = usb_bulk_read(h, 2, buf, 2, 100);
	if (res <= 0) {
		fprintf(stderr, "xfer rd: %d\n", res);
		return (-1);
	}
	return (buf[1]);
}

static int
usbprog_init(cable_t *cable)
{
	int res;
	struct usb_dev_handle *h;
	unsigned char cmd[2];

	res = usbconn_open(cable->link.usb);
	if (res)
		return (-1);
	h = ((libusb_param_t*)(cable->link.usb->params))->handle;

	cmd[0] = 0x01; /* PORT_DIRECTION */
	cmd[1] = (1 << PIN_TDI) | (1 << PIN_TMS) | (1 << PIN_TCK)
			| (1 << PIN_SRST) | (1 << PIN_TRST);
	res = usbprog_xfer(h, cmd, 2, 0);
	if (res)
		fprintf(stderr, "usbprog_init: error %d\n", res);
	return 0;
}

static void
usbprog_setport(cable_t *cable, unsigned char val)
{
	struct usb_dev_handle *h;
	unsigned char cmd[2];
	int res;

	h = ((libusb_param_t*)(cable->link.usb->params))->handle;
	cmd[0] = 2; /* PORT_SET */
	cmd[1] = val;
	res = usbprog_xfer(h, cmd, 2, 0);
	if (res)
		fprintf(stderr, "usbprog_setport: error %d\n", res);
}

static void
usbprog_clock(cable_t *cable, int tms, int tdi, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		usbprog_setport(cable, (0 << PIN_TCK) | (tms << PIN_TMS)
					| (tdi << PIN_TDI));
		cable_wait(cable);
		usbprog_setport(cable, (1 << PIN_TCK) | (tms << PIN_TMS)
					| (tdi << PIN_TDI));
		cable_wait(cable);
	}
}

static int
usbprog_get_tdo(cable_t *cable)
{
	struct usb_dev_handle *h;
	unsigned char cmd[2];
	int res;

	h = ((libusb_param_t*)(cable->link.usb->params))->handle;

	usbprog_setport(cable, 0);
	cable_wait(cable);

	cmd[0] = 3; /* PORT_GET */
	cmd[1] = 0;
	res = usbprog_xfer(h, cmd, 2, 1);
	if (res < 0)
		fprintf(stderr, "usbprog_get_tdo: error %d\n", res);
	return ((res >> PIN_TDO) & 1);
}

static int
usbprog_set_signal(cable_t *cable, int mask, int val)
{

	/* /TRST isn't supported yet */
	if (mask & ~CS_TRST)
		fprintf(stderr, "usbprog_set_signal called(%x, %x)\n",
			mask, val);
	return 1;
}

static int
usbprog_transfer(cable_t *cable, int len, char *in, char *out )
{
	struct usb_dev_handle *h;
	unsigned char cmd[64]; /* ??? */
	unsigned char ans[64]; /* ??? */
	int blen, i, res;

	if (len < 3)
		return (generic_transfer(cable, len, in, out));

	h = ((libusb_param_t*)(cable->link.usb->params))->handle;

	memset(cmd, 0, sizeof(cmd));
	cmd[0] = 0x08; /* WRITE_AND_READ */
	cmd[1] = len / 256;
	cmd[2] = len % 256;
	blen = (len + 7) / 8;
	for (i = 0; i < len; i++)
		cmd[3 + i / 8] |= in[i] << (i % 8);

	res = usb_bulk_write(h, 3, cmd, blen + 3, 100);
	if (res != blen + 3)
		fprintf(stderr, "usbprog_transfer: write error\n");
	res = usb_bulk_read(h, 2, ans, 64, 500);
	if (res != 64)
		fprintf(stderr, "usbprog_transfer(%d): read %d\n", len, res);
	if (!out)
		return len;
	for (i = 0; i < len; i++)
		if (ans[3 + i / 8] & (1 << (i % 8)))
			out[i] = 1;
		else
			out[i] = 0;
	return len;
}

cable_driver_t usbprog_cable_driver = {
	"usbprog",
	"usbprog with usbprogJTAG firmware",
	generic_usbconn_connect,
	generic_disconnect,
	generic_usbconn_free,
	usbprog_init,
	generic_usbconn_done,
	generic_set_frequency,
	usbprog_clock,
	usbprog_get_tdo,
	usbprog_transfer,
	usbprog_set_signal,
	generic_get_signal,
	generic_flush_using_transfer,
	generic_usbconn_help
};

usbconn_cable_t usbconn_cable_usbprog = {
	"usbprog",			/* cable name */
	NULL,				/* string pattern, not used */
	"libusb",			/* usbconn driver */ 
	0x1781,				/* VID (MetaGeek?) */
	0x0c62				/* PID (usbprog) */
};
