$NetBSD: patch-common-src_conffile.c,v 1.2 2018/11/23 22:33:13 spz Exp $

Update the defaults for a few things to use LOCALSTATEDIR (which will
be $VARBASE/amanda) instead of compiling in /usr/adm, which no system
has shipped in the last twenty years or so.  PR 38958.

--- common-src/conffile.c.orig	2016-02-09 22:52:51.000000000 +0000
+++ common-src/conffile.c
@@ -36,6 +36,7 @@
 #include "util.h"
 #include "conffile.h"
 #include "clock.h"
+#include "configmake.h"
 #include <glib.h>
 
 /*
@@ -5295,9 +5296,9 @@ init_defaults(
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
     conf_init_int      (&conf_data[CNF_DUMPCYCLE]            , CONF_UNIT_NONE, 10);
