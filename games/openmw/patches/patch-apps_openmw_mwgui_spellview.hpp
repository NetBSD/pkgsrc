$NetBSD: patch-apps_openmw_mwgui_spellview.hpp,v 1.1 2019/08/09 16:26:09 nia Exp $

Always include <memory> for smart pointers in MWGui

Upstream commit:
https://github.com/OpenMW/openmw/commit/216e1ab16f88b9db6f8559bce2095e84c0ebbcbd.patch

--- apps/openmw/mwgui/spellview.hpp.orig	2019-03-10 10:50:29.000000000 +0000
+++ apps/openmw/mwgui/spellview.hpp
@@ -1,6 +1,7 @@
 #ifndef OPENMW_GUI_SPELLVIEW_H
 #define OPENMW_GUI_SPELLVIEW_H
 
+#include <memory>
 #include <tuple>
 
 #include <MyGUI_Widget.h>
