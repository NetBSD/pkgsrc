$NetBSD: patch-drivers_hidparser.c,v 1.1 2015/11/10 08:52:38 mrg Exp $

work around horrible big-endian code that assumes "long" is 32 bits.
enables usb-nut-ups to work on sparc64.


--- drivers/hidparser.c.orig	2012-07-31 10:38:59.000000000 -0700
+++ drivers/hidparser.c	2015-11-10 00:30:11.000000000 -0800
@@ -163,7 +163,7 @@
 #if WORDS_BIGENDIAN
 			{
 				int	i;
-				unsigned long	valTmp = 0;
+				unsigned valTmp = 0;
 
 				for (i = 0; i < ItemSize[pParser->Item & SIZE_MASK]; i++) {
 					memcpy(&valTmp, &pParser->ReportDesc[(pParser->Pos)+i], 1);
