$NetBSD: patch-src_dict_mapped__file.cc,v 1.1 2018/03/07 09:34:09 wiz Exp $

Return bool where the return value type needs it.

--- src/dict/mapped_file.cc.orig	2013-11-10 10:20:21.000000000 +0000
+++ src/dict/mapped_file.cc
@@ -106,7 +106,7 @@ bool MappedFile::Create(size_t capacity)
   LOG(INFO) << "opening file for read/write access.";
   file_.reset(new MappedFileImpl(file_name_, MappedFileImpl::kOpenReadWrite));
   size_ = 0;
-  return file_;
+  return file_ != NULL;
 }
 
 bool MappedFile::OpenReadOnly() {
@@ -116,7 +116,7 @@ bool MappedFile::OpenReadOnly() {
   }
   file_.reset(new MappedFileImpl(file_name_, MappedFileImpl::kOpenReadOnly));
   size_ = file_->get_size();
-  return file_;
+  return file_ != NULL;
 }
 
 bool MappedFile::OpenReadWrite() {
@@ -126,7 +126,7 @@ bool MappedFile::OpenReadWrite() {
   }
   file_.reset(new MappedFileImpl(file_name_, MappedFileImpl::kOpenReadWrite));
   size_ = 0;
-  return file_;
+  return file_ != NULL;
 }
 
 void MappedFile::Close() {
@@ -137,7 +137,7 @@ void MappedFile::Close() {
 }
 
 bool MappedFile::IsOpen() const {
-  return file_;
+  return file_ != NULL;
 }
 
 bool MappedFile::Flush() {
