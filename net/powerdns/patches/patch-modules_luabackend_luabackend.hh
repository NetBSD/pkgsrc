$NetBSD: patch-modules_luabackend_luabackend.hh,v 1.2 2015/03/27 23:37:52 rodent Exp $

u_int32_t not defined on SunOS.
--- modules/luabackend/luabackend.hh.orig	2015-03-02 13:17:08.000000000 +0000
+++ modules/luabackend/luabackend.hh
@@ -17,6 +17,9 @@ using std::string;
 
 //#undef L
 
+#ifdef __sun
+typedef uint32_t u_int32_t;
+#endif
 
 
 class LUAException {
