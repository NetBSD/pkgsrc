$NetBSD: patch-tools_build_src_tools_gcc.py,v 1.1 2015/04/25 19:02:06 tnn Exp $

https://github.com/boostorg/build/issues/72

--- tools/build/src/tools/gcc.py.orig	2015-04-04 17:25:07.000000000 +0000
+++ tools/build/src/tools/gcc.py
@@ -789,8 +789,7 @@ cpu_flags('gcc', 'OPTIONS', 'x86', 'atom
 # Sparc
 flags('gcc', 'OPTIONS', ['<architecture>sparc/<address-model>32'], ['-m32'])
 flags('gcc', 'OPTIONS', ['<architecture>sparc/<address-model>64'], ['-m64'])
-cpu_flags('gcc', 'OPTIONS', 'sparc', 'c3', ['-mcpu=c3'], default=True)
-cpu_flags('gcc', 'OPTIONS', 'sparc', 'v7', ['-mcpu=v7'])
+cpu_flags('gcc', 'OPTIONS', 'sparc', 'v7', ['-mcpu=v7'], default=True)
 cpu_flags('gcc', 'OPTIONS', 'sparc', 'cypress', ['-mcpu=cypress'])
 cpu_flags('gcc', 'OPTIONS', 'sparc', 'v8', ['-mcpu=v8'])
 cpu_flags('gcc', 'OPTIONS', 'sparc', 'supersparc', ['-mcpu=supersparc'])
