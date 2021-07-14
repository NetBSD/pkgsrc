$NetBSD: patch-clang__delta_Transformation.cpp,v 1.1 2021/07/14 09:08:49 wiz Exp $

Build fix for llvm 12.0.1 from https://github.com/csmith-project/creduce/tree/llvm-12.0-dev

--- clang_delta/Transformation.cpp.orig	2019-05-13 21:17:30.000000000 +0000
+++ clang_delta/Transformation.cpp
@@ -106,7 +106,7 @@ void Transformation::outputTransformedSo
 void Transformation::outputOriginalSource(llvm::raw_ostream &OutStream)
 {
   FileID MainFileID = SrcManager->getMainFileID();
-  const llvm::MemoryBuffer *MainBuf = SrcManager->getBuffer(MainFileID);
+  auto MainBuf = SrcManager->getBufferOrNone(MainFileID);
   TransAssert(MainBuf && "Empty MainBuf!");
   OutStream << MainBuf->getBufferStart();
   OutStream.flush();
@@ -357,7 +357,7 @@ unsigned int Transformation::getConstArr
   llvm::SmallString<8> IntStr;
   Result.toStringUnsigned(IntStr);
 
-  std::stringstream TmpSS(IntStr.str());
+  std::stringstream TmpSS(IntStr.str().str());
 
   if (!(TmpSS >> Sz)) {
     TransAssert(0 && "Non-integer value!");
