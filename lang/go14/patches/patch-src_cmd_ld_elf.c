$NetBSD: patch-src_cmd_ld_elf.c,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Change to EABI when NetBSD/arm (earm)

--- src/cmd/ld/elf.c.orig	2015-09-23 04:37:36.000000000 +0000
+++ src/cmd/ld/elf.c
@@ -55,8 +55,8 @@ elfinit(void)
 
 	// 32-bit architectures
 	case '5':
-		// we use EABI on both linux/arm and freebsd/arm.
-		if(HEADTYPE == Hlinux || HEADTYPE == Hfreebsd)
+		// we use EABI on linux/arm, freebsd/arm and netbsd/arm
+		if(HEADTYPE == Hlinux || HEADTYPE == Hfreebsd || Hnetbsd)
 			hdr.flags = 0x5000002; // has entry point, Version5 EABI
 		// fallthrough
 	default:
