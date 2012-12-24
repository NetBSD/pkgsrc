$NetBSD: patch-setup.py,v 1.1 2012/12/24 21:15:33 joerg Exp $

--- setup.py.orig	2012-12-23 21:32:49.000000000 +0000
+++ setup.py
@@ -77,6 +77,21 @@ if DEBUG:
 else:
     extra_compile_args.append("-w")
 
+# XXX Use distutils
+if "CC" in os.environ:
+    try:
+        sp = subprocess.Popen([os.environ['CC'], '--version'],
+                              stdin=subprocess.PIPE,
+                              stdout=subprocess.PIPE,
+                              stderr=subprocess.PIPE,
+                              universal_newlines=True)
+        sp.stdin.close()
+        sp.wait()
+        if re.search("clang version", sp.stdout.read()):
+            extra_compile_args.append("-no-integrated-as")
+    except:
+        pass
+
 if DISABLE_EMBEDDED_CRYPTOPP:
     define_macros.append(('DISABLE_EMBEDDED_CRYPTOPP', 1))
 
