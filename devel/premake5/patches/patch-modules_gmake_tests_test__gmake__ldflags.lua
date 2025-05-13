$NetBSD: patch-modules_gmake_tests_test__gmake__ldflags.lua,v 1.1 2025/05/13 14:21:57 triaxx Exp $

Remove the hardcoded -L/usr/lib and -L/usr/lib64
This is not needed, and will cause issues:
https://github.com/gentoo/gentoo/pull/25825#issuecomment-1179497476

--- modules/gmake/tests/test_gmake_ldflags.lua.orig	2022-09-03 20:03:02.000000000 +0000
+++ modules/gmake/tests/test_gmake_ldflags.lua
@@ -56,7 +56,7 @@ ALL_LDFLAGS += $(LDFLAGS) -L../libs -Lli
 		system (p.LINUX)
 		prepare()
 		test.capture [[
-ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64
+ALL_LDFLAGS += $(LDFLAGS) -m64
 		]]
 	end
 
@@ -65,7 +65,7 @@ ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -
 		system (p.LINUX)
 		prepare()
 		test.capture [[
-ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -m32
+ALL_LDFLAGS += $(LDFLAGS) -m32
 		]]
 	end
 
