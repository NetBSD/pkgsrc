$NetBSD: patch-include_asterisk_utils.h,v 1.3 2015/08/09 04:07:13 jnemeth Exp $

--- include/asterisk/utils.h.orig	2015-06-04 00:44:42.000000000 +0000
+++ include/asterisk/utils.h
@@ -949,24 +949,9 @@ char *ast_utils_which(const char *binary
  * \encode
  */
 
-#if defined(__clang__)
-typedef void (^_raii_cleanup_block_t)(void);
-static inline void _raii_cleanup_block(_raii_cleanup_block_t *b) { (*b)(); }
-
-#define RAII_VAR(vartype, varname, initval, dtor)                                                                \
-    _raii_cleanup_block_t _raii_cleanup_ ## varname __attribute__((cleanup(_raii_cleanup_block),unused)) = NULL; \
-    __block vartype varname = initval;                                                                           \
-    _raii_cleanup_ ## varname = ^{ {(void)dtor(varname);} }
-
-#elif defined(__GNUC__)
-
-#define RAII_VAR(vartype, varname, initval, dtor)                              \
-    auto void _dtor_ ## varname (vartype * v);                                 \
-    void _dtor_ ## varname (vartype * v) { dtor(*v); }                         \
-    vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)
-
-#else
-    #error "Cannot compile Asterisk: unknown and unsupported compiler."
-#endif /* #if __GNUC__ */
-
+#define RAII_DECL(vartype, varname, dtor) \
+     static void _dtor_ ## varname (vartype * v) { dtor(*v); }
+#define RAII_VAR(vartype, varname, initval) \
+     vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)
+ 
 #endif /* _ASTERISK_UTILS_H */
