$NetBSD: patch-lib_exabgp_application_healthcheck.py,v 1.3 2024/02/19 12:54:09 he Exp $

Change type of `--neighbor` argument from ip_address to str
so that it can support '*' as a value.

--- lib/exabgp/application/healthcheck.py.orig	2024-02-19 12:45:30.545761963 +0000
+++ lib/exabgp/application/healthcheck.py
@@ -222,7 +222,7 @@ def parse():
         help=("Instead of increasing the metric on health failure, " "withdraw the route"),
     )
     g.add_argument("--path-id", metavar='PATHID', type=int, default=None, help="path ID to advertise for the route")
-    g.add_argument("--neighbor", metavar='NEIGHBOR', type=ip_address, dest="neighbors", action="append", help="advertise the route to the selected neigbors")
+    g.add_argument("--neighbor", metavar='NEIGHBOR', type=str, dest="neighbors", action="append", help="advertise the route to the selected neigbors")
 
     g = parser.add_argument_group("reporting")
     g.add_argument("--execute", metavar='CMD', type=str, action="append", help="execute CMD on state change")
