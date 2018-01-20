$NetBSD: patch-src_cmd_5l_obj.c,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Change Load Align in ELF Program Headers to the same as the system standard

--- src/cmd/5l/obj.c.orig	2015-09-23 04:37:36.000000000 +0000
+++ src/cmd/5l/obj.c
@@ -82,7 +82,6 @@ archinit(void)
 		break;
 	case Hlinux:	/* arm elf */
 	case Hfreebsd:
-	case Hnetbsd:
 		debug['d'] = 0;	// with dynamic linking
 		elfinit();
 		HEADR = ELFRESERVE;
@@ -93,6 +92,17 @@ archinit(void)
 		if(INITRND == -1)
 			INITRND = 4096;
 		break;
+	case Hnetbsd:
+		debug['d'] = 0;	// with dynamic linking
+		elfinit();
+		HEADR = ELFRESERVE;
+		if(INITTEXT == -1)
+			INITTEXT = 0x10000 + HEADR;
+		if(INITDAT == -1)
+			INITDAT = 0;
+		if(INITRND == -1)
+			INITRND = 0x10000;
+		break;
 	case Hnacl:
 		elfinit();
 		HEADR = 0x10000;
