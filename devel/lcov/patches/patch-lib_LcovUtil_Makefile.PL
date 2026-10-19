$NetBSD: patch-lib_LcovUtil_Makefile.PL,v 1.2 2026/10/19 14:12:16 wiz Exp $

Makefile.PL: make the -static-libstdc++ probe use the C++ runtime
https://github.com/linux-test-project/lcov/pull/560

--- lib/LcovUtil/Makefile.PL.orig	2026-09-29 23:30:59.000000000 +0000
+++ lib/LcovUtil/Makefile.PL
@@ -162,7 +162,21 @@ my $cxx_runtime_flags = '';
     my $out    = File::Spec->catfile($tmpdir, 'probe.so');
     open(my $probe, '>', $src) or
         die "Makefile.PL: cannot write $src: $!\n";
-    print($probe "extern \"C\" int lcov_probe() { return 0; }\n");
+    # Use exceptions, as the extension does:  an empty probe pulls nothing out
+    # of a static libstdc++.a, so it links even where the real extension cannot
+    # (e.g. a libstdc++.a which is not position-independent - see #552).
+    print($probe <<'END_PROBE');
+#include <stdexcept>
+#include <string>
+extern "C" int lcov_probe(const char *s)
+{
+    try {
+        throw std::runtime_error(std::string(s));
+    } catch (const std::exception &e) {
+        return static_cast<int>(std::string(e.what()).size());
+    }
+}
+END_PROBE
     close($probe);
 
     # True when $cxx can build a shared object with these extra flags.
@@ -206,7 +220,7 @@ my $cxx_runtime_flags = '';
         if (defined($rpath) && $can_link->($rpath)) {
             $cxx_runtime_flags = " $rpath";
             print <<"END_MSG";
-Makefile.PL: no static C++ library for '$cxx'; using an rpath instead.
+Makefile.PL: no usable static C++ library for '$cxx'; using an rpath instead.
 The extension will look for its C++ runtime in
     $dir
 before anything named by LD_LIBRARY_PATH.  Moving or removing that directory
