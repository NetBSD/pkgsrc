$NetBSD: patch-ext_cdparanoia_gstcdparanoiasrc.h,v 1.1 2021/11/15 22:01:19 wiz Exp $

Adapt path to pkgsrc location of cdparanoia headers.

--- ext/cdparanoia/gstcdparanoiasrc.h.orig	2021-03-15 17:48:01.219277600 +0000
+++ ext/cdparanoia/gstcdparanoiasrc.h
@@ -34,8 +34,8 @@ static const char GST_PLUGINS_BASE_VERSI
   #include <cdda/cdda_interface.h>
   #include <cdda/cdda_paranoia.h>
 #else
-  #include <cdda_interface.h>
-  #include <cdda_paranoia.h>
+  #include <cdparanoia/cdda_interface.h>
+  #include <cdparanoia/cdda_paranoia.h>
 #endif
 
 #define GST_TYPE_CD_PARANOIA_SRC            (gst_cd_paranoia_src_get_type())
