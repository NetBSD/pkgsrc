$NetBSD: patch-OgreMain_src_OgreStringConverter.cpp,v 1.1 2015/04/21 17:04:25 joerg Exp $

--- OgreMain/src/OgreStringConverter.cpp.orig	2015-04-17 11:32:19.000000000 +0000
+++ OgreMain/src/OgreStringConverter.cpp
@@ -64,7 +64,6 @@ namespace Ogre {
         return stream.str();
     }
     //-----------------------------------------------------------------------
-#if OGRE_ARCH_TYPE == OGRE_ARCHITECTURE_64 || OGRE_PLATFORM == OGRE_PLATFORM_APPLE    
     String StringConverter::toString(unsigned int val, 
         unsigned short width, char fill, std::ios::fmtflags flags)
     {
@@ -77,19 +76,6 @@ namespace Ogre {
         return stream.str();
     }
     //-----------------------------------------------------------------------
-    String StringConverter::toString(size_t val, 
-        unsigned short width, char fill, std::ios::fmtflags flags)
-    {
-        StringUtil::StrStreamType stream;
-        stream.width(width);
-        stream.fill(fill);
-        if (flags)
-            stream.setf(flags);
-        stream << val;
-        return stream.str();
-    }
-#if OGRE_COMPILER == OGRE_COMPILER_MSVC
-    //-----------------------------------------------------------------------
     String StringConverter::toString(unsigned long val, 
         unsigned short width, char fill, std::ios::fmtflags flags)
     {
@@ -101,11 +87,7 @@ namespace Ogre {
         stream << val;
         return stream.str();
     }
-
-#endif
-    //-----------------------------------------------------------------------
-#else
-    String StringConverter::toString(size_t val, 
+    String StringConverter::toString(long val, 
         unsigned short width, char fill, std::ios::fmtflags flags)
     {
         StringUtil::StrStreamType stream;
@@ -117,20 +99,18 @@ namespace Ogre {
         return stream.str();
     }
     //-----------------------------------------------------------------------
-    String StringConverter::toString(unsigned long val, 
+    String StringConverter::toString(unsigned long long val, 
         unsigned short width, char fill, std::ios::fmtflags flags)
     {
         StringUtil::StrStreamType stream;
-		stream.width(width);
+        stream.width(width);
         stream.fill(fill);
         if (flags)
             stream.setf(flags);
         stream << val;
         return stream.str();
     }
-    //-----------------------------------------------------------------------
-#endif
-    String StringConverter::toString(long val, 
+    String StringConverter::toString(long long val, 
         unsigned short width, char fill, std::ios::fmtflags flags)
     {
         StringUtil::StrStreamType stream;
