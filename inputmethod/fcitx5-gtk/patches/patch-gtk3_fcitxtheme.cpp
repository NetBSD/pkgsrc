$NetBSD: patch-gtk3_fcitxtheme.cpp,v 1.1 2022/12/02 18:06:53 nros Exp $

Add missing include so that std::min that takes an initializer list
is visible.
Taken from upstream:
https://github.com/fcitx/fcitx5-gtk/commit/54995987451b01d3a47e50edcd4f3339c18eb49c

--- gtk3/fcitxtheme.cpp.orig	2022-12-02 17:41:58.732569384 +0000
+++ gtk3/fcitxtheme.cpp
@@ -5,6 +5,7 @@
  *
  */
 #include "fcitxtheme.h"
+#include <algorithm>
 #include <cassert>
 #include <fcntl.h>
 #include <fmt/format.h>
