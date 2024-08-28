$NetBSD: patch-src_gam___init.py,v 1.3 2024/08/28 13:20:34 sborrill Exp $

Don't check for updates

--- gam/__init__.py.orig	2024-08-27 15:01:56.000000000 +0100
+++ gam/__init__.py	2024-08-27 15:03:43.916076241 +0100
@@ -585,8 +585,8 @@
         GC_Values[GC_CONFIG_DIR], FN_LAST_UPDATE_CHECK_TXT)
     GM_Globals[GM_ENABLEDASA_TXT] = os.path.join(
         GC_Values[GC_CONFIG_DIR], FN_ENABLEDASA_TXT)
-    if not GC_Values[GC_NO_UPDATE_CHECK]:
-        doGAMCheckForUpdates(forceCheck=0)
+#    if not GC_Values[GC_NO_UPDATE_CHECK]:
+#        doGAMCheckForUpdates(forceCheck=0)
 
 # domain must be set and customer_id must be set and != my_customer when enable_dasa = true
     if GC_Values[GC_ENABLE_DASA]:
