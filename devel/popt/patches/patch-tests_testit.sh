$NetBSD: patch-tests_testit.sh,v 1.1 2020/08/15 01:02:42 tnn Exp $

Fix test suite failure.

--- tests/testit.sh.orig	2020-03-24 11:01:52.000000000 +0000
+++ tests/testit.sh
@@ -115,7 +115,7 @@ run test1 "test1 - 56" "arg1: 0 arg2: (n
 run test1 "test1 - 57" "arg1: 0 arg2: (none) aBits: foo,baz" --bits foo,bar,baz,!bar
 
 run test1 "test1 - 58" "\
-Usage: lt-test1 [-I?] [-c|--cb2=STRING] [--arg1] [-2|--arg2=ARG]
+Usage: test1 [-I?] [-c|--cb2=STRING] [--arg1] [-2|--arg2=ARG]
         [-3|--arg3=ANARG] [-onedash] [--optional=STRING] [--val]
         [-i|--int=INT] [-s|--short=SHORT] [-l|--long=LONG]
         [-L|--longlong=LONGLONG] [-f|--float=FLOAT] [-d|--double=DOUBLE]
@@ -124,7 +124,7 @@ Usage: lt-test1 [-I?] [-c|--cb2=STRING] 
         [--bitxor] [--nstr=STRING] [--lstr=STRING] [-I|--inc]
         [-c|--cb=STRING] [--longopt] [-?|--help] [--usage] [--simple=ARG]" --usage
 run test1 "test1 - 59" "\
-Usage: lt-test1 [OPTION...]
+Usage: test1 [OPTION...]
       --arg1                      First argument with a really long
                                   description. After all, we have to test
                                   argument help wrapping somehow, right?
