$NetBSD: patch-src_java.desktop_unix_native_common_awt_fontpath.c,v 1.1 2022/05/13 14:24:19 ryoon Exp $

--- src/java.desktop/unix/native/common/awt/fontpath.c.orig	2022-02-05 03:44:09.000000000 +0000
+++ src/java.desktop/unix/native/common/awt/fontpath.c
@@ -56,8 +56,8 @@
 extern Display *awt_display;
 #endif /* !HEADLESS */
 
-#define FONTCONFIG_DLL_VERSIONED VERSIONED_JNI_LIB_NAME("fontconfig", "1")
-#define FONTCONFIG_DLL JNI_LIB_NAME("fontconfig")
+#define FONTCONFIG_DLL_VERSIONED "@BUILDLINK_PREFIX.fontconfig@/lib/" JNI_LIB_NAME("fontconfig")
+#define FONTCONFIG_DLL "@BUILDLINK_PREFIX.fontconfig@/lib/" JNI_LIB_NAME("fontconfig")
 
 #define MAXFDIRS 512    /* Max number of directories that contain fonts */
 
@@ -88,6 +88,27 @@ static char *fullAixFontPath[] = {
     NULL, /* terminates the list */
 };
 #endif
+static char *pkgsrcFontPath[] = {
+   "@PREFIX@/share/fonts/X11/100dpi",
+   "@PREFIX@/share/fonts/X11/75dpi",
+   "@PREFIX@/share/fonts/X11/Type1",
+   "@PREFIX@/share/fonts/X11/cyrillic",
+   "@PREFIX@/share/fonts/X11/misc",
+   "@PREFIX@/share/fonts/X11/TTF",
+   "/usr/X11R7/lib/X11/fonts/100dpi",
+   "/usr/X11R7/lib/X11/fonts/75dpi",
+   "/usr/X11R7/lib/X11/fonts/Type1",
+   "/usr/X11R7/lib/X11/fonts/cyrillic",
+   "/usr/X11R7/lib/X11/fonts/misc",
+   "/usr/X11R7/lib/X11/fonts/TTF",
+   "/usr/X11R6/lib/X11/fonts/100dpi",
+   "/usr/X11R6/lib/X11/fonts/75dpi",
+   "/usr/X11R6/lib/X11/fonts/Type1",
+   "/usr/X11R6/lib/X11/fonts/cyrillic",
+   "/usr/X11R6/lib/X11/fonts/misc",
+   "/usr/X11R6/lib/X11/fonts/TTF",
+   NULL
+};
 
 static char **getFontConfigLocations();
 
@@ -329,6 +350,7 @@ static char *getPlatformFontPathChars(JN
 #elif defined(_AIX)
     knowndirs = fullAixFontPath;
 #endif
+    knowndirs = pkgsrcFontPath;
     /* REMIND: this code requires to be executed when the GraphicsEnvironment
      * is already initialised. That is always true, but if it were not so,
      * this code could throw an exception and the fontpath would fail to
