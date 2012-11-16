$NetBSD: patch-libskk_state.c,v 1.1 2012/11/16 01:02:54 joerg Exp $

--- libskk/state.c.orig	2012-07-02 02:12:19.000000000 +0000
+++ libskk/state.c
@@ -2085,7 +2085,7 @@ static gchar* skk_state_expand_numeric_r
 #line 263 "/home/ueno/devel/libskk/libskk/state.vala"
 					_inner_error_ = NULL;
 #line 272 "/home/ueno/devel/libskk/libskk/state.vala"
-					g_return_if_reached ();
+					g_return_val_if_reached (0);
 #line 263 "/home/ueno/devel/libskk/libskk/state.vala"
 					_g_error_free0 (e);
 #line 2092 "state.c"
