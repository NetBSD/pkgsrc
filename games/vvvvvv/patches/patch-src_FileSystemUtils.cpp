$NetBSD: patch-src_FileSystemUtils.cpp,v 1.1 2020/01/10 18:27:18 nia Exp $

Support non-Linux

--- src/FileSystemUtils.cpp.orig	2020-01-10 16:45:29.000000000 +0000
+++ src/FileSystemUtils.cpp
@@ -14,7 +14,7 @@
 #include <shlobj.h>
 #define mkdir(a, b) CreateDirectory(a, NULL)
 #define VNEEDS_MIGRATION (mkdirResult != 0)
-#elif defined(__linux__) || defined(__APPLE__)
+#elif defined(__unix__) || defined(__APPLE__)
 #include <sys/stat.h>
 #include <limits.h>
 #define VNEEDS_MIGRATION (mkdirResult == 0)
@@ -141,7 +141,13 @@ std::vector<std::string> FILESYSTEM_getL
 
 void PLATFORM_getOSDirectory(char* output)
 {
-#if defined(__linux__)
+#if defined(__APPLE__)
+	strcpy(output, PHYSFS_getUserDir());
+	strcat(output, "Library/Application Support/VVVVVV/");
+#elif defined(_WIN32)
+	SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, output);
+	strcat(output, "\\VVVVVV\\");
+#else
 	const char *homeDir = getenv("XDG_DATA_HOME");
 	if (homeDir == NULL)
 	{
@@ -153,14 +159,6 @@ void PLATFORM_getOSDirectory(char* outpu
 		strcpy(output, homeDir);
 		strcat(output, "/VVVVVV/");
 	}
-#elif defined(__APPLE__)
-	strcpy(output, PHYSFS_getUserDir());
-	strcat(output, "Library/Application Support/VVVVVV/");
-#elif defined(_WIN32)
-	SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, output);
-	strcat(output, "\\VVVVVV\\");
-#else
-#error See PLATFORM_getOSDirectory
 #endif
 }
 
@@ -169,7 +167,7 @@ void PLATFORM_migrateSaveData(char* outp
 	char oldLocation[MAX_PATH];
 	char newLocation[MAX_PATH];
 	char oldDirectory[MAX_PATH];
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__) || defined(__APPLE__)
 	DIR *dir = NULL;
 	struct dirent *de = NULL;
 	DIR *subDir = NULL;
@@ -182,10 +180,10 @@ void PLATFORM_migrateSaveData(char* outp
 		return;
 	}
 	strcpy(oldDirectory, homeDir);
-#if defined(__linux__)
-	strcat(oldDirectory, "/.vvvvvv/");
-#elif defined(__APPLE__)
+#if defined(__APPLE__)
 	strcat(oldDirectory, "/Documents/VVVVVV/");
+#else
+	strcat(oldDirectory, "/.vvvvvv/");
 #endif
 	dir = opendir(oldDirectory);
 	if (!dir)
