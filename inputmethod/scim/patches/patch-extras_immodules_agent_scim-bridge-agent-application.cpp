$NetBSD: patch-extras_immodules_agent_scim-bridge-agent-application.cpp,v 1.1 2012/08/19 08:09:08 obache Exp $

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
@@ -90,14 +90,14 @@ int main (int argc, char *argv[])
                 standalone_enabled = true;
                 break;
             case 'h':
-                cout << "Usage: scim-bridge-agent [options]" << endl;
+                cout << "Usage: scim-im-agent [options]" << endl;
                 cout << " Options" << endl << endl;
                 cout << " -h, --help\tGive this help list" << endl;
                 cout << " -v, --verbose\tVerbosely print out the debug message into standard output.This option equals to '--debuglevel=6'" << endl;
                 cout << " -q, --quiet\tMake it print no debug message at all.This option equals to '--debuglevel=0" << endl;
                 cout << " -l, --debuglevel\tSet how verbosely should it print debug output.'--debuglevel=0' equals to '--queit', and '--debuglevel=9' equals to '--verbose'" << endl;
-                cout << " -s, --standalone\tGiven this, scim-brige-agent won't daemonize itself." << endl;
-                cout << " -n, --noexit\tGiven this, scim-brige-agent won't exit when there is no client." << endl;
+                cout << " -s, --standalone\tGiven this, scim-im-agent won't daemonize itself." << endl;
+                cout << " -n, --noexit\tGiven this, scim-im-agent won't exit when there is no client." << endl;
                 exit (0);
                 break;
             case ':':
