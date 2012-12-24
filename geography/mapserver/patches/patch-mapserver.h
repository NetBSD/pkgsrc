$NetBSD: patch-mapserver.h,v 1.1 2012/12/24 21:09:47 joerg Exp $

--- mapserver.h.orig	2012-12-23 17:16:27.000000000 +0000
+++ mapserver.h
@@ -2614,10 +2614,10 @@ int msSaveRasterBuffer(rasterBufferObj *
 int msSaveRasterBufferToBuffer(rasterBufferObj *data, bufferObj *buffer,
         outputFormatObj *format);
 
-inline void msBufferInit(bufferObj *buffer);
-inline void msBufferResize(bufferObj *buffer, size_t target_size);
-MS_DLL_EXPORT  inline void msBufferFree(bufferObj *buffer);
-MS_DLL_EXPORT  inline void msBufferAppend(bufferObj *buffer, void *data, size_t length);
+void msBufferInit(bufferObj *buffer);
+void msBufferResize(bufferObj *buffer, size_t target_size);
+MS_DLL_EXPORT  void msBufferFree(bufferObj *buffer);
+MS_DLL_EXPORT  void msBufferAppend(bufferObj *buffer, void *data, size_t length);
 
 struct rendererVTable {
 	int supports_transparent_layers;
