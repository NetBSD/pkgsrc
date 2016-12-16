$NetBSD: patch-services_plugins_dndcp_dndUIX11.cpp,v 1.1 2016/12/16 00:04:03 joerg Exp $

Avoid User-defined Literals in C++11.

--- services/plugins/dndcp/dndUIX11.cpp.orig	2016-12-15 15:03:55.031323362 +0000
+++ services/plugins/dndcp/dndUIX11.cpp
@@ -128,7 +128,7 @@ DnDUIX11::~DnDUIX11()
        && !mHGStagingDir.empty()) {
       uint64 totalSize = File_GetSizeEx(mHGStagingDir.c_str());
       if (mTotalFileSize != totalSize) {
-         g_debug("%s: deleting %s, expecting %"FMT64"d, finished %"FMT64"d\n",
+         g_debug("%s: deleting %s, expecting %" FMT64 "d, finished %" FMT64 "d\n",
                  __FUNCTION__, mHGStagingDir.c_str(),
                  mTotalFileSize, totalSize);
          DnD_DeleteStagingFiles(mHGStagingDir.c_str(), FALSE);
@@ -1125,14 +1125,14 @@ DnDUIX11::OnGtkDragDataGet(
 
    if (   TargetIsPlainText(target)
        && CPClipboard_GetItem(&mClipboard, CPFORMAT_TEXT, &buf, &sz)) {
-      g_debug("%s: providing plain text, size %"FMTSZ"u\n", __FUNCTION__, sz);
+      g_debug("%s: providing plain text, size %" FMTSZ "u\n", __FUNCTION__, sz);
       selection_data.set(target.c_str(), (const char *)buf);
       return;
    }
 
    if (   TargetIsRichText(target)
        && CPClipboard_GetItem(&mClipboard, CPFORMAT_RTF, &buf, &sz)) {
-      g_debug("%s: providing rtf text, size %"FMTSZ"u\n", __FUNCTION__, sz);
+      g_debug("%s: providing rtf text, size %" FMTSZ "u\n", __FUNCTION__, sz);
       selection_data.set(target.c_str(), (const char *)buf);
       return;
    }
@@ -1457,7 +1457,7 @@ DnDUIX11::SetCPClipboardFromGtk(const Gt
           && source.size() < DNDMSG_MAX_ARGSZ
           && CPClipboard_SetItem(&mClipboard, CPFORMAT_TEXT, source.c_str(),
                                  source.size() + 1)) {
-         g_debug("%s: Got text, size %"FMTSZ"u\n", __FUNCTION__, source.size());
+         g_debug("%s: Got text, size %" FMTSZ "u\n", __FUNCTION__, source.size());
       } else {
          g_debug("%s: Failed to get text\n", __FUNCTION__);
          return false;
@@ -1473,7 +1473,7 @@ DnDUIX11::SetCPClipboardFromGtk(const Gt
           && source.size() < DNDMSG_MAX_ARGSZ
           && CPClipboard_SetItem(&mClipboard, CPFORMAT_RTF, source.c_str(),
                                  source.size() + 1)) {
-         g_debug("%s: Got RTF, size %"FMTSZ"u\n", __FUNCTION__, source.size());
+         g_debug("%s: Got RTF, size %" FMTSZ "u\n", __FUNCTION__, source.size());
          return true;
       } else {
          g_debug("%s: Failed to get text\n", __FUNCTION__ );
@@ -2229,7 +2229,7 @@ DnDUIX11::WriteFileContentsToStagingDir(
 
       if (!fileItem[i].cpName.cpName_val ||
           0 == fileItem[i].cpName.cpName_len) {
-         g_debug("%s: invalid fileItem[%"FMTSZ"u].cpName.\n", __FUNCTION__, i);
+         g_debug("%s: invalid fileItem[%" FMTSZ "u].cpName.\n", __FUNCTION__, i);
          goto exit;
       }
 
