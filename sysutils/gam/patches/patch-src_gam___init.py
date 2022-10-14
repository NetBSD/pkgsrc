$NetBSD: patch-src_gam___init.py,v 1.1 2022/10/14 12:01:18 sborrill Exp $

Don't check for updates

--- gam/__init__.py.orig	2022-10-14 12:42:57.307510055 +0100
+++ gam/__init__.py	2022-10-14 12:43:41.196030867 +0100
@@ -583,8 +583,8 @@
         GC_Values[GC_CONFIG_DIR], FN_LAST_UPDATE_CHECK_TXT)
     GM_Globals[GM_ENABLEDASA_TXT] = os.path.join(
         GC_Values[GC_CONFIG_DIR], FN_ENABLEDASA_TXT)
-    if not GC_Values[GC_NO_UPDATE_CHECK]:
-        doGAMCheckForUpdates()
+#    if not GC_Values[GC_NO_UPDATE_CHECK]:
+#        doGAMCheckForUpdates()
 
 # domain must be set and customer_id must be set and != my_customer when enable_dasa = true
     if GC_Values[GC_ENABLE_DASA]:
