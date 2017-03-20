$NetBSD: patch-hier.c,v 1.5 2017/03/20 16:23:20 schmonz Exp $

Install files without needing real qmail users to exist yet.

--- hier.c.orig	1998-06-15 10:53:16.000000000 +0000
+++ hier.c
@@ -1,6 +1,7 @@
 #include "auto_qmail.h"
 #include "auto_split.h"
-#include "auto_uids.h"
+#include "pkgsrc_user_destdir_fake_uids.h"
+#include "pkgsrc_user_destdir_fake_chown.c"
 #include "fmt.h"
 #include "fifo.h"
 
