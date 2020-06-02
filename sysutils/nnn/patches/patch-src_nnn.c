$NetBSD: patch-src_nnn.c,v 1.1 2020/06/02 11:07:42 sjmulder Exp $

Wrap FILE_MIME_OPTS use in check, since it's not defined (at the top of
nnn.c) for Illumos which doesn't have such an option.

https://github.com/jarun/nnn/pull/622

--- src/nnn.c.orig	2020-05-26 00:08:38.000000000 +0000
+++ src/nnn.c
@@ -3689,9 +3689,11 @@ static bool show_stats(const char *fpath
 			}
 			fprintf(fp, " %s\n  ", begin);
 
+#ifdef FILE_MIME_OPTS
 			/* Show the file mime type */
 			get_output(g_buf, CMD_LEN_MAX, "file", FILE_MIME_OPTS, fpath, FALSE);
 			fprintf(fp, "%s", g_buf);
+#endif
 		}
 	}
 
