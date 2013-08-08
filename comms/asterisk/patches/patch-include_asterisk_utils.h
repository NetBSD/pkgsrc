$NetBSD: patch-include_asterisk_utils.h,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- include/asterisk/utils.h.orig	2013-04-30 13:46:53.000000000 +0000
+++ include/asterisk/utils.h
@@ -926,10 +926,9 @@ char *ast_utils_which(const char *binary
  * }
  * \encode
  */
-#define RAII_VAR(vartype, varname, initval, dtor) \
-    /* Prototype needed due to http://gcc.gnu.org/bugzilla/show_bug.cgi?id=36774 */ \
-    auto void _dtor_ ## varname (vartype * v); \
-    void _dtor_ ## varname (vartype * v) { dtor(*v); } \
+#define RAII_DECL(vartype, varname, dtor) \
+    static void _dtor_ ## varname (vartype * v) { dtor(*v); }
+#define RAII_VAR(vartype, varname, initval) \
     vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)
 
 #endif /* _ASTERISK_UTILS_H */
