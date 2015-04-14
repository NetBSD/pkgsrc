$NetBSD: patch-src_python.c,v 1.1 2015/04/14 11:27:30 fhajny Exp $

Backport Python 3 fixes from upstream trunk.
https://github.com/collectd/collectd/pull/890
--- src/python.c.orig	2015-02-26 10:43:48.488180825 +0000
+++ src/python.c
@@ -988,13 +988,15 @@ PyMODINIT_FUNC PyInit_collectd(void) {
 #endif
 
 static int cpy_init_python() {
-	char *argv = "";
 	PyObject *sys;
 	PyObject *module;
 
 #ifdef IS_PY3K
+	wchar_t *argv = L"";
 	/* Add a builtin module, before Py_Initialize */
 	PyImport_AppendInittab("collectd", PyInit_collectd);
+#else
+	char *argv = "";
 #endif
 	
 	Py_Initialize();
@@ -1067,9 +1069,13 @@ static int cpy_config(oconfig_item_t *ci
 		} else if (strcasecmp(item->key, "Encoding") == 0) {
 			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_STRING)
 				continue;
+#ifdef IS_PY3K
+			NOTICE("python: \"Encoding\" was used in the config file but Python3 was used, which does not support changing encodings. Ignoring this.");
+#else
 			/* Why is this even necessary? And undocumented? */
 			if (PyUnicode_SetDefaultEncoding(item->values[0].value.string))
 				cpy_log_exception("setting default encoding");
+#endif
 		} else if (strcasecmp(item->key, "LogTraces") == 0) {
 			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN)
 				continue;
