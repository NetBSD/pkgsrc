$NetBSD: patch-jdk_src_solaris_native_sun_nio_ch_sctp_SctpChannelImpl.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- jdk/src/solaris/native/sun/nio/ch/sctp/SctpChannelImpl.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/native/sun/nio/ch/sctp/SctpChannelImpl.c
@@ -1,3 +1,4 @@
+#if !defined(__NetBSD__)
 /*
  * Copyright (c) 2009, 2012, Oracle and/or its affiliates. All rights reserved.
  * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
@@ -613,4 +614,4 @@ JNIEXPORT jint JNICALL Java_sun_nio_ch_s
     return Java_sun_nio_ch_SocketChannelImpl_checkConnect(env, this,
                                                           fdo, block, ready);
 }
-
+#endif
