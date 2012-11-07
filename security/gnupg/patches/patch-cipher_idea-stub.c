$NetBSD: patch-cipher_idea-stub.c,v 1.1 2012/11/07 21:07:38 wiz Exp $

commit c3a5448379cdf07b408a265fe8f477901524170d
Author: Werner Koch <wk@gnupg.org>
Date:   Wed Nov 7 21:38:27 2012 +0100

    Fix usage of dlerror to conform to POSIX.

    * cipher/idea-stub.c: Clear last error before dlsym.
    --

    This is required for NetBSD.

    Reported-by: Thomas Klausner

--- cipher/idea-stub.c.orig	2012-01-20 10:51:15.000000000 +0000
+++ cipher/idea-stub.c
@@ -130,6 +130,8 @@ load_module (const char *name)
       goto failure;
     }
 
+  dlerror ();  /* Clear old errors or initialize dlerror.  */
+
   sym = dlsym (handle, "idea_get_info");
   if (dlerror ())
     sym = dlsym (handle, "_idea_get_info");
