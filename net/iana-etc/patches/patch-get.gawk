$NetBSD: patch-get.gawk,v 1.3 2019/06/15 15:16:30 christos Exp $

o Add a new parameter to specify the name of the url to get the files from.
  Well, partial name but that is good enough.
o Add a user-agent, because iana now requires one

--- get.gawk.orig	2008-03-05 13:04:18.000000000 -0500
+++ get.gawk	2019-06-15 11:14:57.692498675 -0400
@@ -7,7 +7,7 @@
 
 # get.awk: retrieves IANA numbers assignments from iana.org.
 # Requires GNU Awk.
-# Usage: get.gawk -v file=<filename>
+# Usage: get.gawk -v url=<url> file=<filename>
 
 BEGIN {
     host = "www.iana.org"
@@ -15,8 +15,8 @@
     # file is set by the caller
     socket = "/inet/tcp/0/" host "/80"
 
-    print "Getting http://" host path file >"/dev/stderr"
-    printf "GET %s%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, file, host |& socket
+    print "Getting http://" host path url "/" url ".txt" >"/dev/stderr"
+    printf "GET %s%s/%s.txt HTTP/1.0\r\nHost: %s\r\nUser-Agent: MickeyMouse/1.0\r\n\r\n", path, url, url, host |& socket
     printf "Request sent, waiting for data... " >"/dev/stderr"
 
     NR = 0
