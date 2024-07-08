$NetBSD: patch-src_main.cc,v 1.3 2024/07/08 14:04:42 micha Exp $

Include missing header.
Add placeholder for pkgsrc PREFIX to beginning of search list.
Remove date to make builds reproducible (based on Debian patch).

--- src/main.cc.orig	2024-07-04 06:00:57.000000000 +0000
+++ src/main.cc
@@ -30,6 +30,7 @@
 
 #include <time.h>
 #include <memory>
+#include <signal.h>
 #include <stdexcept>
 
 #include "im_color.h"
@@ -324,6 +325,7 @@ static void Determine_InstallPath(const 
 #else
 		static const fs::path prefixes[] =
 		{
+			"PKGSRC_PREFIX",
 			"/usr/local",
 			"/usr",
 			"/opt",
@@ -1058,7 +1060,7 @@ static void ShowHelp()
 
 static void ShowVersion()
 {
-	printf("Eureka version " EUREKA_VERSION " (" __DATE__ ")\n");
+	printf("Eureka version " EUREKA_VERSION " (Reproducible build)\n");
 
 	fflush(stdout);
 }
