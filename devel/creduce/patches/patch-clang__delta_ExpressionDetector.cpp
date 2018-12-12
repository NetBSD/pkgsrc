$NetBSD: patch-clang__delta_ExpressionDetector.cpp,v 1.1 2018/12/12 12:44:43 adam Exp $

Fix for LLVM 7.0.
https://github.com/csmith-project/creduce/tree/llvm-7.0

--- clang_delta/ExpressionDetector.cpp.orig	2018-12-12 12:34:31.000000000 +0000
+++ clang_delta/ExpressionDetector.cpp
@@ -63,7 +63,8 @@ public:
                           StringRef FileName, bool IsAngled,
                           CharSourceRange FilenameRange, const FileEntry *File,
                           StringRef SearchPath, StringRef RelativePath,
-                          const Module *Imported) override;
+                          const Module *Imported,
+                          SrcMgr::CharacteristicKind FileType) override;
 
 private:
   SourceManager &SrcManager;
@@ -83,7 +84,8 @@ void IncludesPPCallbacks::InclusionDirec
                                             const FileEntry * /*File*/,
                                             StringRef /*SearchPath*/,
                                             StringRef /*RelativePath*/,
-                                            const Module * /*Imported*/)
+                                            const Module * /*Imported*/,
+                                            SrcMgr::CharacteristicKind /*FileType*/)
 {
   if (!SrcManager.isInMainFile(HashLoc))
     return;
