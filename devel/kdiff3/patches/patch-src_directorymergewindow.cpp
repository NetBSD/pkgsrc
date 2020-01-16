$NetBSD: patch-src_directorymergewindow.cpp,v 1.1 2020/01/16 02:37:30 gutteridge Exp $

kdiff3 fails to close files properly leading to stability and speed issues.
Patches via Fedora:
https://src.fedoraproject.org/rpms/kdiff3/c/8a700c10780b157e681637404e97718f5ba0cff2
https://src.fedoraproject.org/rpms/kdiff3/c/bc38b46ef5c96b2b7800e1195b3895527bceea65

--- src/directorymergewindow.cpp.orig	2019-05-18 01:01:30.000000000 +0000
+++ src/directorymergewindow.cpp
@@ -741,6 +741,7 @@ bool DirectoryMergeWindow::DirectoryMerg
 
     if(!fi2.open(QIODevice::ReadOnly))
     {
+        fi1.close();
         status = fi2.errorString();
         return bEqual;
     }
@@ -758,17 +759,23 @@ bool DirectoryMergeWindow::DirectoryMerg
         if(len != fi1.read(&buf1[0], len))
         {
             status = fi1.errorString();
+            fi1.close();
+            fi2.close();
             return bEqual;
         }
 
         if(len != fi2.read(&buf2[0], len))
         {
-            status = fi2.errorString();;
+            status = fi2.errorString();
+            fi1.close();
+            fi2.close();
             return bEqual;
         }
 
         if(memcmp(&buf1[0], &buf2[0], len) != 0)
         {
+            fi1.close();
+            fi2.close();
             bError = false;
             return bEqual;
         }
@@ -780,6 +787,9 @@ bool DirectoryMergeWindow::DirectoryMerg
     // If the program really arrives here, then the files are really equal.
     bError = false;
     bEqual = true;
+
+    fi1.close();
+    fi2.close();
     return bEqual;
 }
 
