$NetBSD: patch-src_texture.cpp,v 1.1 2013/03/02 18:08:03 joerg Exp $

--- src/texture.cpp.orig	2013-02-27 21:21:04.000000000 +0000
+++ src/texture.cpp
@@ -5,6 +5,7 @@
  *      Author: krzysztof
  */
 #include <stdio.h>
+#include <cstring>
 #include "texture.hpp"
 #include "files.h"
 
