$NetBSD: patch-src_fsmagic.c,v 1.1 2015/03/27 18:57:43 bsiegert Exp $
Explicitly convert mode_t to unsigned int for formatted output

--- src/fsmagic.c.orig	2014-12-04 15:56:46.000000000 +0000
+++ src/fsmagic.c
@@ -394,7 +394,7 @@ file_fsmagic(struct magic_set *ms, const
 		break;
 
 	default:
-		file_error(ms, 0, "invalid mode 0%o", sb->st_mode);
+		file_error(ms, 0, "invalid mode 0%o", (unsigned int)sb->st_mode);
 		return -1;
 		/*NOTREACHED*/
 	}
