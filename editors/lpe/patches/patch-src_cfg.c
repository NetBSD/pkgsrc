$NetBSD: patch-src_cfg.c,v 1.1 2025/01/14 14:40:47 ktnb Exp $

Update error setting to slang 2

--- src/cfg.c.orig	2001-06-20 09:44:42.000000000 +0000
+++ src/cfg.c
@@ -37,7 +37,7 @@ cfg_init (void)
 	if (SLang_load_file (DATADIR "/lpe/init.sl") == -1)
 	{
 	    SLang_restart (1);
-	    SLang_Error = 0;
+	    SLang_set_error (0);
 	}
     }
 }
