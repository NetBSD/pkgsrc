$NetBSD: patch-source_Files.cpp,v 1.1 2020/07/26 05:21:20 dholland Exp $

Fix the logic for finding the game data.

--- source/Files.cpp~	2020-05-01 19:02:38.000000000 +0000
+++ source/Files.cpp
@@ -102,20 +102,32 @@ void Files::Init(const char * const *arg
 		// Find the path to the resource directory. This will depend on the
 		// operating system, and can be overridden by a command line argument.
 		char *str = SDL_GetBasePath();
-		if(!str)
-			throw runtime_error("Unable to get path to resource directory!");
-		
-		resources = str;
-		SDL_free(str);
+		if(str)
+		{
+			resources = str;
+			SDL_free(str);
+		}
+		else
+		{
+#ifdef BINDIR
+			// SDL_GetBasePath fails on some systems if e.g. /proc isn't mounted.
+			// Compile in the installation path as a fallback.
+			resources = BINDIR "/";
+#else
+			throw runtime_error("Unable to get path to resource directory! (use -r)");
+#endif
+		}
 	}
 #if defined _WIN32
 	FixWindowsSlashes(resources);
 #endif
 	if(resources.back() != '/')
 		resources += '/';
-#if defined __linux__ || defined __FreeBSD__ || defined __DragonFly__
+#if defined __linux__ || defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__ || defined __OpenBSD__
 	// Special case, for Linux: the resource files are not in the same place as
 	// the executable, but are under the same prefix (/usr or /usr/local).
+	// ...or /usr/pkg or /usr/contrib or /opt or...
+#if 0
 	static const string LOCAL_PATH = "/usr/local/";
 	static const string STANDARD_PATH = "/usr/";
 	static const string RESOURCE_PATH = "share/games/endless-sky/";
@@ -123,6 +135,10 @@ void Files::Init(const char * const *arg
 		resources = LOCAL_PATH + RESOURCE_PATH;
 	else if(!resources.compare(0, STANDARD_PATH.length(), STANDARD_PATH))
 		resources = STANDARD_PATH + RESOURCE_PATH;
+#else
+	static const string RESOURCE_PATH = "share/games/endless-sky/";
+	resources = resources + "../" + RESOURCE_PATH;
+#endif /* 0 */
 #elif defined __APPLE__
 	// Special case for Mac OS X: the resources are in ../Resources relative to
 	// the folder the binary is in.
