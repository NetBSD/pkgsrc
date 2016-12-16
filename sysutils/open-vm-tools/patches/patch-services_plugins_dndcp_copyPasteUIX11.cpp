$NetBSD: patch-services_plugins_dndcp_copyPasteUIX11.cpp,v 1.1 2016/12/16 00:04:03 joerg Exp $

Avoid User-defined Literals in C++11.

--- services/plugins/dndcp/copyPasteUIX11.cpp.orig	2016-12-15 15:01:19.828851463 +0000
+++ services/plugins/dndcp/copyPasteUIX11.cpp
@@ -214,7 +214,7 @@ CopyPasteUIX11::~CopyPasteUIX11()
        !mHGStagingDir.empty()) {
       uint64 totalSize = File_GetSizeEx(mHGStagingDir.c_str());
       if (mTotalFileSize != totalSize) {
-         g_debug("%s: deleting %s, expecting %"FMT64"d, finished %"FMT64"d\n",
+         g_debug("%s: deleting %s, expecting %" FMT64 "d, finished %" FMT64 "d\n",
                  __FUNCTION__, mHGStagingDir.c_str(),
                  mTotalFileSize, totalSize);
          DnD_DeleteStagingFiles(mHGStagingDir.c_str(), FALSE);
@@ -552,7 +552,7 @@ CopyPasteUIX11::LocalGetTextOrRTFRequest
          return;
       }
 
-      g_debug("%s: providing RTF data, size %"FMTSZ"u\n",
+      g_debug("%s: providing RTF data, size %" FMTSZ "u\n",
             __FUNCTION__, mHGRTFData.size());
 
       sd.set(target.c_str(), mHGRTFData.c_str());
@@ -566,7 +566,7 @@ CopyPasteUIX11::LocalGetTextOrRTFRequest
          g_debug("%s: Can not get valid text data\n", __FUNCTION__);
          return;
       }
-      g_debug("%s: providing plain text, size %"FMTSZ"u\n",
+      g_debug("%s: providing plain text, size %" FMTSZ "u\n",
             __FUNCTION__, mHGTextData.bytes());
 
       sd.set(target.c_str(), mHGTextData.c_str());
@@ -743,7 +743,7 @@ again:
           CPClipboard_SetItem(&mClipboard, CPFORMAT_IMG_PNG,
                               buf, bufSize)) {
          validDataInClip = true;
-         g_debug("%s: Got PNG: %"FMTSZ"u\n", __FUNCTION__, bufSize);
+         g_debug("%s: Got PNG: %" FMTSZ "u\n", __FUNCTION__, bufSize);
       } else {
          g_debug("%s: Failed to get PNG\n", __FUNCTION__);
       }
@@ -796,7 +796,7 @@ again:
           CPClipboard_SetItem(&mClipboard, CPFORMAT_TEXT,
                               (const void *)str.data(), bufSize + 1)) {
          validDataInClip = true;
-         g_debug("%s: Got TEXT: %"FMTSZ"u\n", __FUNCTION__, bufSize);
+         g_debug("%s: Got TEXT: %" FMTSZ "u\n", __FUNCTION__, bufSize);
       } else {
          g_debug("%s: Failed to get TEXT\n", __FUNCTION__);
       }
@@ -1031,7 +1031,7 @@ CopyPasteUIX11::LocalGetSelectionFileLis
 
    DynBuf_Init(&buf);
    fileList.SetFileSize(totalSize);
-   g_debug("%s: totalSize is %"FMT64"u\n", __FUNCTION__, totalSize);
+   g_debug("%s: totalSize is %" FMT64 "u\n", __FUNCTION__, totalSize);
    fileList.ToCPClipboard(&buf, false);
    CPClipboard_SetItem(&mClipboard, CPFORMAT_FILELIST, DynBuf_Get(&buf),
                        DynBuf_GetSize(&buf));
@@ -1198,7 +1198,7 @@ CopyPasteUIX11::GetRemoteClipboardCB(con
        * accept paste.
        */
       if (CPClipboard_GetItem(clip, CPFORMAT_RTF, &buf, &sz)) {
-         g_debug("%s: RTF data, size %"FMTSZ"u.\n", __FUNCTION__, sz);
+         g_debug("%s: RTF data, size %" FMTSZ "u.\n", __FUNCTION__, sz);
          Gtk::TargetEntry appRtf(TARGET_NAME_APPLICATION_RTF);
          Gtk::TargetEntry textRtf(TARGET_NAME_TEXT_RICHTEXT);
 
@@ -1214,7 +1214,7 @@ CopyPasteUIX11::GetRemoteClipboardCB(con
          Gtk::TargetEntry utf8Text(TARGET_NAME_UTF8_STRING);
          Gtk::TargetEntry compountText(TARGET_NAME_COMPOUND_TEXT);
 
-         g_debug("%s: Text data, size %"FMTSZ"u.\n", __FUNCTION__, sz);
+         g_debug("%s: Text data, size %" FMTSZ "u.\n", __FUNCTION__, sz);
          targets.push_back(stringText);
          targets.push_back(plainText);
          targets.push_back(utf8Text);
@@ -1234,7 +1234,7 @@ CopyPasteUIX11::GetRemoteClipboardCB(con
    }
 
    if (CPClipboard_GetItem(clip, CPFORMAT_IMG_PNG, &buf, &sz)) {
-      g_debug("%s: PNG data, size %"FMTSZ"u.\n", __FUNCTION__, sz);
+      g_debug("%s: PNG data, size %" FMTSZ "u.\n", __FUNCTION__, sz);
       /* Try to load buf into pixbuf, and write to local clipboard. */
       try {
          Glib::RefPtr<Gdk::PixbufLoader> loader = Gdk::PixbufLoader::create();
@@ -1388,7 +1388,7 @@ CopyPasteUIX11::LocalPrepareFileContents
 
       if (!fileItem[i].cpName.cpName_val ||
           0 == fileItem[i].cpName.cpName_len) {
-         g_debug("%s: invalid fileItem[%"FMTSZ"u].cpName.\n", __FUNCTION__, i);
+         g_debug("%s: invalid fileItem[%" FMTSZ "u].cpName.\n", __FUNCTION__, i);
          goto exit;
       }
 
