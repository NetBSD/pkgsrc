$NetBSD: patch-spectro_usbio__bsd.c,v 1.1 2023/11/17 17:37:48 jakllsch Exp $

Attempt to make actually function with NetBSD ugen(4).

--- spectro/usbio_bsd.c.orig	2023-10-23 00:56:17.000000000 +0000
+++ spectro/usbio_bsd.c
@@ -67,13 +67,15 @@ icompaths *p 
 #if defined(__FreeBSD__)
 	    "/dev/usb/[0-9]*.*.0",		/* FreeBSD >= 8 */
 	    "/dev/ugen[0-9]*",			/* FreeBSD < 8, but no .E */
+#elif defined(__NetBSD__)
+	    "/dev/ugen[0-9]*.00",		/* NetBSD */
 #else
-	    "/dev/ugen/[0-9]*.00",		/* NetBSD, OpenBSD */
+	    "/dev/ugen/[0-9]*.00",		/* OpenBSD */
 #endif
 	    NULL
 	};
 	int vid, pid;
-	int nconfig = 0, nep = 0;
+	unsigned int configix, nconfig, nep;
 	char *dpath;
 	devType itype;
 	struct usb_idevice *usbd = NULL;
@@ -85,6 +87,9 @@ icompaths *p 
 		glob_t g;
 		int fd;
 		struct usb_device_info di;
+		usb_device_descriptor_t udd;
+		struct usb_interface_desc uid;
+		struct usb_config_desc ucd;
 		int rv, found = 0;
 
 		if (paths[j] == NULL)
@@ -121,12 +126,8 @@ icompaths *p 
 				continue;
 			}
 
-			// ~~99 need to check number of end points ~~~
-			// ~~99 and number of configs
-			nconfig = 1;
- 
-//USB_GET_DEVICEINFO	struct usb_device_info
-//USB_GET_DEVICE_DESC	struct usb_device_descriptor
+			if (ioctl(fd, USB_GET_DEVICE_DESC, &udd) < 0)
+				continue;
 
 			/* Allocate an idevice so that we can fill in the end point information */
 			if ((usbd = (struct usb_idevice *) calloc(sizeof(struct usb_idevice), 1)) == NULL) {
@@ -136,8 +137,56 @@ icompaths *p 
 				return ICOM_SYS;
 			}
 
-			usbd->nconfig = nconfig;
+			usbd->nconfig = nconfig = udd.bNumConfigurations;
 			
+			/* Read the configuration descriptors looking for the first configuration, first interface, */
+			/* and extract the number of end points for each configuration */
+			for (configix = 0; configix < nconfig; configix++) {
+				ucd.ucd_config_index = configix;
+				if (ioctl(fd, USB_GET_CONFIG_DESC, &ucd) < 0) {
+					free(usbd);
+					close(fd);
+					break;
+				}
+				usbd->nifce = ucd.ucd_desc.bNumInterface;
+				usbd->config = ucd.ucd_desc.bConfigurationValue;
+
+				if (ucd.ucd_desc.bConfigurationValue != 1)
+					continue;
+
+				uid.uid_config_index = USB_CURRENT_CONFIG_INDEX;
+				uid.uid_interface_index = 0;
+				uid.uid_alt_index = USB_CURRENT_ALT_INDEX;
+
+				if (ioctl(fd, USB_GET_INTERFACE_DESC, &uid) < 0) {
+					break;
+				}
+
+				nep = uid.uid_desc.bNumEndpoints;
+
+				unsigned int epix;
+				struct usb_endpoint_desc ued;
+				for (epix = 0; epix < nep; epix++) {
+					ued.ued_config_index = USB_CURRENT_CONFIG_INDEX;
+					ued.ued_interface_index = 0;
+					ued.ued_alt_index = USB_CURRENT_ALT_INDEX;
+					ued.ued_endpoint_index = epix;
+					if (ioctl(fd, USB_GET_ENDPOINT_DESC, &ued) < 0) {
+						break;
+					}
+
+					const unsigned int ad = ued.ued_desc.bEndpointAddress;
+					usbd->EPINFO(ad).valid = 1;
+					usbd->EPINFO(ad).addr = ad;
+					usbd->EPINFO(ad).packetsize = UGETW(ued.ued_desc.wMaxPacketSize);
+					usbd->EPINFO(ad).type = ued.ued_desc.bmAttributes & IUSB_ENDPOINT_TYPE_MASK;
+					usbd->EPINFO(ad).interface = uid.uid_desc.bInterfaceNumber;
+					usbd->EPINFO(ad).fd = -1;
+
+					a1logd(p->log, 6, "set ep ad 0x%x packetsize %d type %d\n",ad,usbd->EPINFO(ad).packetsize,usbd->EPINFO(ad).type);
+				}
+			}
+
 			/* Found a known instrument ? */
 			if ((itype = inst_usb_match(vid, pid, nep)) != instUnknown) {
 				char pname[400], *cp;
@@ -310,7 +359,6 @@ char **pnames		/* List of process names 
 	if (p->is_open)
 		p->close_port(p);
 
-#ifdef NEVER    // ~~99
 	/* Make sure the port is open */
 	if (!p->is_open) {
 		int rv, i, iface;
@@ -345,12 +393,16 @@ char **pnames		/* List of process names 
 			p->cconfig = 1;
 
 			if (p->cconfig != config) {
+#if 0
 				if ((rv = ioctl(p->usbd->fd, USBDEVFS_SETCONFIGURATION, &config)) != 0) {
 					a1logd(p->log, 1, "icoms_usb_setconfig failed with %d\n",rv);
 					return ICOM_SYS;
 				}
 				p->cconfig = config;
 				a1logd(p->log, 6, "usb_open_port: set config %d OK\n",config);
+#else
+				a1logd(p->log, 6, "usb_open_port: set config %d unimplemented\n",config);
+#endif
 			}
 
 			/* We're done */
@@ -363,6 +415,7 @@ char **pnames		/* List of process names 
 		/* Claim all the interfaces */
 		for (iface = 0; iface < p->nifce; iface++) {
 
+#if 0
 			if ((rv = ioctl(p->usbd->fd, USBDEVFS_CLAIMINTERFACE, &iface)) < 0) {
 				struct usbdevfs_getdriver getd;
 				getd.interface = iface;
@@ -387,6 +440,30 @@ char **pnames		/* List of process names 
 					return ICOM_SYS;
 				}
 			}
+#endif
+		}
+
+		char epdpath[33];
+		snprintf(epdpath, sizeof(epdpath), "%s.%02d", p->usbd->dpath, 0);
+		int fd;
+		fd = open(epdpath, O_RDWR);
+		p->ep[0].fd = fd;
+
+		for (int i = 1; i < 16; i++) {
+			int flg;
+			if (p->ep[i].valid && p->ep[i+16].valid)
+				flg = O_RDWR;
+			else if (p->ep[i].valid)
+				flg = O_WRONLY;
+			else if (p->ep[i+16].valid)
+				flg = O_RDONLY;
+			else
+				continue;
+
+			snprintf(epdpath, sizeof(epdpath), "%s.%02d", p->usbd->dpath, i);
+			int fd = open(epdpath, flg);
+
+			p->ep[i].fd = p->ep[i+16].fd = fd;
 		}
 
 		/* Clear any errors. */
@@ -408,25 +485,10 @@ char **pnames		/* List of process names 
 			p->rd_qa = 8;
 		a1logd(p->log, 8, "usb_open_port: 'serial' read quanta = packet size = %d\n",p->rd_qa);
 
-		/* Start the reaper thread to handle URB completions */
-		if ((rv = pipe(p->usbd->sd_pipe)) < 0) {
-			a1loge(p->log, ICOM_SYS, "usb_open_port: creat pipe failed with %d\n",rv);
-			return ICOM_SYS;
-		}
-		pthread_mutex_init(&p->usbd->lock, NULL);
-		
-		p->usbd->running = 1;
-		if ((rv = pthread_create(&p->usbd->thread, NULL, urb_reaper, (void*)p)) < 0) {
-			p->usbd->running = 0;
-			a1loge(p->log, ICOM_SYS, "usb_open_port: creating urb reaper thread failed with %s\n",rv);
-			return ICOM_SYS;
-		}
-
 		p->is_open = 1;
 		a1logd(p->log, 8, "usb_open_port: USB port is now open\n");
 	}
 
-#endif  // ~~99
 	/* Install the cleanup signal handlers, and add to our cleanup list */
 	usb_install_signal_handlers(p);
 
@@ -445,88 +507,23 @@ static int icoms_usb_transaction(
 	int length,
 	unsigned int timeout		/* In msec */
 ) {
-	int type;
 	int remlen;
 	unsigned char *bp;
-	int xlength = 0;
+	ssize_t xlength = 0;
 	int i;
 	int reqrv = ICOM_OK;
 
-#ifdef NEVER    // ~~99
 	in_usb_rw++;
 	a1logd(p->log, 8, "icoms_usb_transaction: req type 0x%x ep 0x%x size %d\n",ttype,endpoint,length);
 
-	if (!p->usbd->running) {
-		in_usb_rw--;
-		a1logv(p->log, 1, "icoms_usb_transaction: reaper thread is not running\n");
-		return ICOM_SYS;
-	}
+	/* XXX USB_SET_TIMEOUT */
 
-	/* Translate icoms transfer type of Linux */
-	switch (ttype) {
-		case icom_usb_trantype_command:
-			type = USBDEVFS_URB_TYPE_CONTROL;
-			break;
-		case icom_usb_trantype_interrutpt:
-			type = USBDEVFS_URB_TYPE_INTERRUPT;
-			break;
-		case icom_usb_trantype_bulk:
-			type = USBDEVFS_URB_TYPE_BULK;
-			break;
-	}
+	if ((endpoint & IUSB_ENDPOINT_DIR_MASK) == IUSB_ENDPOINT_OUT)
+		xlength = write(p->ep[endpoint&0xf].fd, buffer, length);
+	else
+		xlength = read(p->ep[endpoint&0xf].fd, buffer, length);
 
-	/* Setup the icom req and urbs */
-	req.urbs = NULL;
-	pthread_mutex_init(&req.lock, NULL);
-	pthread_cond_init(&req.cond, NULL);
-
-	/* Linux historically only copes with 16384 length urbs, */
-	/* so break up longer requests into multiple urbs */
-
-	req.cancelled = 0;
-	req.nourbs = req.nurbs = (length + (1 << 14)-1) >> 14;
-	if ((req.urbs = (usbio_urb *)calloc(sizeof(usbio_urb), req.nourbs)) == NULL) {
-		in_usb_rw--;
-		a1loge(p->log, ICOM_SYS, "icoms_usb_transaction: control transfer too big! (%d)\n",length);
-		return ICOM_SYS;
-	}
-
-	bp = buffer;
-	remlen = length;
-	for (i = 0; i < req.nurbs; i++) {
-		req.urbs[i].req = &req;
-		req.urbs[i].urbno = i;
-		/* Setup Linux URB */
-		req.urbs[i].urb.usercontext = &req.urbs[i];
-		req.urbs[i].urb.type = type; 
-		if (type != USBDEVFS_URB_TYPE_CONTROL)
-			req.urbs[i].urb.endpoint = endpoint;
-		if (remlen > 16384)
-			req.urbs[i].urb.buffer_length = 16384;
-		else
-			req.urbs[i].urb.buffer_length = remlen;
-		req.urbs[i].urb.buffer = (void *)bp;
-		remlen -= req.urbs[i].urb.buffer_length;
-		bp += req.urbs[i].urb.buffer_length;
-		req.urbs[i].urb.status = -EINPROGRESS;
-	}
-a1logd(p->log, 8, "icoms_usb_transaction: reset req %p nourbs to %d\n",&req,req.nourbs);
-
-	/* Add our request to the req list so that it can be cancelled on reap failure */
-	pthread_mutex_lock(&p->usbd->lock);
-	req.next = p->usbd->reqs;
-	p->usbd->reqs = &req;
-	pthread_mutex_unlock(&p->usbd->lock);
-
-	/* submit the URBs */
-	for (i = 0; i < req.nurbs; i++) {
-		if ((rv = ioctl(p->usbd->fd, USBDEVFS_SUBMITURB, &req.urbs[i].urb)) < 0) {
-			a1logd(p->log, 1, "coms_usb_transaction: Submitting urb to fd %d failed with %d\n",p->usbd->fd, rv);
-			req.urbs[i].urb.status = ICOM_SYS;	/* Mark it as failed to submit */
-			req.nourbs--;
-		}
-	}
-	
+#if 0	
 	if (cancelt != NULL) {
 		amutex_lock(cancelt->cmtx);
 		cancelt->hcancel = (void *)&req;
@@ -534,85 +531,7 @@ a1logd(p->log, 8, "icoms_usb_transaction
 		amutex_unlock(cancelt->cond);		/* Signal any thread waiting for IO start */
 		amutex_unlock(cancelt->cmtx);
 	}
-
-	/* Wait for the reaper to wake us, or for a timeout, */
-	/* or for the reaper to die. */
-	pthread_mutex_lock(&req.lock);
-	if (req.nourbs > 0) {
-		struct timeval tv;
-		struct timespec ts;
-
-		// this is unduly complicated...
-		gettimeofday(&tv, NULL);
-		ts.tv_sec = tv.tv_sec + timeout/1000;
-		ts.tv_nsec = (tv.tv_usec + (timeout % 1000) * 1000) * 1000L;
-		if (ts.tv_nsec > 1000000000L) {
-			ts.tv_nsec -= 1000000000L;
-			ts.tv_sec++;
-		}
-		
-		for(;;) {	/* Ignore spurious wakeups */
-			if ((rv = pthread_cond_timedwait(&req.cond, &req.lock, &ts)) != 0) {
-				if (rv != ETIMEDOUT) {
-					pthread_mutex_unlock(&req.lock);
-					a1logd(p->log, 1, "coms_usb_transaction: pthread_cond_timedwait failed with %d\n",rv);
-					rv = ICOM_SYS;
-					goto done;
-				}
-
-				/* Timed out - cancel the remaining URB's */
-				a1logd(p->log, 8, "coms_usb_transaction: time out - cancel remaining URB's\n");
-				reqrv = ICOM_TO;
-				if (!req.cancelled && (rv = cancel_req(p, &req, -1)) != ICOM_OK) {
-					pthread_mutex_unlock(&req.lock);
-					reqrv = ICOM_SYS;
-					/* Since cancelling failed, we can't wait for them to be reaped */
-					goto done;
-				}
-	
-				/* Wait for the cancelled URB's to be reaped */
-				for (;req.nourbs > 0;) {	/* Ignore spurious wakeups */
-					if ((rv = pthread_cond_wait(&req.cond, &req.lock)) != 0) {
-						pthread_mutex_unlock(&req.lock);
-						a1logd(p->log, 1, "coms_usb_transaction:  pthread_cond_wait failed with %d\n",rv);
-						reqrv = ICOM_SYS;
-						/* Waiting for reap failed, so give up */
-						goto done;
-					}
-				}
-			} else {
-				a1logd(p->log, 8, "coms_usb_transaction: reap - %d left\n",req.nourbs);
-			}
-			if (req.nourbs <= 0)
-				break;				/* All urbs's are done */
-		}
-	}
-	pthread_mutex_unlock(&req.lock);
-
-	/* Compute the overall result by going through the urbs. */
-	for (i = 0; i < req.nurbs; i++) {
-		int stat = req.urbs[i].urb.status;
-		xlength += req.urbs[i].urb.actual_length;
-
-		if (stat == ICOM_SYS) {	/* Submit or cancel failed */
-			reqrv = ICOM_SYS;
-		} else if (reqrv == ICOM_OK && stat < 0 && stat != -ECONNRESET) {	/* Error result */
-			if ((endpoint & IUSB_ENDPOINT_DIR_MASK) == IUSB_ENDPOINT_OUT)
-				reqrv = ICOM_USBW;
-			else
-				reqrv = ICOM_USBR;
-		} else if (reqrv == ICOM_OK && stat == -ECONNRESET) {	/* Cancelled */
-			reqrv = ICOM_CANC;
-		} else if (reqrv == ICOM_OK
-		        && req.urbs[i].urb.actual_length < req.urbs[i].urb.buffer_length) {
-			/* Disregard any following urb's status - they are probably cancelled */
-			break;
-		}
-		/* reqrv == ICOM_TO will ignore urb status */
-	}
-
-	if (ttype == icom_usb_trantype_command)
-		xlength += IUSB_REQ_HEADER_SIZE;		/* Account for header - linux doesn't */
+#endif
 
 	/* requested size wasn't transferred ? */
 	if (reqrv == ICOM_OK && xlength != length)
@@ -621,6 +540,7 @@ a1logd(p->log, 8, "icoms_usb_transaction
 	if (transferred != NULL)
 		*transferred = xlength;
 
+#if 0
 done:;
 	if (cancelt != NULL) {
 		amutex_lock(cancelt->cmtx);
@@ -630,20 +550,7 @@ done:;
 		cancelt->state = 2;
 		amutex_unlock(cancelt->cmtx);
 	}
-
-	/* Remove our request from the list  */
-	pthread_mutex_lock(&p->usbd->lock);
-	preq = &p->usbd->reqs;
-	while (*preq != &req && *preq != NULL)		/* Find it */
-		preq = &((*preq)->next);
-	if (*preq != NULL)
-		*preq = (*preq)->next;
-	pthread_mutex_unlock(&p->usbd->lock);
-
-	if (req.urbs != NULL)
-		free(req.urbs);
-	pthread_cond_destroy(&req.cond);
-	pthread_mutex_destroy(&req.lock);
+#endif
 
 	if (in_usb_rw < 0)
 		exit(0);
@@ -651,7 +558,6 @@ done:;
 	in_usb_rw--;
 
 	a1logd(p->log, 8, "coms_usb_transaction: returning err 0x%x and %d bytes\n",reqrv, xlength);
-#endif  // ~~99
 
 	return reqrv;
 }
@@ -666,51 +572,34 @@ int value, int index, unsigned char *byt
 int timeout) {
 	int reqrv = ICOM_OK;
 	int dirw = (requesttype & IUSB_REQ_DIR_MASK) == IUSB_REQ_HOST_TO_DEV ? 1 : 0;
-	unsigned char *buf;
+	struct usb_ctl_request ucr;
 
 	a1logd(p->log, 8, "icoms_usb_control_msg: type 0x%x req 0x%x size %d\n",requesttype,request,size);
 
-#ifdef NEVER    // ~~99
-	/* Allocate a buffer for the ctrl header + payload */
-	if ((buf = calloc(1, IUSB_REQ_HEADER_SIZE + size)) == NULL) {
-		a1loge(p->log, ICOM_SYS, "icoms_usb_control_msg: calloc failed\n");
-		return ICOM_SYS;
-	}
-
+	ucr.ucr_addr = 0;
 	/* Setup the control header */
-	buf[0] = requesttype;
-	buf[1] = request;
-	short2buf(buf + 2, value);
-	short2buf(buf + 4, index);
-	short2buf(buf + 6, size);
-
-	/* If it's a write, copy the write data into the buffer */
-	if (dirw)
-		memcpy(buf + IUSB_REQ_HEADER_SIZE, bytes, size);
-
-	reqrv = icoms_usb_transaction(p, NULL, transferred, icom_usb_trantype_command,   
-	                  dirw ? 0x80 : 0x00, buf, IUSB_REQ_HEADER_SIZE + size, timeout);  
-
-	/* If read, copy the data back */
-	if (!dirw)
-		memcpy(bytes, buf + IUSB_REQ_HEADER_SIZE, size);
+	ucr.ucr_request.bmRequestType = requesttype;
+	ucr.ucr_request.bRequest = request;
+	USETW(ucr.ucr_request.wValue, value);
+	USETW(ucr.ucr_request.wIndex, index);
+	USETW(ucr.ucr_request.wLength, size);
+	ucr.ucr_data = bytes;
+	ucr.ucr_flags = USBD_SHORT_XFER_OK;
+	ucr.ucr_actlen = 0;
 
-	if (transferred != NULL)	/* Adjust for header size requested */
-		*transferred -= IUSB_REQ_HEADER_SIZE;
+	/* XXX USB_SET_TIMEOUT */
 
-	free(buf);
+	if (ioctl(p->ep[0].fd, USB_DO_REQUEST, &ucr) < 0)
+		return ICOM_SYS; /* XXX */
+
+	if (transferred != NULL)
+		*transferred = ucr.ucr_actlen;
 
-#endif  // ~~99
 	a1logd(p->log, 8, "icoms_usb_control_msg: returning err 0x%x and %d bytes\n",reqrv, *transferred);
 	return reqrv;
 }
 
 /*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
-/* Time out error return value */
-
-#define USBIO_ERROR_TIMEOUT	-ETIMEDOUT
-
-/*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
 
 /* Cancel i/o in another thread */
 int icoms_usb_cancel_io(
@@ -718,8 +607,9 @@ int icoms_usb_cancel_io(
 	usb_cancelt *cancelt
 ) {
 	int rv = ICOM_OK;
-#ifdef NEVER    // ~~99
+
 	a1logd(p->log, 8, "icoms_usb_cancel_io called\n");
+#ifdef NEVER    // ~~99
 	usb_lock_cancel(cancelt);
 	if (cancelt->hcancel != NULL)
 		rv = cancel_req(p, (usbio_req *)cancelt->hcancel, -1);
@@ -740,6 +630,8 @@ int icoms_usb_resetep(
 ) {
 	int rv = ICOM_OK;
 
+	a1logd(p->log, 1, "icoms_usb_resetep unimplemented with %d\n",rv);
+
 #ifdef NEVER    // ~~99
 	if ((rv = ioctl(p->usbd->fd, USBDEVFS_RESETEP, &ep)) != 0) {
 		a1logd(p->log, 1, "icoms_usb_resetep failed with %d\n",rv);
@@ -757,6 +649,8 @@ int icoms_usb_clearhalt(
 ) {
 	int rv = ICOM_OK;
 
+	a1logd(p->log, 1, "icoms_usb_clearhalt unimplemented with %d\n",rv);
+
 #ifdef NEVER    // ~~99
 	if ((rv = ioctl(p->usbd->fd, USBDEVFS_CLEAR_HALT, &ep)) != 0) {
 		a1logd(p->log, 1, "icoms_usb_clearhalt failed with %d\n",rv);
