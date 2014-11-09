$NetBSD: patch-extras_immodules_agent_scim-bridge-agent-application.cpp,v 1.2 2014/11/09 02:46:30 obache Exp $

--- extras/immodules/agent/scim-bridge-agent-application.cpp.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/agent/scim-bridge-agent-application.cpp
@@ -61,12 +61,12 @@ int main (int argc, char *argv[])
         {0, 0, NULL, 0}
     };
 
-    char short_options[] = "vhqdls:b:";
+    char short_options[] = "vhql:sn:";
 
     unsigned int tmp_uint;
 
     int option = 0;
-    while (option != EOF) {
+    while (option != -1) {
         option = getopt_long (argc, argv, short_options, long_options, NULL);
         switch (option) {
             case 'v':
