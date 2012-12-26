$NetBSD: patch-jambase.c,v 1.1 2012/12/26 18:51:47 ryoon Exp $

--- jambase.c.orig	2012-12-26 18:50:42.000000000 +0000
+++ jambase.c
@@ -607,7 +607,6 @@ const char *jambase[] = {
 "\n",
 "case SOLARIS :\n",
 "RANLIB      ?= \"\" ;\n",
-"AR      ?= \"/usr/ccs/bin/ar ru\" ;\n",
 "\n",
 "case UNICOS :\n",
 "NOARSCAN    ?= true ;\n",
