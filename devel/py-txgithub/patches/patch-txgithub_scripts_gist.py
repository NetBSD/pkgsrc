$NetBSD: patch-txgithub_scripts_gist.py,v 1.2 2017/10/01 09:52:19 wiz Exp $

Fix for python-3.x.
https://github.com/tomprince/txgithub/issues/13

--- txgithub/scripts/gist.py.orig	2017-09-30 20:47:17.806190554 +0000
+++ txgithub/scripts/gist.py
@@ -30,16 +30,16 @@ def postGist(reactor, token, files):
         gistFiles['gistfile1'] = {"content": sys.stdin.read()}
 
     response = yield api.gists.create(files=gistFiles)
-    print response['html_url']
+    print(response['html_url'])
 
 
 def run(reactor, *argv):
     config = Options()
     try:
         config.parseOptions(argv[1:]) # When given no argument, parses sys.argv[1:]
-    except usage.UsageError, errortext:
-        print '%s: %s' % (argv[0], errortext)
-        print '%s: Try --help for usage details.' % (argv[0])
+    except usage.UsageError as errortext:
+        print('%s: %s' % (argv[0], errortext))
+        print('%s: Try --help for usage details.' % (argv[0]))
         sys.exit(1)
 
     return postGist(reactor, **config)
