$NetBSD: patch-audio_hufftable.cpp,v 1.1 2019/11/23 23:03:01 nia Exp $

Fix build with GCC >= 6.

--- audio/hufftable.cpp.orig	2019-11-23 22:30:57.000000000 +0000
+++ audio/hufftable.cpp
@@ -9,6 +9,8 @@
 #include "config.h"
 #endif
 
+#include <climits>
+
 #include "MPEGaudio.h"
 
 static const unsigned int
@@ -550,11 +552,11 @@ htd33[ 31][2]={{ 16,  1},{  8,  1},{  4,
 
 const HUFFMANCODETABLE MPEGaudio::ht[HTN]=
 {
-  { 0, 0-1, 0-1, 0,  0, htd33},
+  { 0, UINT_MAX, UINT_MAX, 0,  0, htd33},
   { 1, 2-1, 2-1, 0,  7,htd01},
   { 2, 3-1, 3-1, 0, 17,htd02},
   { 3, 3-1, 3-1, 0, 17,htd03},
-  { 4, 0-1, 0-1, 0,  0, htd33},
+  { 4, UINT_MAX, UINT_MAX, 0,  0, htd33},
   { 5, 4-1, 4-1, 0, 31,htd05},
   { 6, 4-1, 4-1, 0, 31,htd06},
   { 7, 6-1, 6-1, 0, 71,htd07},
@@ -564,7 +566,7 @@ const HUFFMANCODETABLE MPEGaudio::ht[HTN
   {11, 8-1, 8-1, 0,127,htd11},
   {12, 8-1, 8-1, 0,127,htd12},
   {13,16-1,16-1, 0,511,htd13},
-  {14, 0-1, 0-1, 0,  0, htd33},
+  {14, UINT_MAX, UINT_MAX, 0,  0, htd33},
   {15,16-1,16-1, 0,511,htd15},
   {16,16-1,16-1, 1,511,htd16},
   {17,16-1,16-1, 2,511,htd16},
