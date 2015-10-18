$NetBSD: patch-biewlib_sysdep_generic_unix_vio.c,v 1.1 2015/10/18 00:29:55 dholland Exp $

Fix build with HAVE_ICONV not set, needed on OpenBSD.

--- biewlib/sysdep/generic/unix/vio.c~	2009-09-20 14:39:37.000000000 +0000
+++ biewlib/sysdep/generic/unix/vio.c
@@ -190,6 +190,8 @@ chtype __FASTCALL__ _2ps(unsigned char c
 static char *screen_cp;
 static unsigned is_unicode=0;
 static void *nls_handle;
+#else
+#define is_unicode 0
 #endif
 
 #ifdef	_VT100_
@@ -437,11 +439,13 @@ void __FASTCALL__ __vioWriteBuff(tAbsCoo
 	    *dpb=c; dpb++;
 	}
 	else {
+#ifdef HAVE_ICONV
 	    unsigned len=1;
 	    char *destb=nls_recode2screen_cp(nls_handle,&c,&len);
 	    memcpy(dpb,destb,len);
 	    free(destb);
 	    dpb+=len;
+#endif
 	}
 #endif
     }
@@ -586,7 +590,9 @@ void __FASTCALL__ __term_vio(void)
     free(vtmp);
 #endif
     free(viomem);
+#ifdef HAVE_ICONV
     nls_term(nls_handle);
+#endif
     initialized = 0;
 }
 
