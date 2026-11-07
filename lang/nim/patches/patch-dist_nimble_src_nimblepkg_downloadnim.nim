$NetBSD: patch-dist_nimble_src_nimblepkg_downloadnim.nim,v 1.1 2026/11/07 22:43:07 wiz Exp $

Add NetBSD to nimble's nightly-OS detection. Without a matching branch the
`when` expression in getNightliesUrl is empty on NetBSD and the compiler
rejects it with "expression '' has no type (or is ambiguous)".

--- dist/nimble/src/nimblepkg/downloadnim.nim.orig
+++ dist/nimble/src/nimblepkg/downloadnim.nim
@@ -146,5 +146,7 @@
     elif defined(openbsd):
       "openbsd"
     elif defined(haiku):
       "haiku"
+    elif defined(netbsd):
+      "netbsd"
   for jn in parsedContents.getElems():
