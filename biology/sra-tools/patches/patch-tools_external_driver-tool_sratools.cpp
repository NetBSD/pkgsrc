$NetBSD: patch-tools_external_driver-tool_sratools.cpp,v 1.1 2023/08/29 00:00:25 bacon Exp $

# Add NetBSD pthread_main_np() stand-in

--- tools/external/driver-tool/sratools.cpp.orig	2023-08-15 12:51:29.845642918 +0000
+++ tools/external/driver-tool/sratools.cpp
@@ -578,11 +578,20 @@ static int main(CommandLine const &argv)
 
 } // namespace sratools
 
+#ifdef __NetBSD__
+// Defined in sysmgr.c
+extern pthread_t       _ncbi_thr_main;
+#endif
+
 // BSD is defined when compiling on Mac
 // Use the MAC case below, not this one
 #if BSD && !MAC
 int main(int argc, char *argv[], char *envp[])
 {
+#ifdef __NetBSD__
+    _ncbi_thr_main = pthread_self();
+#endif
+
     auto const invocation = CommandLine(argc, argv, envp, nullptr);
     return sratools::main(invocation);
 }
