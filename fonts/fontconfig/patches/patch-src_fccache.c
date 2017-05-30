$NetBSD: patch-src_fccache.c,v 1.1 2017/05/30 16:53:14 jperkin Exp $

Apply upstream patch for https://bugs.freedesktop.org/show_bug.cgi?id=97546

--- src/fccache.c.orig	2016-08-05 05:35:05.000000000 +0000
+++ src/fccache.c
@@ -640,6 +640,7 @@ FcCacheOffsetsValid (FcCache *cache)
             FcPattern		*font = FcFontSetFont (fs, i);
             FcPatternElt	*e;
             FcValueListPtr	 l;
+	    char                *last_offset;
 
             if ((char *) font < base ||
                 (char *) font > end - sizeof (FcFontSet) ||
@@ -653,11 +654,17 @@ FcCacheOffsetsValid (FcCache *cache)
             if (e->values != 0 && !FcIsEncodedOffset(e->values))
                 return FcFalse;
 
-            for (j = font->num, l = FcPatternEltValues(e); j >= 0 && l; j--, l = FcValueListNext(l))
-                if (l->next != NULL && !FcIsEncodedOffset(l->next))
-                    break;
-            if (j < 0)
-                return FcFalse;
+	    for (j = 0; j < font->num; j++)
+	    {
+		last_offset = (char *) font + font->elts_offset;
+		for (l = FcPatternEltValues(&e[j]); l; l = FcValueListNext(l))
+		{
+		    if ((char *) l < last_offset || (char *) l > end - sizeof (*l) ||
+			(l->next != NULL && !FcIsEncodedOffset(l->next)))
+			return FcFalse;
+		    last_offset = (char *) l + 1;
+		}
+	    }
         }
     }
 
