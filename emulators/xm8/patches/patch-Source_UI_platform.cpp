$NetBSD: patch-Source_UI_platform.cpp,v 1.1 2019/09/07 00:36:34 tsutsui Exp $

- add NetBSD denitions

--- Source/UI/platform.cpp.orig	2017-12-30 13:04:42.000000000 +0000
+++ Source/UI/platform.cpp
@@ -22,15 +22,15 @@
 #include "converter.h"
 #include "platform.h"
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if defined(UNIX) && !defined(__ANDROID__)
 #include <locale.h>
-#endif // __linux__ && !__ANDROID__
+#endif // UNIX && !__ANDROID__
 
-#ifdef __linux__
+#if defined(UNIX)
 #include <dirent.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#endif // __linux__
+#endif // UNIX
 
 //
 // defines
@@ -63,11 +63,11 @@ Platform::Platform(App *a)
 	ImmDisableIME((DWORD)-1);
 #endif // _WIN32
 
-#ifdef __linux__
+#if defined(UNIX)
 	dir_handle = NULL;
 	dir_name[0] = '\0';
 	dir_up = false;
-#endif // __linux__
+#endif // UNIX
 }
 
 //
@@ -144,7 +144,7 @@ bool Platform::Init(SDL_Window *window)
 	}
 #endif // _WIN32 && UNICODE
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if defined(UNIX) && !defined(__ANDROID__)
 	char *opaque;
 
 	// set locale to UTF-8
@@ -155,7 +155,7 @@ bool Platform::Init(SDL_Window *window)
 			opaque = setlocale(LC_CTYPE, LOCALE_UTF8);
 		}
 	}
-#endif // __linux__ && !__ANDROID__
+#endif // UNIX && !__ANDROID__
 
 	return true;
 }
@@ -186,12 +186,12 @@ void Platform::Deinit()
 	}
 #endif // _WIN32
 
-#ifdef __linux__
+#if defined(UNIX)
 	if (dir_handle != NULL) {
 		closedir((DIR*)dir_handle);
 		dir_handle = NULL;
 	}
-#endif // __linux__
+#endif // UNIX
 }
 
 //
@@ -282,7 +282,7 @@ const char* Platform::FindFirst(const ch
 	return NULL;
 #endif // _WIN32 && UNICODE
 
-#ifdef __linux__
+#if defined(UNIX)
 	DIR *dir_ret;
 
 	// Find ..
@@ -306,7 +306,7 @@ const char* Platform::FindFirst(const ch
 
 	// find next
 	return FindNext(info);
-#endif // __liunx__
+#endif // UNIX
 }
 
 //
@@ -384,7 +384,7 @@ const char* Platform::FindNext(Uint32 *i
 	return NULL;
 #endif // _WIN32 && UNICODE
 
-#ifdef __linux__
+#if defined(UNIX)
 	struct dirent *entry;
 	Converter *converter;
 
@@ -420,10 +420,10 @@ const char* Platform::FindNext(Uint32 *i
 	*info = (Uint32)entry->d_type;
 
 	return dir_name;
-#endif // __liunx__
+#endif // UNIX
 }
 
-#ifdef __linux__
+#if defined(UNIX)
 //
 // FindUp()
 // find ..
@@ -464,7 +464,7 @@ bool Platform::FindUp(const char *dir)
 	closedir(dir_ret);
 	return false;
 }
-#endif // __liunx__
+#endif // UNIX
 
 //
 // IsDir()
@@ -487,14 +487,14 @@ bool Platform::IsDir(Uint32 info)
 	}
 #endif // _WIN32
 
-#ifdef __linux__
+#if defined(UNIX)
 	if (info == DT_DIR) {
 		return true;
 	}
 	else {
 		return false;
 	}
-#endif // __linux__
+#endif // UNIX
 }
 
 //
@@ -557,7 +557,7 @@ bool Platform::MakePath(char *dir, const
 	return true;
 #endif // _WIN32 && UNICODE
 
-#ifdef __linux__
+#if defined(UNIX)
 	Converter *converter;
 	struct stat filestat;
 
@@ -588,7 +588,7 @@ bool Platform::MakePath(char *dir, const
 	strcpy(dir, dir_name);
 
 	return true;
-#endif // __linux__
+#endif // UNIX
 }
 
 //
@@ -637,7 +637,7 @@ bool Platform::GetFileDateTime(const cha
 	return false;
 #endif // _WIN32
 
-#ifdef __linux__
+#if defined(UNIX)
 	struct stat filestat;
 	time_t timep;
 	struct tm local_time;
@@ -660,7 +660,7 @@ bool Platform::GetFileDateTime(const cha
 	}
 
 	return false;
-#endif // __linux__
+#endif // UNIX
 }
 
 //
@@ -696,7 +696,7 @@ void Platform::MsgBox(SDL_Window *window
 	}
 #endif // _WIN32
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if defined(UNIX) && !defined(__ANDROID__)
 	SDL_MessageBoxData data;
 	SDL_MessageBoxButtonData button;
 	int retid;
@@ -718,7 +718,7 @@ void Platform::MsgBox(SDL_Window *window
 
 	// show modal message box
 	SDL_ShowMessageBox(&data, &retid);
-#endif // __linux__ && !__ANDROID__
+#endif // UNIX && !__ANDROID__
 }
 
 //
