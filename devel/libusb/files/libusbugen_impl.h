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

#ifndef _SYS_USB_LIBUSB_LIBUSB_IMPL_H
#define	_SYS_USB_LIBUSB_LIBUSB_IMPL_H

#ifdef	__cplusplus
extern "C" {
#endif

/* debug levels */
#define	DEBUG_NONE		0
#define	DEBUG_ERRORS		1
#define	DEBUG_RECOVERABLE	2
#define	DEBUG_FUNCTIONS 	3
#define	DEBUG_DETAILED		4
#define	DEBUG_DATA_DUMP		5

/* api binding */
#define	API_RELAXED		0
#define	API_STRICT		1

/*
 * XXX issues: remove duplicates with usb.h
 */
typedef struct usb_device usb_device_t;
typedef struct usb_bus usb_bus_t;
typedef struct usb_ctrl_setup usb_ctrl_setup_t;

/* some useful defines */
#define	USB_DEV_REQ_HOST_TO_DEV 	0x00
#define	USB_DEV_REQ_DEV_TO_HOST 	0x80
#define	USB_DEV_REQ_DIR_MASK		0x80

#define	USB_DESCR_TYPE_SETUP_DEV		0x0100
#define	USB_DESCR_TYPE_SETUP_CFG		0x0200
#define	USB_DESCR_TYPE_SETUP_STRING		0x0300
#define	USB_DESCR_TYPE_SETUP_IF 		0x0400
#define	USB_DESCR_TYPE_SETUP_EP 		0x0500
#define	USB_DESCR_TYPE_SETUP_DEV_QLF		0x0600
#define	USB_DESCR_TYPE_SETUP_OTHER_SPEED_CFG	0x0700
#define	USB_DESCR_TYPE_SETUP_IFPWR		0x0800

#define	USB_DESCR_TYPE_DEV			0x01
#define	USB_DESCR_TYPE_CFG			0x02
#define	USB_DESCR_TYPE_STRING			0x03
#define	USB_DESCR_TYPE_IF			0x04
#define	USB_DESCR_TYPE_EP			0x05
#define	USB_DESCR_TYPE_DEV_QLF			0x06
#define	USB_DESCR_TYPE_OTHER_SPEED_CFG		0x07
#define	USB_DESCR_TYPE_IF_PWR			0x08

/*
 * bEndpointAddress masks
 */
#define	USB_EP_NUM_MASK 	0x0F		/* endpoint number mask */
#define	USB_EP_DIR_MASK 	0x80		/* direction mask */
#define	USB_EP_DIR_OUT		0x00		/* OUT endpoint */
#define	USB_EP_DIR_IN		0x80		/* IN endpoint */

/*
 * The compiler pads the above structures;  the following represent the
 * unpadded, aggregate data sizes.
 */
#define	USB_DEV_DESCR_SIZE	18	/* device descr size */
#define	USB_CFG_DESCR_SIZE	 9	/* configuration desc. size */
#define	USBA_CFG_PWR_DESCR_SIZE 18	/* configuration pwr desc. size */
#define	USB_IF_DESCR_SIZE	 9	/* interface descr size */
#define	USBA_IF_PWR_DESCR_SIZE	15	/* interface pwr descr size */
#define	USB_EP_DESCR_SIZE	 7	/* endpoint descr size */

#define	BYTE_SWAP(x)  ((((x) & 0xff) << 8) | (((x) & 0xff00) >> 8))

/* I/O direction */
#define	READ	0
#define	WRITE	1

typedef enum {
	USB_ERROR_TYPE_NONE = 0,
	USB_ERROR_TYPE_STRING,
	USB_ERROR_TYPE_ERRNO
} usb_error_type_t;

/*
 * This records the file descriptors for endpoint/status devices.
 */
typedef struct usb_dev_handle_info {
	int	configuration_value;
	int	configuration_index;
	int	claimed_interface;
	int	alternate;
	int	ep_fd[USB_MAXENDPOINTS];
	int	ep_status_fd[USB_MAXENDPOINTS];
	int	ep_interface[USB_MAXENDPOINTS];
} usb_dev_handle_info_t;

typedef struct {
	usb_device_t	*device;
	usb_dev_handle_info_t *info;
} usb_dev_handle_impl_t;

#define	USB_MAX_INTERFACES	256

typedef struct {
	int	ref_count;
	int	ep0_fd;
	int	ep0_fd_stat;
	usb_dev_handle_impl_t
		*claimed_interfaces[USB_MAX_INTERFACES];
} usb_device_specific_t;

#define	USB_PARSE_ERROR 0
#define	USB_DESCR_TYPE_ANY			-1	/* Wild card */

#define	INCREMENT_BUF(buf) \
		if ((buf)[0] == 0) { \
			break; \
		} else { \
			(buf) += (buf)[0]; \
		}
#define	isdigit(ch) ((ch >= '0') && (ch <= '9'))

typedef struct usb_cfg_descr {
	uint8_t 	bLength;	/* descriptor size		*/
	uint8_t 	bDescriptorType; /* set to CONFIGURATION	*/
	uint16_t	wTotalLength;	/* total length of data returned */
	uint8_t 	bNumInterfaces; /* # interfaces in config	*/
	uint8_t 	bConfigurationValue; /* arg for SetConfiguration */
	uint8_t 	iConfiguration; /* configuration string 	*/
	uint8_t 	bmAttributes;	/* config characteristics	*/
	uint8_t 	MaxPower;	/* max pwr consumption		*/
} usb_cfg_descr_t;


/*
 * usb_if_descr:
 *	usb interface descriptor, refer to USB 2.0/9.6.5
 */
typedef  struct usb_if_descr {
	uint8_t 	bLength;		/* descriptor size	*/
	uint8_t 	bDescriptorType;	/* set to INTERFACE	*/
	uint8_t 	bInterfaceNumber;	/* interface number	*/
	uint8_t 	bAlternateSetting;	/* alt. interface number */
	uint8_t 	bNumEndpoints;		/* # of endpoints	*/
	uint8_t 	bInterfaceClass;	/* class code		*/
	uint8_t 	bInterfaceSubClass;	/* sub class code	*/
	uint8_t 	bInterfaceProtocol;	/* protocol code	*/
	uint8_t 	iInterface;		/* description string	*/
} usb_if_descr_t;


/*
 * usb_ep_descr:
 *	usb endpoint descriptor, refer to USB 2.0/9.6.6
 */
typedef struct usb_ep_descr {
	uint8_t 	bLength;		/* descriptor size	*/
	uint8_t 	bDescriptorType;	/* set to ENDPOINT	*/
	uint8_t 	bEndpointAddress;	/* address of this e/p */
	uint8_t 	bmAttributes;		/* transfer type	*/
	uint16_t	wMaxPacketSize; 	/* maximum packet size	*/
	uint8_t 	bInterval;		/* e/p polling interval */
	uint8_t		bRefresh;		/* refresh */
	uint8_t		bSynchAddress;
} usb_ep_descr_t;

#ifdef __cplusplus
}
#endif

#endif /* _SYS_USB_LIBUSB_LIBUSB_IMPL_H */
