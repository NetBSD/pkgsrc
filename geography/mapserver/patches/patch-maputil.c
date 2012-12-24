$NetBSD: patch-maputil.c,v 1.1 2012/12/24 21:09:47 joerg Exp $

--- maputil.c.orig	2012-12-23 17:18:02.000000000 +0000
+++ maputil.c
@@ -1876,14 +1876,14 @@ int msCheckParentPointer(void* p, char *
     return MS_SUCCESS;
 }
 
-inline void msBufferInit(bufferObj *buffer) {
+void msBufferInit(bufferObj *buffer) {
     buffer->data=NULL;
     buffer->size=0;
     buffer->available=0;
     buffer->_next_allocation_size = MS_DEFAULT_BUFFER_ALLOC;
 }
 
-inline void msBufferResize(bufferObj *buffer, size_t target_size){
+void msBufferResize(bufferObj *buffer, size_t target_size){
     while(buffer->available <= target_size) {
         buffer->data = realloc(buffer->data,buffer->available+buffer->_next_allocation_size);
         buffer->available += buffer->_next_allocation_size;
@@ -1891,7 +1891,7 @@ inline void msBufferResize(bufferObj *bu
     }
 }
 
-inline void msBufferAppend(bufferObj *buffer, void *data, size_t length) {
+void msBufferAppend(bufferObj *buffer, void *data, size_t length) {
     if(buffer->available < buffer->size+length) {
         msBufferResize(buffer,buffer->size+length);
     }
@@ -1899,7 +1899,7 @@ inline void msBufferAppend(bufferObj *bu
     buffer->size += length;
 }
 
-inline void msBufferFree(bufferObj *buffer) {
+void msBufferFree(bufferObj *buffer) {
     if(buffer->available>0)
         free(buffer->data);
 }
