$NetBSD: patch-bin_rrd2whisper.py,v 1.1 2018/07/07 04:56:45 minskim Exp $

Make the command work with Python 3.
https://github.com/graphite-project/whisper/pull/254

--- bin/rrd2whisper.py.orig	2018-04-04 08:34:11.000000000 +0000
+++ bin/rrd2whisper.py
@@ -20,7 +20,7 @@ except ImportError:
 # Ignore SIGPIPE
 signal.signal(signal.SIGPIPE, signal.SIG_DFL)
 
-aggregationMethods = whisper.aggregationMethods
+aggregationMethods = list(whisper.aggregationMethods)
 
 # RRD doesn't have a 'sum' or 'total' type
 aggregationMethods.remove('sum')
