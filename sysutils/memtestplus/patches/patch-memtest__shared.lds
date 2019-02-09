$NetBSD: patch-memtest__shared.lds,v 1.1 2019/02/09 09:13:24 maya Exp $

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
