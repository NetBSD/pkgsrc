$NetBSD: patch-apps_openmw_mwgui_videowidget.hpp,v 1.1 2019/08/09 16:26:09 nia Exp $

Always include <memory> for smart pointers in MWGui

Upstream commit:
https://github.com/OpenMW/openmw/commit/216e1ab16f88b9db6f8559bce2095e84c0ebbcbd.patch

--- apps/openmw/mwgui/videowidget.hpp.orig	2019-03-10 10:50:29.000000000 +0000
+++ apps/openmw/mwgui/videowidget.hpp
@@ -2,6 +2,7 @@
 #define OPENMW_MWGUI_VIDEOWIDGET_H
 
 #include <MyGUI_Widget.h>
+#include <memory>
 
 namespace Video
 {
