$NetBSD: patch-OgreMain_include_OgreStringConverter.h,v 1.1 2015/04/21 17:04:25 joerg Exp $

--- OgreMain/include/OgreStringConverter.h.orig	2015-04-17 11:25:21.000000000 +0000
+++ OgreMain/include/OgreStringConverter.h
@@ -80,34 +80,24 @@ namespace Ogre {
         static String toString(int val, unsigned short width = 0, 
             char fill = ' ', 
             std::ios::fmtflags flags = std::ios::fmtflags(0) );
-#if OGRE_ARCH_TYPE == OGRE_ARCHITECTURE_64 || OGRE_PLATFORM == OGRE_PLATFORM_APPLE
         /** Converts an unsigned int to a String. */
         static String toString(unsigned int val, 
             unsigned short width = 0, char fill = ' ', 
             std::ios::fmtflags flags = std::ios::fmtflags(0) );
-        /** Converts a size_t to a String. */
-        static String toString(size_t val, 
-            unsigned short width = 0, char fill = ' ', 
-            std::ios::fmtflags flags = std::ios::fmtflags(0) );
-        #if OGRE_COMPILER == OGRE_COMPILER_MSVC
-                /** Converts an unsigned long to a String. */
-                static String toString(unsigned long val, 
-                    unsigned short width = 0, char fill = ' ', 
-                    std::ios::fmtflags flags = std::ios::fmtflags(0) );
-
-        #endif
-#else
-        /** Converts a size_t to a String. */
-        static String toString(size_t val, 
+        /** Converts a long to a String. */
+        static String toString(long val, 
             unsigned short width = 0, char fill = ' ', 
             std::ios::fmtflags flags = std::ios::fmtflags(0) );
         /** Converts an unsigned long to a String. */
         static String toString(unsigned long val, 
             unsigned short width = 0, char fill = ' ', 
             std::ios::fmtflags flags = std::ios::fmtflags(0) );
-#endif
         /** Converts a long to a String. */
-        static String toString(long val, 
+        static String toString(long long val, 
+            unsigned short width = 0, char fill = ' ', 
+            std::ios::fmtflags flags = std::ios::fmtflags(0) );
+        /** Converts an unsigned long to a String. */
+        static String toString(unsigned long long val, 
             unsigned short width = 0, char fill = ' ', 
             std::ios::fmtflags flags = std::ios::fmtflags(0) );
         /** Converts a boolean to a String. 
