$NetBSD: patch-src_common_pa__stream.h,v 1.1 2019/10/26 17:22:39 nia Exp $

Add features needed to make portmixer work in audacity.

--- src/common/pa_stream.h.orig	2016-10-30 01:23:04.000000000 +0000
+++ src/common/pa_stream.h
@@ -152,6 +152,7 @@ typedef struct PaUtilStreamRepresentatio
     PaStreamFinishedCallback *streamFinishedCallback;
     void *userData;
     PaStreamInfo streamInfo;
+    PaHostApiTypeId hostApiType;
 } PaUtilStreamRepresentation;
 
 
