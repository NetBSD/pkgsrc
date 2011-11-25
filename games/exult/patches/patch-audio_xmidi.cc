$NetBSD: patch-audio_xmidi.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- audio/xmidi.cc.orig	2011-11-25 17:44:45.000000000 +0000
+++ audio/xmidi.cc
@@ -26,6 +26,7 @@
 #ifndef ALPHA_LINUX_CXX
 #  include <cassert>
 #  include <cstdio>
+#  include <cstdlib>
 #  include <cmath>
 #  include <iostream>
 #  include <cmath>
