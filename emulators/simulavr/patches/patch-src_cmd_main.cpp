$NetBSD: patch-src_cmd_main.cpp,v 1.1 2026/09/15 08:59:37 wiz Exp $

Avoid 'using namespace std'. This introduces a conflict between
std::byte and the local typedef.

--- src/cmd/main.cpp.orig	2026-09-15 08:53:05.702267801 +0000
+++ src/cmd/main.cpp
@@ -27,7 +27,6 @@
 #include <sstream>
 #include <string>
 #include <map>
-using namespace std;
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -66,21 +65,21 @@ const char *SplitOffsetFile(const char *arg,
     char *end;
     
     if(!StringToUnsignedLong(arg, offset, &end, base)) {
-        cerr << name << ": offset is not a number" << endl;
+        std::cerr << name << ": offset is not a number" << std::endl;
         exit(1);
     }
     //position behind the "," or any other delimiter for the offset
     if(!*end) {
-        cerr << name << ": argument ends before filename" << endl;
+        std::cerr << name << ": argument ends before filename" << std::endl;
         exit(1);
     }
     if(*end != ',') {
-        cerr << name << ": argument does not have comma before filename" << endl;
+        std::cerr << name << ": argument does not have comma before filename" << std::endl;
         exit(1);
     }
     ++end;
     if(!*end) {
-        cerr << name << ": argument has comma but no filename" << endl;
+        std::cerr << name << ": argument has comma but no filename" << std::endl;
         exit(1);
     }
     
@@ -133,9 +132,9 @@ int main(int argc, char *argv[]) {
 int main(int argc, char *argv[]) {
     int c;
     bool gdbserver_flag = 0;
-    string filename("unknown");
-    string devicename("unknown");
-    string tracefilename("unknown");
+    std::string filename("unknown");
+    std::string devicename("unknown");
+    std::string tracefilename("unknown");
     long global_gdbserver_port = 1212;
     int global_gdb_debug = 0;
     bool globalWaitForGdbConnection = true; //please wait for gdb connection
@@ -148,14 +147,14 @@ int main(int argc, char *argv[]) {
     unsigned long readFromPipeOffset = 0x21;
     unsigned long writeToAbort = 0;
     unsigned long writeToExit = 0;
-    string readFromPipeFileName = "";
-    string writeToPipeFileName = "";
+    std::string readFromPipeFileName = "";
+    std::string writeToPipeFileName = "";
     
-    vector<string> terminationArgs;
+    std::vector<std::string> terminationArgs;
     
-    vector<string> tracer_opts;
+    std::vector<std::string> tracer_opts;
     bool tracer_dump_avail = false;
-    string tracer_avail_out;
+    std::string tracer_avail_out;
     
     while (1) {
         //int this_option_optind = optind ? optind : 1;
@@ -209,25 +208,25 @@ int main(int argc, char *argv[]) {
             
             case 'a': // write to abort
                 if(!StringToUnsignedLong(optarg, &writeToAbort, NULL, 16)) {
-                    cerr << "writeToAbort is not a number" << endl;
+                    std::cerr << "writeToAbort is not a number" << std::endl;
                     exit(1);
                 }
                 break;
             
             case 'e': // write to exit
                 if(!StringToUnsignedLong(optarg, &writeToExit, NULL, 16)) {
-                    cerr << "writeToExit is not a number" << endl;
+                    std::cerr << "writeToExit is not a number" << std::endl;
                     exit(1);
                 }
                 break;
             
             case 'F':
                 if(!StringToUnsignedLongLong(optarg, &fcpu, NULL, 10)) {
-                    cerr << "frequency is not a number" << endl;
+                    std::cerr << "frequency is not a number" << std::endl;
                     exit(1);
                 }
                 if(fcpu == 0) {
-                    cerr << "frequency is zero" << endl;
+                    std::cerr << "frequency is zero" << std::endl;
                     exit(1);
                 }
                 if(global_verbose_on)
@@ -237,73 +236,73 @@ int main(int argc, char *argv[]) {
             
             case 'm':
                 if(!StringToUnsignedLongLong( optarg, &maxRunTime, NULL, 10)) {
-                    cerr << "maxRunTime is not a number" << endl;
+                    std::cerr << "maxRunTime is not a number" << std::endl;
                     exit(1);
                 }
                 if(maxRunTime == 0) {
-                    cerr << "maxRunTime is zero" << endl;
+                    std::cerr << "maxRunTime is zero" << std::endl;
                     exit(1);
                 }
                 if(global_verbose_on)
-                    cout << "Maximum Run Time: " << maxRunTime << endl;
+                    std::cout << "Maximum Run Time: " << maxRunTime << std::endl;
                 break;
             
             case 'u':
                 if(global_verbose_on)
-                    cout << "Run with User Interface at Port 7777" << endl;
+                    std::cout << "Run with User Interface at Port 7777" << std::endl;
                 userinterface_flag = 1;
                 break;
             
             case 'f':
                 if(global_verbose_on)
-                    cout << "File to load: " << optarg << endl;
+                    std::cout << "File to load: " << optarg << std::endl;
                 filename = optarg;
                 break;
             
             case 'd':
                 if(global_verbose_on)
-                    cout << "Device to simulate: " << optarg << endl;
+                    std::cout << "Device to simulate: " << optarg << std::endl;
                 devicename = optarg;
                 break;
             
             case 'g':
                 if(global_verbose_on)
-                    cout << "Running as gdb-server" << endl;
+                    std::cout << "Running as gdb-server" << std::endl;
                 gdbserver_flag = 1;
                 break;
             
             case 'G':
                 if(global_verbose_on)
-                    cout << "Running with debug information from gdbserver" << endl;
+                    std::cout << "Running with debug information from gdbserver" << std::endl;
                 global_gdb_debug = 1;
                 gdbserver_flag = 1;
                 break;
             
             case 'p':
                 if(!StringToLong( optarg, &global_gdbserver_port, NULL, 10)) {
-                    cerr << "GDB Server Port is not a number" << endl;
+                    std::cerr << "GDB Server Port is not a number" << std::endl;
                     exit(1);
                 }
                 if(global_verbose_on)
-                    cout << "Running on port: " << optarg << endl;
+                    std::cout << "Running on port: " << optarg << std::endl;
                 break;
             
             case 't':
                 if(global_verbose_on)
-                    cout << "Running in Trace Mode" << endl;
+                    std::cout << "Running in Trace Mode" << std::endl;
                 sysConHandler.SetTraceFile(optarg, 1000000);
                 break;
             
             case 'v':
-                cout << "SimulAVR " << VERSION << endl
-                     << "See documentation for copyright and distribution terms" << endl
-                     << endl;
+                std::cout << "SimulAVR " << VERSION << std::endl
+                     << "See documentation for copyright and distribution terms" << std::endl
+                     << std::endl;
                 exit(0);
                 break;
             
             case 'n':
-                cout << "We will NOT wait for a gdb connection, "
-                        "simulation starts now!" << endl;
+                std::cout << "We will NOT wait for a gdb connection, "
+                        "simulation starts now!" << std::endl;
                 globalWaitForGdbConnection = false;
                 break;
             
@@ -321,9 +320,9 @@ int main(int argc, char *argv[]) {
                 break;
             
             default:
-                cout << Usage
-                     << "Supported devices:" << endl
-                     << AvrFactory::supportedDevices() << endl;
+                std::cout << Usage
+                     << "Supported devices:" << std::endl
+                     << AvrFactory::supportedDevices() << std::endl;
                 exit(0);
         }
     }
@@ -346,39 +345,39 @@ int main(int argc, char *argv[]) {
     SetDumpTraceArgs(tracer_opts, dev1);
     
     if(!gdbserver_flag && filename == "unknown") {
-        cerr << "Specify either --file <executable> or --gdbserver (or --gdb-stdin)" << endl;
+        std::cerr << "Specify either --file <executable> or --gdbserver (or --gdb-stdin)" << std::endl;
         exit(1);
     }
     
     //if we want to insert some special "pipe" Registers we could do this here:
     if(readFromPipeFileName != "") {
         if(global_verbose_on)
-            cout << "Add ReadFromPipe-Register at 0x"
-                 << hex << readFromPipeOffset
-                 << " and read from file: " << readFromPipeFileName << endl;
+            std::cout << "Add ReadFromPipe-Register at 0x"
+                 << std::hex << readFromPipeOffset
+                 << " and read from file: " << readFromPipeFileName << std::endl;
         dev1->ReplaceIoRegister(readFromPipeOffset,
             new RWReadFromFile(dev1, "FREAD", readFromPipeFileName.c_str()));
     }
     
     if(writeToPipeFileName != "") {
         if(global_verbose_on)
-            cout << "Add WriteToPipe-Register at 0x"
-                 << hex << writeToPipeOffset
-                 << " and write to file: " << writeToPipeFileName << endl;
+            std::cout << "Add WriteToPipe-Register at 0x"
+                 << std::hex << writeToPipeOffset
+                 << " and write to file: " << writeToPipeFileName << std::endl;
         dev1->ReplaceIoRegister(writeToPipeOffset,
             new RWWriteToFile(dev1, "FWRITE", writeToPipeFileName.c_str()));
     }
     
     if(writeToAbort) {
         if(global_verbose_on)
-            cout << "Add WriteToAbort-Register at 0x" << hex
-                 << writeToAbort << endl;
+            std::cout << "Add WriteToAbort-Register at 0x" << std::hex
+                 << writeToAbort << std::endl;
         dev1->ReplaceIoRegister(writeToAbort, new RWAbort(dev1, "ABORT"));
     }
     
     if(writeToExit) {
         if(global_verbose_on)
-            cout << "Add WriteToExit-Register at 0x" << hex << writeToExit << endl;
+            std::cout << "Add WriteToExit-Register at 0x" << std::hex << writeToExit << std::endl;
         dev1->ReplaceIoRegister(writeToExit, new RWExit(dev1, "EXIT"));
     }
     
@@ -387,10 +386,10 @@ int main(int argc, char *argv[]) {
     }
     
     //if we have a file we can check out for termination lines.
-    vector<string>::iterator ii;
+    std::vector<std::string>::iterator ii;
     for(ii = terminationArgs.begin(); ii != terminationArgs.end(); ii++) {
         if(global_verbose_on)
-            cout << "Termination or Breakpoint Symbol: " << *ii << endl;
+            std::cout << "Termination or Breakpoint Symbol: " << *ii << std::endl;
         dev1->RegisterTerminationSymbol((*ii).c_str());
     }
     
@@ -413,7 +412,7 @@ int main(int argc, char *argv[]) {
         }
     } else { // gdb should be activated
         if(global_verbose_on)
-            cout << "Going to gdb..." << endl;
+            std::cout << "Going to gdb..." << std::endl;
         GdbServer gdb1(dev1, global_gdbserver_port, global_gdb_debug, globalWaitForGdbConnection);
         SystemClock::Instance().Add(&gdb1);
         SystemClock::Instance().Endless();
