$NetBSD: patch-libskk_state.c,v 1.2 2013/01/25 12:07:13 obache Exp $

--- libskk/state.c.orig	2012-08-27 02:38:28.000000000 +0000
+++ libskk/state.c
@@ -1560,7 +1560,7 @@ static gchar* skk_state_expand_numeric_r
 					GError* e = NULL;
 					e = _inner_error_;
 					_inner_error_ = NULL;
-					g_return_if_reached ();
+					g_return_val_if_reached (0);
 					_g_error_free0 (e);
 				}
 				__finally33:
