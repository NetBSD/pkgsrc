$NetBSD: patch-jdk_src_solaris_native_sun_nio_ch_sctp_SctpNet.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- jdk/src/solaris/native/sun/nio/ch/sctp/SctpNet.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/native/sun/nio/ch/sctp/SctpNet.c
@@ -1,3 +1,4 @@
+#if !defined(__NetBSD__)
 /*
  * Copyright (c) 2009, 2012, Oracle and/or its affiliates. All rights reserved.
  * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
@@ -753,3 +754,4 @@ JNIEXPORT int JNICALL Java_sun_nio_ch_sc
 
     return newfd;
 }
+#endif
