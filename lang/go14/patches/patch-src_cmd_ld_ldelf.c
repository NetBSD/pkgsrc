$NetBSD: patch-src_cmd_ld_ldelf.c,v 1.1 2016/02/21 14:32:24 bsiegert Exp $

--- src/cmd/ld/ldelf.c.orig	2015-09-23 04:37:36.000000000 +0000
+++ src/cmd/ld/ldelf.c
@@ -888,12 +888,15 @@ reltype(char *pn, int elftype, uchar *si
 	case R('6', R_X86_64_PC32):
 	case R('6', R_X86_64_PLT32):
 	case R('6', R_X86_64_GOTPCREL):
+	case R('6', R_X86_64_GOTPCRELX):
+	case R('6', R_X86_64_REX_GOTPCRELX):
 	case R('8', R_386_32):
 	case R('8', R_386_PC32):
 	case R('8', R_386_GOT32):
 	case R('8', R_386_PLT32):
 	case R('8', R_386_GOTOFF):
 	case R('8', R_386_GOTPC):
+	case R('8', R_386_GOT32X):
 		*siz = 4;
 		break;
 	case R('6', R_X86_64_64):
