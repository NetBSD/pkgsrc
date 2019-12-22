$NetBSD: patch-waflib_Tools_c__config.py,v 1.1 2019/12/22 22:21:58 joerg Exp $

When detecting the C++ compiler, force C++ mode for stdin as the wrappers
add -std=c++11 and that breaks for C input.

--- waflib/Tools/c_config.py.orig	2019-12-21 22:11:24.000906920 +0000
+++ waflib/Tools/c_config.py
@@ -632,7 +632,7 @@ def cxx_load_tools(conf):
 	conf.load('cxx')
 @conf
 def get_cc_version(conf,cc,gcc=False,icc=False,clang=False):
-	cmd=cc+['-dM','-E','-']
+	cmd=cc+(['-x','c++']if cc[0].endswith('+')else[])+['-dM','-E','-']
 	env=conf.env.env or None
 	try:
 		out,err=conf.cmd_and_log(cmd,output=0,input='\n'.encode(),env=env)
