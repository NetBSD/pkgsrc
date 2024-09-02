$NetBSD: patch-vendor_github.com_containers_image_v5_signature_policy__paths__common.go,v 1.1 2024/09/02 17:44:03 maya Exp $

Use pkgsrc directories

--- vendor/github.com/containers/image/v5/signature/policy_paths_common.go.orig	2024-05-30 16:55:38.205703869 +0000
+++ vendor/github.com/containers/image/v5/signature/policy_paths_common.go
@@ -5,4 +5,4 @@ package signature
 
 // builtinDefaultPolicyPath is the policy path used for DefaultPolicy().
 // DO NOT change this, instead see systemDefaultPolicyPath above.
-const builtinDefaultPolicyPath = "/etc/containers/policy.json"
+const builtinDefaultPolicyPath = "@PKG_SYSCONFDIR@/policy.json"
