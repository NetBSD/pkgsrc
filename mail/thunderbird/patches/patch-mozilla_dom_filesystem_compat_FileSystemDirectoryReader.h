$NetBSD: patch-mozilla_dom_filesystem_compat_FileSystemDirectoryReader.h,v 1.1 2017/04/27 13:32:40 ryoon Exp $

--- mozilla/dom/filesystem/compat/FileSystemDirectoryReader.h.orig	2017-04-14 04:53:05.000000000 +0000
+++ mozilla/dom/filesystem/compat/FileSystemDirectoryReader.h
@@ -11,6 +11,7 @@
 #include "mozilla/ErrorResult.h"
 #include "mozilla/dom/BindingDeclarations.h"
 #include "nsCycleCollectionParticipant.h"
+#include "mozilla/dom/FileSystemDirectoryEntry.h"
 #include "nsWrapperCache.h"
 
 namespace mozilla {
