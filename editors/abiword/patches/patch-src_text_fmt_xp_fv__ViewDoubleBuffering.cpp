$NetBSD: patch-src_text_fmt_xp_fv__ViewDoubleBuffering.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/text/fmt/xp/fv_ViewDoubleBuffering.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/text/fmt/xp/fv_ViewDoubleBuffering.cpp
@@ -27,7 +27,7 @@
 #include "ut_misc.h"
 #include "ut_debugmsg.h"
 
-//#define DEACTIVATE_FV_VIEW_DOUBLE_BUFFERING
+//#define DEACTIVATE_FV_VIEW_DOUBLE_BUFFERING 1
 
 FV_ViewDoubleBuffering::FV_ViewDoubleBuffering(FV_View *pView, bool suspendDirectDrawing, bool callDrawOnlyAtTheEnd)
 	: m_pView(pView),
