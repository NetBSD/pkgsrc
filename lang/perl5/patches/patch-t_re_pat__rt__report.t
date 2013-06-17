$NetBSD: patch-t_re_pat__rt__report.t,v 1.1 2013/06/17 06:54:13 wiz Exp $

Fix regmatch pointer 32-bit wraparound regression

Cherry-picked from:

commit 285a3ca139d04d2ee1894c9a9110294ee8bb0309
Merge: aad0429 dfb8f19
Author:     Tony Cook <tony@develop-help.com>
AuthorDate: Mon Jun 3 22:28:37 2013 +1000
Commit:     Tony Cook <tony@develop-help.com>
CommitDate: Mon Jun 3 22:28:37 2013 +1000

    [perl #118175] avoid making pointers outside of objects

    In a couple of cases, when strings were allocated above the 2GB line
    on 32-bit CPUs, this could cause regexps to act strangely - not matching
    or crashing perl.

    The final patch in the set prevents pointer creation which the C standard
    describes as undefined behaviour, but is typically safe (as long as the
    pointer isn't derefed)

This regression was introduced into 5.18.0 by commit
4063ade8503ac8877a02fc4eae8ebbe242b9110b.

--- t/re/pat_rt_report.t.orig	2013-05-01 02:52:56.000000000 +0000
+++ t/re/pat_rt_report.t
@@ -22,7 +22,7 @@ BEGIN {
 }
 
 
-plan tests => 2530;  # Update this when adding/deleting tests.
+plan tests => 2532;  # Update this when adding/deleting tests.
 
 run_tests() unless caller;
 
@@ -1158,6 +1158,21 @@ EOP
             '$_ = "abc"; /b/g; $_ = "hello"; print eval q|$\'|,"\n"',
             "c\n", {}, '$\' first mentioned after match');
     }
+
+    {
+	# [perl #118175] threaded perl-5.18.0 fails pat_rt_report_thr.t
+	# this tests some related failures
+	#
+	# The tests in the block *only* fail when run on 32-bit systems
+	# with a malloc that allocates above the 2GB line.  On the system
+	# in the report above that only happened in a thread.
+	my $s = "\x{1ff}" . "f" x 32;
+	ok($s =~ /\x{1ff}[[:alpha:]]+/gca, "POSIXA pointer wrap");
+
+	# this one segfaulted under the conditions above
+	# of course, CANY is evil, maybe it should crash
+	ok($s =~ /.\C+/, "CANY pointer wrap");
+    }
 } # End of sub run_tests
 
 1;
