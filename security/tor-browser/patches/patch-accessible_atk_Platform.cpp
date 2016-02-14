$NetBSD: patch-accessible_atk_Platform.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- accessible/atk/Platform.cpp.orig	2015-05-04 00:43:17.000000000 +0000
+++ accessible/atk/Platform.cpp
@@ -18,8 +18,9 @@
 #include <dbus/dbus.h>
 #endif
 #include <gtk/gtk.h>
+
 #if (MOZ_WIDGET_GTK == 3)
-#include <atk-bridge.h>
+extern "C" __attribute__((weak,visibility("default"))) int atk_bridge_adaptor_init(int*, char **[]);
 #endif
 
 using namespace mozilla;
@@ -46,7 +47,6 @@ static gulong sToplevel_hide_hook = 0;
 
 GType g_atk_hyperlink_impl_type = G_TYPE_INVALID;
 
-#if (MOZ_WIDGET_GTK == 2)
 struct GnomeAccessibilityModule
 {
     const char *libName;
@@ -67,11 +67,13 @@ static GnomeAccessibilityModule sAtkBrid
     "gnome_accessibility_module_shutdown", nullptr
 };
 
+#if (MOZ_WIDGET_GTK == 2)
 static GnomeAccessibilityModule sGail = {
     "libgail.so", nullptr,
     "gnome_accessibility_module_init", nullptr,
     "gnome_accessibility_module_shutdown", nullptr
 };
+#endif
 
 static nsresult
 LoadGtkModule(GnomeAccessibilityModule& aModule)
@@ -98,7 +100,11 @@ LoadGtkModule(GnomeAccessibilityModule& 
             else
                 subLen = loc2 - loc1;
             nsAutoCString sub(Substring(libPath, loc1, subLen));
+#if (MOZ_WIDGET_GTK == 2)
             sub.AppendLiteral("/gtk-2.0/modules/");
+#else
+            sub.AppendLiteral("/gtk-3.0/modules/");
+#endif
             sub.Append(aModule.libName);
             aModule.lib = PR_LoadLibrary(sub.get());
             if (aModule.lib)
@@ -123,7 +129,6 @@ LoadGtkModule(GnomeAccessibilityModule& 
     }
     return NS_OK;
 }
-#endif // (MOZ_WIDGET_GTK == 2)
 
 void
 a11y::PlatformInit()
@@ -175,14 +180,17 @@ a11y::PlatformInit()
 
   // Init atk-bridge now
   PR_SetEnv("NO_AT_BRIDGE=0");
-#if (MOZ_WIDGET_GTK == 2)
-  rv = LoadGtkModule(sAtkBridge);
-  if (NS_SUCCEEDED(rv)) {
-    (*sAtkBridge.init)();
-  }
-#else
-  atk_bridge_adaptor_init(nullptr, nullptr);
+#if (MOZ_WIDGET_GTK == 3)
+  if (atk_bridge_adaptor_init) {
+    atk_bridge_adaptor_init(nullptr, nullptr);
+  } else
 #endif
+  {
+    nsresult rv = LoadGtkModule(sAtkBridge);
+    if (NS_SUCCEEDED(rv)) {
+      (*sAtkBridge.init)();
+    }
+  }
 
   if (!sToplevel_event_hook_added) {
     sToplevel_event_hook_added = true;
@@ -210,7 +218,6 @@ a11y::PlatformShutdown()
                                     sToplevel_hide_hook);
     }
 
-#if (MOZ_WIDGET_GTK == 2)
     if (sAtkBridge.lib) {
         // Do not shutdown/unload atk-bridge,
         // an exit function registered will take care of it
@@ -221,6 +228,7 @@ a11y::PlatformShutdown()
         sAtkBridge.init = nullptr;
         sAtkBridge.shutdown = nullptr;
     }
+#if (MOZ_WIDGET_GTK == 2)
     if (sGail.lib) {
         // Do not shutdown gail because
         // 1) Maybe it's not init-ed by us. e.g. GtkEmbed
