$NetBSD: patch-audio__sun.c,v 1.1 2016/01/29 16:33:54 wiz Exp $

Remove unused header that breaks compilation on NetBSD.

--- audio_sun.c.orig	2004-01-23 09:41:31.000000000 +0000
+++ audio_sun.c
@@ -38,7 +38,6 @@
 #  include <stropts.h>
 # endif
 
-# include <sys/conf.h>
 # include <mad.h>
 
 # include "gettext.h"
