$NetBSD: patch-packages_xpce_src_img_gifread.c,v 1.1 2013/01/24 12:03:09 is Exp $

--- gifread.c.orig	2011-03-23 18:57:54.000000000 +0000
+++ packages/xpce/src/img/gifread.c
@@ -169,7 +169,7 @@ GIFReadFD(IOSTREAM *fd,
   /* read colormaps */
   if ( BitSet((UCHAR) buf[4], LOCALCOLORMAP) )
   { if ( (rval=ReadColorMap(fd, GifScreen.BitPixel, at, ac, closure))
-	 							!= GIF_OK )
+								!= GIF_OK )
     { setGifError("Error reading GIF colormap");
       return rval;
     }
@@ -466,7 +466,7 @@ LZWReadByte(IOSTREAM * fd, int flag, int
       firstcode = oldcode = GetCode(fd, code_size, FALSE);
     }
     while (firstcode == clear_code);
-    return firstcode;
+    return (firstcode&255);
   }
   if (sp > stack)
     return *--sp;
@@ -487,11 +487,11 @@ LZWReadByte(IOSTREAM * fd, int flag, int
       max_code = clear_code + 2;
       sp = stack;
       firstcode = oldcode = GetCode(fd, code_size, FALSE);
-      return firstcode;
-    } else if (code == end_code)
+      return (firstcode&255);
+    } else if (code == end_code || code > max_code)
     {
       int count;
-      UCHAR buf[260];
+      UCHAR buf[260];			/* Block buffer */
 
       if (ZeroDataBlock)
 	return -2;
@@ -505,11 +505,12 @@ LZWReadByte(IOSTREAM * fd, int flag, int
     incode = code;
 
     if (code >= max_code)
-    {
-      *sp++ = firstcode;
+    { if ( sp < stack+sizeof(stack) )  /* stack is UCHAR */
+         *sp++ = firstcode;
+
       code = oldcode;
     }
-    while (code >= clear_code)
+    while (code >= clear_code && sp < stack+sizeof(stack))
     {
       *sp++ = vals[code];
       if (code == (int) next[code])
@@ -520,7 +521,8 @@ LZWReadByte(IOSTREAM * fd, int flag, int
       code = next[code];
     }
 
-    *sp++ = firstcode = vals[code];
+    if ( sp < stack+sizeof(stack) )
+      *sp++ = firstcode = vals[code];
 
     if ((code = max_code) < (1 << MAX_LZW_BITS))
     {
@@ -537,9 +539,9 @@ LZWReadByte(IOSTREAM * fd, int flag, int
     oldcode = incode;
 
     if (sp > stack)
-      return *--sp;
+      return ((*--sp) & 255);
   }
-  return code;
+  return (code&255);
 }
 
 
@@ -554,7 +556,7 @@ ReadImage(IOSTREAM *fd,
   int xpos = 0, ypos = 0, pass = 0;
   long curidx;
 
-  if (!ReadOK(fd, &c, 1))
+  if ( !ReadOK(fd, &c, 1) || c > MAX_LZW_BITS )
   { return GIF_INVALID;
   }
   if (LZWReadByte(fd, TRUE, c) < 0)
