$NetBSD: patch-src_sound_Pixtone.cpp,v 1.1 2020/09/30 08:07:57 nia Exp $

[PATCH] Fix buffer overflow

https://github.com/nxengine/nxengine-evo/commit/75b8b8e3b067fd354baa903332f2a3254d1cc017.patch

--- src/sound/Pixtone.cpp.orig	2019-04-08 14:37:06.000000000 +0000
+++ src/sound/Pixtone.cpp
@@ -17,6 +17,8 @@
 #include <cstdlib>
 #include <cstring>
 #include <functional>
+#include <iomanip>
+#include <sstream>
 #include <vector>
 
 // using std::fgetc;
@@ -274,7 +276,6 @@ bool Pixtone::init()
     wave[MOD_NOISE].table[i]   = (signed char)(seed >> 16) / 2;      // Pseudorandom
   }
 
-  char fname[80];
   uint32_t slot;
 
   stat("Loading Sound FX...");
@@ -282,10 +283,11 @@ bool Pixtone::init()
   std::string path = ResourceManager::getInstance()->getPathForDir("pxt/");
   for (slot = 1; slot <= NUM_SOUNDS; slot++)
   {
-    sprintf(fname, "%sfx%02x.pxt", path.c_str(), slot);
+    std::ostringstream filename;
+    filename << path << "fx" << std::hex << std::setw(2) << std::setfill('0') << slot << ".pxt";
     stPXSound snd;
 
-    if (!snd.load(fname))
+    if (!snd.load(filename.str()))
       continue;
     snd.render();
 
