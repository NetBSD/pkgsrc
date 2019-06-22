$NetBSD: patch-buildtools_wafsamba_samba__utils.py,v 1.1 2019/06/22 12:14:49 jmcneill Exp $

--- buildtools/wafsamba/samba_utils.py.orig	2019-03-21 10:12:32.000000000 +0000
+++ buildtools/wafsamba/samba_utils.py
@@ -519,10 +519,7 @@ def CHECK_MAKEFLAGS(options):
             setattr(options, opt[0:loc], opt[loc+1:])
         elif opt[0] != '-':
             for v in opt:
-                if re.search(r'j[0-9]*$', v):
-                    jobs_set = True
-                    jobs = opt.strip('j')
-                elif v == 'k':
+                if v == 'k':
                     options.keep = True
         elif re.search(r'-j[0-9]*$', opt):
             jobs_set = True
