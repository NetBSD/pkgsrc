$NetBSD: patch-linux_hid-libusb.c,v 1.1 2015/04/03 22:29:12 rodent Exp $

inptr has to be type casted for iconv on NetBSD.

--- linux/hid-libusb.c.orig	2011-10-26 00:58:17.000000000 +0000
+++ linux/hid-libusb.c
@@ -351,7 +351,7 @@ static wchar_t *get_usb_string(libusb_de
 	inbytes = len-2;
 	outptr = (char*) wbuf;
 	outbytes = sizeof(wbuf);
-	res = iconv(ic, &inptr, &inbytes, &outptr, &outbytes);
+	res = iconv(ic, (const char **) &inptr, &inbytes, &outptr, &outbytes);
 	if (res == (size_t)-1)
 		goto err;
 
