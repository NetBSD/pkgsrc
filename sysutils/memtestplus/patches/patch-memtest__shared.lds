$NetBSD: patch-memtest__shared.lds,v 1.2 2019/02/09 11:39:25 maya Exp $

Compensate for a local patch in netbsd's binutils.
https://mail-index.netbsd.org/tech-toolchain/2019/02/09/msg003405.html

NetBSD creates another program header and thus we need more space for
headers.

--- memtest_shared.lds.orig	2013-08-10 02:01:58.000000000 +0000
+++ memtest_shared.lds
@@ -3,7 +3,7 @@ OUTPUT_ARCH(i386);
 
 ENTRY(startup_32); 
 SECTIONS {
-	. = 0;
+	. = 0x100;
 	.text : {
 		_start = .;
 		*(.text)
