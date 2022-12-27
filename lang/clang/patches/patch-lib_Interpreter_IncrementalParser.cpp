$NetBSD: patch-lib_Interpreter_IncrementalParser.cpp,v 1.1 2022/12/27 10:49:42 he Exp $

NetBSD doesn't have ENOTRECOVERABLE, so doesn't have
std::errc::state_not_recoverable either.  Use
std::errc::operation_not_supported instead.

--- lib/Interpreter/IncrementalParser.cpp.orig	2022-11-16 06:28:29.000000000 +0000
+++ lib/Interpreter/IncrementalParser.cpp
@@ -53,7 +53,7 @@ public:
           switch (CI.getFrontendOpts().ProgramAction) {
           default:
             Err = llvm::createStringError(
-                std::errc::state_not_recoverable,
+                std::errc::operation_not_supported,
                 "Driver initialization failed. "
                 "Incremental mode for action %d is not supported",
                 CI.getFrontendOpts().ProgramAction);
