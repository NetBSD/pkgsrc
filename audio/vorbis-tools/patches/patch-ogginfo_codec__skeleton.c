$NetBSD: patch-ogginfo_codec__skeleton.c,v 1.1 2024/06/18 08:49:34 markd Exp $

Include "utf8.h" for a prototype of the utf8_decode function.  This
avoids an implicit function declaration and build issues with future
compilers.
From Fedora

diff --git a/ogginfo/codec_skeleton.c b/ogginfo/codec_skeleton.c
index a27f8da8307872bb..0709860ab096c942 100644
--- ogginfo/codec_skeleton.c
+++ ogginfo/codec_skeleton.c
@@ -25,6 +25,7 @@
 #include <ogg/ogg.h>
 
 #include "i18n.h"
+#include "utf8.h"
 
 #include "private.h"
 
