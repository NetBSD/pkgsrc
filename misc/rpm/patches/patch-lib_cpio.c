$NetBSD: patch-lib_cpio.c,v 1.1 2015/03/22 17:32:55 sevan Exp $

CVE-2014-8118 - Integer overflow allows remote attackers to execute arbitrary
code via a crafted CPIO header in the payload section of an RPM file, which
triggers a stack-based buffer overflow.

https://bugzilla.redhat.com/show_bug.cgi?id=1168715

--- lib/cpio.c.orig	2014-06-30 08:47:13.000000000 +0000
+++ lib/cpio.c
@@ -399,6 +399,9 @@ int rpmcpioHeaderRead(rpmcpio_t cpio, ch
 
     GET_NUM_FIELD(hdr.filesize, fsize);
     GET_NUM_FIELD(hdr.namesize, nameSize);
+    if (nameSize <= 0 || nameSize > 4096) {
+	return RPMERR_BAD_HEADER;
+    }
 
     char name[nameSize + 1];
     read = Fread(name, nameSize, 1, cpio->fd);
