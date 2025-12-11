$NetBSD: patch-src_libs_loguru_loguru.cpp,v 1.1 2025/12/11 20:08:51 vins Exp $

Portability fix for pthread_setname_np(3) and pthread_self(3) on NetBSD. 

--- src/libs/loguru/loguru.cpp.orig	2025-06-17 09:01:32.000000000 +0000
+++ src/libs/loguru/loguru.cpp
@@ -670,6 +670,8 @@ namespace loguru
 						pthread_set_name_np(this_thread, main_thread_name);
 					#elif defined(__linux__) || defined(__sun)
 						pthread_setname_np(this_thread, main_thread_name);
+					#elif defined(__NetBSD)
+						pthread_setname_np(this_thread, "%s", (gchar *) main_thread_name);
 					#else
 						// platforms that we don't know how to set the name on
 						(void)this_thread; // unused
@@ -1089,6 +1091,8 @@ namespace loguru
 				pthread_set_name_np(pthread_self(), name);
 			#elif defined(__linux__) || defined(__sun)
 				pthread_setname_np(pthread_self(), name);
+			#elif defined(__NetBSD)
+				pthread_setname_np(pthread_self(), "%s", (gchar *) name);
 			#else
 				// Platforms that may not support setting a thread name
 				(void)name; // unused
@@ -1120,7 +1124,7 @@ namespace loguru
 			// This is what we *want* to do on all platforms, but
 			// only some platforms support it (currently).
 
-			#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__linux__) || defined(__sun)
+			#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__linux__) || defined(__sun) || defined(__NetBSD__)
 				pthread_getname_np(pthread_self(), buffer, length);
 			#elif defined(__OpenBSD__)
 				pthread_get_name_np(pthread_self(), buffer, length);
@@ -1156,7 +1160,7 @@ namespace loguru
 				const auto pthread_self_is_pointer = std::is_pointer<decltype(native_id)>::value;
 				const auto thread_id = pthread_self_is_pointer
 				                           ? reinterpret_cast<uintptr_t>((void*)native_id)
-				#if defined(__OpenBSD__)
+				#if defined(__OpenBSD__) || defined(__NetBSD__)
 				                           : reinterpret_cast<uintptr_t>(native_id);
 				#else
 				                           : static_cast<uintptr_t>(native_id);
