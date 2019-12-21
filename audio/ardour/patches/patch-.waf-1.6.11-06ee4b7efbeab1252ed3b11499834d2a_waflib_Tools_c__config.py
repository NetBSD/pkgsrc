$NetBSD: patch-.waf-1.6.11-06ee4b7efbeab1252ed3b11499834d2a_waflib_Tools_c__config.py,v 1.1 2019/12/21 23:27:04 joerg Exp $

When detecting the C++ compiler, force C++ mode for stdin as the wrappers
add -std=c++11 and that breaks for C input.

--- .waf-1.6.11-06ee4b7efbeab1252ed3b11499834d2a/waflib/Tools/c_config.py.orig	2019-12-21 19:28:02.658101225 +0000
+++ .waf-1.6.11-06ee4b7efbeab1252ed3b11499834d2a/waflib/Tools/c_config.py
@@ -553,7 +553,7 @@ def cxx_load_tools(conf):
 		conf.env.DEST_OS=Utils.unversioned_sys_platform()
 	conf.load('cxx')
 def get_cc_version(conf,cc,gcc=False,icc=False):
-	cmd=cc+['-dM','-E','-']
+	cmd=cc+(['-x','c++']if cc[0].endswith('+')else[])+['-dM','-E','-']
 	env=conf.env.env or None
 	try:
 		p=Utils.subprocess.Popen(cmd,stdin=Utils.subprocess.PIPE,stdout=Utils.subprocess.PIPE,stderr=Utils.subprocess.PIPE,env=env)
