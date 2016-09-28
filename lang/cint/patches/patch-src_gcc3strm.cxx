$NetBSD: patch-src_gcc3strm.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Fix build with recent (>3.3) GCC.

--- src/gcc3strm.cxx.orig	2006-09-28 09:01:54.000000000 +0000
+++ src/gcc3strm.cxx
@@ -308,13 +308,13 @@ static int G__G__stream_7_6_0(G__value* 
 
 static int G__G__stream_7_7_0(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
 {
-      G__letint(result7, 103, (long) ((fpos<mbstate_t>*) G__getstructoffset())->operator==(*(fpos<mbstate_t>*) libp->para[0].ref));
+   G__letint(result7, 103, (long) (*(fpos<mbstate_t>*) G__getstructoffset())==(*(fpos<mbstate_t>*) libp->para[0].ref));
    return(1 || funcname || hash || result7 || libp) ;
 }
 
 static int G__G__stream_7_8_0(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
 {
-      G__letint(result7, 103, (long) ((fpos<mbstate_t>*) G__getstructoffset())->operator!=(*(fpos<mbstate_t>*) libp->para[0].ref));
+   G__letint(result7, 103, (long) (*(fpos<mbstate_t>*) G__getstructoffset())!=(*(fpos<mbstate_t>*) libp->para[0].ref));
    return(1 || funcname || hash || result7 || libp) ;
 }
 
