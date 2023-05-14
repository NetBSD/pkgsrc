--- tests/stdlib/tssl.nim.orig	2023-03-10 01:54:22.000000000 +0100
+++ tests/stdlib/tssl.nim	2023-05-14 22:37:16.081979178 +0200
@@ -2,6 +2,7 @@
   joinable: false
   disabled: "freebsd"
   disabled: "openbsd"
+  disabled: "netbsd"
 """
 # disabled: pending bug #15713
 import net, nativesockets
