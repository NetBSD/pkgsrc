$NetBSD: patch-common-src_conffile.c,v 1.1 2015/08/09 22:50:10 dholland Exp $

Update the defaults for a few things to use LOCALSTATEDIR (which will
be $VARBASE/amanda) instead of compiling in /usr/adm, which no system
has shipped in the last twenty years or so.  PR 38958.

--- common-src/conffile.c.orig	2012-02-21 11:36:51.000000000 +0000
+++ common-src/conffile.c
@@ -35,6 +35,7 @@
 #include "util.h"
 #include "conffile.h"
 #include "clock.h"
+#include "configmake.h"
 #include <glib.h>
 
 /*
@@ -5330,9 +5331,9 @@ init_defaults(
     conf_init_str   (&conf_data[CNF_LABELSTR]             , ".*");
     conf_init_str   (&conf_data[CNF_TAPELIST]             , "tapelist");
     conf_init_str   (&conf_data[CNF_DISKFILE]             , "disklist");
-    conf_init_str   (&conf_data[CNF_INFOFILE]             , "/usr/adm/amanda/curinfo");
-    conf_init_str   (&conf_data[CNF_LOGDIR]               , "/usr/adm/amanda");
-    conf_init_str   (&conf_data[CNF_INDEXDIR]             , "/usr/adm/amanda/index");
+    conf_init_str   (&conf_data[CNF_INFOFILE]             , LOCALSTATEDIR "/curinfo");
+    conf_init_str   (&conf_data[CNF_LOGDIR]               , LOCALSTATEDIR);
+    conf_init_str   (&conf_data[CNF_INDEXDIR]             , LOCALSTATEDIR "/index");
     conf_init_ident    (&conf_data[CNF_TAPETYPE]             , "DEFAULT_TAPE");
     conf_init_identlist(&conf_data[CNF_HOLDINGDISK]          , NULL);
     conf_init_int      (&conf_data[CNF_DUMPCYCLE]            , 10);
