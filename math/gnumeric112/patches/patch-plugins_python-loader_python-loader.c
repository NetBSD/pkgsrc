$NetBSD: patch-plugins_python-loader_python-loader.c,v 1.1 2019/01/15 12:05:56 wiz Exp $

python-loader.c:227:3: error: non-void function 'gplp_func_file_probe' should return a value [-Wreturn-type]
https://gitlab.gnome.org/GNOME/gnumeric/issues/379

--- plugins/python-loader/python-loader.c.orig	2018-11-24 17:05:48.000000000 +0000
+++ plugins/python-loader/python-loader.c
@@ -224,7 +224,9 @@ gplp_func_file_probe (G_GNUC_UNUSED GOFi
 	g_return_val_if_fail (input != NULL, FALSE);
 	if (_PyGObject_API == NULL) {
 		pygobject_init (3, 0, 0);
-		g_return_if_fail (_PyGObject_API != NULL);
+		if (_PyGObject_API == NULL) {
+			return FALSE;
+		}
 	}
 
 	loader_data = g_object_get_data (G_OBJECT (service), "loader_data");
