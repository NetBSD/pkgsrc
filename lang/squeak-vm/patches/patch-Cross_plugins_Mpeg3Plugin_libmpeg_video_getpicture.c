$NetBSD: patch-Cross_plugins_Mpeg3Plugin_libmpeg_video_getpicture.c,v 1.1 2012/10/20 22:12:30 joerg Exp $

--- Cross/plugins/Mpeg3Plugin/libmpeg/video/getpicture.c.orig	2012-10-20 13:52:22.000000000 +0000
+++ Cross/plugins/Mpeg3Plugin/libmpeg/video/getpicture.c
@@ -205,7 +205,7 @@ int mpeg3video_getintrablock(mpeg3_slice
 		{
 /*    	  	fprintf(stderr, "mpeg3video_getintrablock: invalid Huffman code\n"); */
     	  	slice->fault = 1;
-    	  	return;
+    	  	return 1;
     	}
 
     	mpeg3slice_flushbits(slice_buffer, tab->len);
@@ -240,7 +240,7 @@ int mpeg3video_getintrablock(mpeg3_slice
 		else
 		{
     	  	slice->fault = 1;
-    	  	return;
+    	  	return 1;
 		}
 			
 
@@ -397,7 +397,7 @@ int mpeg3video_getmpg2intrablock(mpeg3_s
 	else                  
 		val = (dc_dct_pred[2] += mpeg3video_getdcchrom(slice_buffer));
 
-  	if(slice->fault) return;
+  	if(slice->fault) return 1;
 #ifdef HAVE_MMX
 	if(video->have_mmx)
   		bp[0] = val << (7 - video->dc_prec);
@@ -463,7 +463,7 @@ int mpeg3video_getmpg2intrablock(mpeg3_s
 			{
 // invalid signed_level (escape)
         		slice->fault = 1;
-        		return;
+        		return 1;
     	  	}
     	  	if((sign = (val >= 2048)) != 0) val = 4096 - val;
     	}
@@ -545,7 +545,7 @@ int mpeg3video_getmpg2interblock(mpeg3_s
 		{
 // invalid Huffman code
     		slice->fault = 1;
-    		return;
+    		return 1;
     	}
 
     	mpeg3slice_flushbits(slice_buffer, tab->len);
