$NetBSD: patch-src_pstoedit.cpp,v 1.1 2016/08/22 11:20:56 markd Exp $

Upstream patch for not finding plugins.

--- src/pstoedit.cpp.orig	2014-09-04 18:21:45.000000000 +0000
+++ src/pstoedit.cpp
@@ -30,6 +30,7 @@
 #include I_string_h
 
 #include <assert.h>
+#include <sys/stat.h>
 
 #include "pstoeditoptions.h"
 
@@ -261,33 +262,33 @@ static void loadpstoeditplugins(const ch
 		loadPlugInDrivers(plugindir.c_str(), errstream, verbose);	// load the driver plugins
 		pluginsloaded = true;
 	}
-	// also look in the directory where the pstoedit .exe/dll was found
-	char szExePath[1000];
-	szExePath[0] = '\0';
-	const unsigned long r = P_GetPathToMyself(progname, szExePath, sizeof(szExePath));
-	if (verbose)  errstream << "pstoedit : path to myself:" << progname << " " << r << " " << szExePath<< endl;
-	char *p = 0;
-	if (r && (p = strrchr(szExePath, directoryDelimiter)) != 0) {
-		*p = '\0';
-		if (!strequal(szExePath, plugindir.c_str())) {
-			loadPlugInDrivers(szExePath, errstream,verbose);
-			pluginsloaded = true;
-		}
-	}
-	// now try also $exepath/../lib/pstoedit
-	strcat_s(szExePath,1000,"/../lib/pstoedit");
-	if (!strequal(szExePath, plugindir.c_str())) {
-    	loadPlugInDrivers(szExePath, errstream,verbose);
-		pluginsloaded = true;
-	}
-
 #ifdef PSTOEDITLIBDIR
-	if (!pluginsloaded) {
+	struct stat s;
+	if (!pluginsloaded &&
+	    !stat(PSTOEDITLIBDIR, &s) &&
+	    S_ISDIR(s.st_mode)) {
   	  // also try to load drivers from the PSTOEDITLIBDIR
 	  loadPlugInDrivers(PSTOEDITLIBDIR, errstream,verbose);
 	  pluginsloaded = true;
 	}
 #endif
+	// If the above failed, also look in the directory where the pstoedit .exe/dll was found
+	if (!pluginsloaded) {
+	  char szExePath[1000];
+	  szExePath[0] = '\0';
+	  const unsigned long r = P_GetPathToMyself(progname, szExePath, sizeof(szExePath));
+	  if (verbose)  errstream << "pstoedit : path to myself:" << progname << " " << r << " " << szExePath<< endl;
+	  char *p = 0;
+	  if (r && (p = strrchr(szExePath, directoryDelimiter)) != 0) {
+		*p = '\0';
+		loadPlugInDrivers(szExePath, errstream,verbose);
+	  }
+	  // now try also $exepath/../lib/pstoedit
+	  strcat_s(szExePath,1000,"/../lib/pstoedit");
+	  if (!strequal(szExePath, plugindir.c_str())) {
+	  loadPlugInDrivers(szExePath, errstream,verbose);
+	  }
+	}
 
 	// delete[]plugindir;
 }
