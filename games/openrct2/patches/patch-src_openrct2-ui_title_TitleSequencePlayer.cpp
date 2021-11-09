$NetBSD: patch-src_openrct2-ui_title_TitleSequencePlayer.cpp,v 1.1 2021/11/09 11:36:08 nia Exp $

Fix building on NetBSD/current.
"error: 'runtime_error' is not a member of 'std'"

--- src/openrct2-ui/title/TitleSequencePlayer.cpp.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2-ui/title/TitleSequencePlayer.cpp
@@ -13,6 +13,7 @@
 
 #include <algorithm>
 #include <memory>
+#include <stdexcept>
 #include <openrct2/Context.h>
 #include <openrct2/Game.h>
 #include <openrct2/GameState.h>
