$NetBSD: patch-include_asterisk_utils.h,v 1.2 2015/05/19 07:52:14 jnemeth Exp $

--- include/asterisk/utils.h.orig	2015-03-12 12:26:57.000000000 +0000
+++ include/asterisk/utils.h
@@ -943,30 +943,9 @@ char *ast_utils_which(const char *binary
  * \encode
  */
 
-#if defined(__clang__)
-
-#if defined(__has_feature) && __has_feature(blocks)
-typedef void (^_raii_cleanup_block_t)(void);
-static inline void _raii_cleanup_block(_raii_cleanup_block_t *b) { (*b)(); }
-
-#define RAII_VAR(vartype, varname, initval, dtor)                                                                \
-    _raii_cleanup_block_t _raii_cleanup_ ## varname __attribute__((cleanup(_raii_cleanup_block),unused)) = NULL; \
-    vartype varname = initval;                                                                                   \
-    _raii_cleanup_ ## varname = ^{ dtor(varname); }
-
-#else
-	#error "CLANG must support the 'blocks' feature to compile Asterisk."
-#endif /* #if defined(__has_feature) && __has_feature(blocks) */
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
