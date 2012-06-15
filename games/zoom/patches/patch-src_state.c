$NetBSD: patch-src_state.c,v 1.1 2012/06/15 18:51:32 joerg Exp $

Avoid nested functions.

--- src/state.c.orig	2012-06-15 14:14:35.000000000 +0000
+++ src/state.c
@@ -181,37 +181,37 @@ ZByte* state_compile(ZStack* stack, ZDWo
   time_t now;
   ZByte version;
   
-  inline void wblock(ZByte* x, int len)
-    {
-      flen += len;
-      data = realloc(data, flen+16);
-      memcpy(data + flen - len, x, len);
-    }
-  
-  inline void wdword(ZDWord w)
-    {
-      flen +=4;
-      data = realloc(data, flen+16);
-      data[flen-4] = w>>24;
-      data[flen-3] = w>>16;
-      data[flen-2] = w>>8;
-      data[flen-1] = w;
-    }
-  
-  inline void wword(ZUWord w)
-    {
-      flen += 2;
-      data = realloc(data, flen+16);
-      data[flen-2] = w>>8;
-      data[flen-1] = w;
-    }
-  
-  inline void wbyte(ZUWord w)
-    {
-      flen += 1;
-      data = realloc(data, flen+16);
-      data[flen-1] = w;
-    }
+#define wblock(x,len) do { \
+  size_t wblock_len = (len); \
+  flen += wblock_len; \
+  data = realloc(data, flen+16); \
+  memcpy(data + flen - wblock_len, (x), wblock_len); \
+} while (0)
+
+#define wdword(w) do { \
+  ZDWord wdword_w = (w); \
+  flen +=4; \
+  data = realloc(data, flen+16); \
+  data[flen-4] = wdword_w>>24; \
+  data[flen-3] = wdword_w>>16; \
+  data[flen-2] = wdword_w>>8; \
+  data[flen-1] = wdword_w; \
+} while (0)
+
+#define wword(w) do { \
+  ZUWord wword_w = (w); \
+  flen += 2; \
+  data = realloc(data, flen+16); \
+  data[flen-2] = wword_w>>8; \
+  data[flen-1] = wword_w; \
+} while (0)
+
+#define wbyte(w) do { \
+  ZUWord wbyte_w = (w); \
+  flen += 1; \
+  data = realloc(data, flen+16); \
+  data[flen-1] = w; \
+} while (0)
 
   *len = -1;
   version = ReadByte(0);
