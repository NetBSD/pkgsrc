$NetBSD: patch-src_cmd_6l_obj.c,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Change Load Align in ELF Program Headers to the same as the system standard.
 
--- src/cmd/6l/obj.c.orig	2015-09-23 04:37:36.000000000 +0000
+++ src/cmd/6l/obj.c
@@ -114,7 +114,6 @@ archinit(void)
 		break;
 	case Hlinux:		/* elf64 executable */
 	case Hfreebsd:		/* freebsd */
-	case Hnetbsd:		/* netbsd */
 	case Hopenbsd:		/* openbsd */
 	case Hdragonfly:	/* dragonfly */
 	case Hsolaris:		/* solaris */
@@ -127,6 +126,16 @@ archinit(void)
 		if(INITRND == -1)
 			INITRND = 4096;
 		break;
+	case Hnetbsd:		/* netbsd */
+		elfinit();
+		HEADR = ELFRESERVE;
+		if(INITTEXT == -1)
+			INITTEXT = (1<<22)+HEADR;
+		if(INITDAT == -1)
+			INITDAT = 0;
+		if(INITRND == -1)
+			INITRND = 0x200000;
+		break;
 	case Hnacl:
 		elfinit();
 		debug['w']++; // disable dwarf, which gets confused and is useless anyway
