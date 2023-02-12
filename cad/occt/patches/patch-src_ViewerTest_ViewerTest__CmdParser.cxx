$NetBSD: patch-src_ViewerTest_ViewerTest__CmdParser.cxx,v 1.1 2023/02/12 14:42:25 tnn Exp $

Just use SIZE_MAX instead of C++20 std::numeric_limits to help
with older compilers.

--- src/ViewerTest/ViewerTest_CmdParser.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/ViewerTest/ViewerTest_CmdParser.cxx
@@ -50,7 +50,11 @@ namespace
 
 } // namespace
 
+#ifdef SIZE_MAX
+const std::size_t ViewerTest_CmdParser::THE_UNNAMED_COMMAND_OPTION_KEY = SIZE_MAX;
+#else
 const std::size_t ViewerTest_CmdParser::THE_UNNAMED_COMMAND_OPTION_KEY = (std::numeric_limits<std::size_t>::max)();
+#endif
 
 const std::size_t ViewerTest_CmdParser::THE_HELP_COMMAND_OPTION_KEY = 0;
 
