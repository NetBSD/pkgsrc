$NetBSD: patch-crt_aws-c-io_source_posix_host__resolver.c,v 1.1 2025/09/07 18:33:59 maya Exp $

Fix NetBSD build issue: no AI_ALL/AI_V4MAPPED. Match the OpenBSD exception.

--- crt/aws-c-io/source/posix/host_resolver.c.orig	2025-09-06 20:33:44.486176072 +0000
+++ crt/aws-c-io/source/posix/host_resolver.c
@@ -38,7 +38,7 @@ int aws_default_dns_resolve(
     AWS_ZERO_STRUCT(hints);
     hints.ai_family = AF_UNSPEC;
     hints.ai_socktype = SOCK_STREAM;
-#    if !defined(__OpenBSD__)
+#    if !(defined(__OpenBSD__) || defined(__NetBSD__))
     hints.ai_flags = AI_ALL | AI_V4MAPPED;
 #    endif /* __OpenBSD__ */
 
