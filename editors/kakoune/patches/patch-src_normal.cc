$NetBSD: patch-src_normal.cc,v 1.1 2020/05/14 19:06:55 joerg Exp $

--- src/normal.cc.orig	2020-05-11 00:48:13.234212710 +0000
+++ src/normal.cc
@@ -646,7 +646,7 @@ void insert_output(Context& context, Nor
                 return ShellManager::instance().eval(
                     cmdline, context, content(context.buffer(), sel),
                     ShellManager::Flags::WaitForStdout).first;
-            }) | gather<Vector>();
+            }) | gather<Vector<String>>();
 
             selections.set_main_index(old_main);
             selections.insert(ins, mode);
