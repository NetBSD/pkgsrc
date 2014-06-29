$NetBSD: patch-.waf3-1.6.4-e3c1e08604b18a10567cfcd2d02eb6e6_waflib_Tools_python.py,v 1.1 2014/06/29 15:04:40 joerg Exp $

--- .waf3-1.6.4-e3c1e08604b18a10567cfcd2d02eb6e6/waflib/Tools/python.py.orig	2014-06-29 14:32:41.000000000 +0000
+++ .waf3-1.6.4-e3c1e08604b18a10567cfcd2d02eb6e6/waflib/Tools/python.py
@@ -169,7 +169,7 @@ def check_python_headers(conf):
 		conf.find_program('python-config-%s'%num,var='PYTHON_CONFIG',mandatory=False)
 	includes=[]
 	if conf.env.PYTHON_CONFIG:
-		for incstr in conf.cmd_and_log(conf.env.PYTHON+[conf.env.PYTHON_CONFIG,'--includes']).strip().split():
+		for incstr in conf.cmd_and_log([conf.env.PYTHON_CONFIG,'--includes']).strip().split():
 			if(incstr.startswith('-I')or incstr.startswith('/I')):
 				incstr=incstr[2:]
 			if incstr not in includes:
