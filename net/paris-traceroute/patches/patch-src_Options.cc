$NetBSD: patch-src_Options.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/Options.cc.orig	2020-03-27 18:19:59.385262004 +0000
+++ src/Options.cc
@@ -95,26 +95,26 @@ Options::Options (int argc, char** argv)
 				set_log_level(ERROR);
         break;
       case 'h':   // help
-        log(DUMP, "Option : help");
+        mylog(DUMP, "Option : help");
         help();
         break;
       case 'V':   // version
-        log(DUMP, "Option : version");
+        mylog(DUMP, "Option : version");
         version();
         break;
       case 'f':   // first ttl
-        log(DUMP, "Option : first ttl, param = %s", optarg);
+        mylog(DUMP, "Option : first ttl, param = %s", optarg);
         ttl_initial = atoi(optarg);
         break;
       case 'F':
       	strncpy(targets, optarg, 32);
       	break;
       case 'm':   // max ttl
-        log(DUMP, "Option : max ttl, param = %s", optarg);
+        mylog(DUMP, "Option : max ttl, param = %s", optarg);
         ttl_max = atoi(optarg);
         break;
       case 'p':   // protocol
-        log(DUMP, "Option : protocol, param = %s", optarg);
+        mylog(DUMP, "Option : protocol, param = %s", optarg);
         strncpy(protocol, optarg, 5);
         
         if (strncmp(optarg, "icmp", 4) == 0) {
@@ -130,7 +130,7 @@ Options::Options (int argc, char** argv)
       	bandwidth = atoi(optarg);
       	break;
       case 's':   // source port
-        log(DUMP, "Option : source_port, param = %s", optarg);
+        mylog(DUMP, "Option : source_port, param = %s", optarg);
         if (strncmp(optarg, "pid", 3) == 0) {
         	// XXX at least we don't want to interfer with classic traceroute
   				proc_id = getpid() + 32768;
@@ -141,55 +141,55 @@ Options::Options (int argc, char** argv)
 				}
         break;
       case 'd':   // destination port
-        log(DUMP, "Option : dest_port, param = %s", optarg);
+        mylog(DUMP, "Option : dest_port, param = %s", optarg);
         dst_port = atoi(optarg);
         break;
       case 't':   // tos
-        log(DUMP, "Option : tos, param = %s", optarg);
+        mylog(DUMP, "Option : tos, param = %s", optarg);
         tos = atoi(optarg);
         break;
       case 'w':   // wait between probes
-        log(DUMP, "Option : w, param = %s", optarg);
+        mylog(DUMP, "Option : w, param = %s", optarg);
         delay_between_probes = atoi(optarg);
         break;
       case 'T':   // timeout for each probe
-        log(DUMP, "Option : timeout, param = %s", optarg);
+        mylog(DUMP, "Option : timeout, param = %s", optarg);
         timeout = atoi(optarg);
         break;
       case 'q':   // Number of tests before we consider a router down
-        log(DUMP, "Option : retry, param = %s", optarg);
+        mylog(DUMP, "Option : retry, param = %s", optarg);
         max_try = atoi(optarg);
         break;
       case 'r':
       	return_flow_id = atoi(optarg);
       	break;
       case 'M':   // Number of missing hop before stopping the traceroute
-        log(DUMP, "Option : missing_hop, param = %s", optarg);
+        mylog(DUMP, "Option : missing_hop, param = %s", optarg);
         max_missing = atoi(optarg);
         break;
       case 'a':
-        log(DUMP, "Option : algorithm, param = %s", optarg);
+        mylog(DUMP, "Option : algorithm, param = %s", optarg);
         strncpy(algo, optarg, 20);
         if (strncmp(algo, "help", 20) == 0) helpAlgo();
         break;
       case 'L':
-        log(DUMP, "Options : probe length, param = %s", optarg);
+        mylog(DUMP, "Options : probe length, param = %s", optarg);
         probe_length = atoi(optarg);
         break;
       case 'n':   // Print hop addresses numerically
-        log(DUMP, "Option : numeric = true");
+        mylog(DUMP, "Option : numeric = true");
         resolve_hostname = false;
         break;
       case 'i':   // Print the IP Id of the returned packet
-        log(DUMP, "Option : ipid = true");
+        mylog(DUMP, "Option : ipid = true");
         display_ipid = true;
         break;
       case 'l':   // Print the TTL of the returned packet
-        log(DUMP, "Option : print_ttl = true");
+        mylog(DUMP, "Option : print_ttl = true");
         display_ttl = true;
         break;
       case 'b':
-        log(DUMP, "Option : id_initial, param = %s", optarg);
+        mylog(DUMP, "Option : id_initial, param = %s", optarg);
         id_initial = atoi(optarg);
         break;
       case 'Z':
@@ -219,7 +219,7 @@ Options::Options (int argc, char** argv)
 
 	if (targets[0] == 0x00)
 	{
-	  log(DUMP, "dst_addr = %s", argv[optind]);
+	  mylog(DUMP, "dst_addr = %s", argv[optind]);
 	  if (argv[optind] == NULL) {
 	    help();
 	    exit(1);
@@ -337,20 +337,20 @@ Options::version () {
 
 void
 Options::dump () {
-  log(DUMP, "protocol     = %s", protocol);
-  log(DUMP, "src_add      = %s", src_addr);
-  log(DUMP, "dst_addr     = %s", dst_addr);
-  log(DUMP, "ttl_initial  = %d", ttl_initial);
-  log(DUMP, "ttl_max      = %d", ttl_max);
-  log(DUMP, "tos          = %d", tos);
-  log(DUMP, "probe_length = %d", probe_length);
-  log(DUMP, "algo         = %s", algo);
-  log(DUMP, "timeout      = %d", timeout);
-  log(DUMP, "delay        = %d", delay_between_probes);
-  log(DUMP, "max_try      = %d", max_try);
-  log(DUMP, "max_missing  = %d", max_missing);
-  log(DUMP, "id_initial   = %d", id_initial);
-  log(DUMP, "resolve      = %s", resolve_hostname ? "true" : "false");
-  log(DUMP, "ipid         = %s", display_ipid ? "true" : "false");
+  mylog(DUMP, "protocol     = %s", protocol);
+  mylog(DUMP, "src_add      = %s", src_addr);
+  mylog(DUMP, "dst_addr     = %s", dst_addr);
+  mylog(DUMP, "ttl_initial  = %d", ttl_initial);
+  mylog(DUMP, "ttl_max      = %d", ttl_max);
+  mylog(DUMP, "tos          = %d", tos);
+  mylog(DUMP, "probe_length = %d", probe_length);
+  mylog(DUMP, "algo         = %s", algo);
+  mylog(DUMP, "timeout      = %d", timeout);
+  mylog(DUMP, "delay        = %d", delay_between_probes);
+  mylog(DUMP, "max_try      = %d", max_try);
+  mylog(DUMP, "max_missing  = %d", max_missing);
+  mylog(DUMP, "id_initial   = %d", id_initial);
+  mylog(DUMP, "resolve      = %s", resolve_hostname ? "true" : "false");
+  mylog(DUMP, "ipid         = %s", display_ipid ? "true" : "false");
 }
 
