$NetBSD: patch-lenses_tests_test_simplevars.aug,v 1.1 2026/09/06 18:44:02 bsiegert Exp $

Test that the perl form of adduser.conf is read; see
patch-lenses_simplevars.aug.

Sent upstream as hercules-team/augeas#893; this is that diff.

--- lenses/tests/test_simplevars.aug.orig
+++ lenses/tests/test_simplevars.aug
@@ -34,3 +34,32 @@
      Support empty values *)
 test Simplevars.lns get "foo =\n" =
   { "foo" = "" { } }
+
+(* Variable: bsd_adduser
+     adduser(8) on the BSDs writes its config as perl, not as shell *)
+let bsd_adduser = "# verbose = [0-2]
+verbose = 1
+
+# copy dotfiles from this dir (\"/etc/skel\" or \"no\")
+dotdir = \"/etc/skel\"
+
+# List of directories where shells located
+# path = ('/bin', '/usr/bin', '/usr/local/bin')
+path = ('/bin', '/usr/bin', '/usr/local/bin')
+
+## DO NOT DELETE THIS LINE!
+"
+
+(* Test: Simplevars.lns *)
+test Simplevars.lns get bsd_adduser =
+   { "#comment" = "verbose = [0-2]" }
+   { "verbose" = "1" }
+   { }
+   { "#comment" = "copy dotfiles from this dir (\"/etc/skel\" or \"no\")" }
+   { "dotdir" = "\"/etc/skel\"" }
+   { }
+   { "#comment" = "List of directories where shells located" }
+   { "#comment" = "path = ('/bin', '/usr/bin', '/usr/local/bin')" }
+   { "path" = "('/bin', '/usr/bin', '/usr/local/bin')" }
+   { }
+   { "#comment" = "# DO NOT DELETE THIS LINE!" }
