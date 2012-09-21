$NetBSD: patch-src_logmill.cpp,v 1.1 2012/09/21 11:28:44 ryoon Exp $

--- src/logmill.cpp.orig	2012-04-20 01:52:29.000000000 +0000
+++ src/logmill.cpp
@@ -176,7 +176,7 @@ RCommitLog* RLogMill::fetchLog(std::stri
                     logfile = repo_path.string();
                 }
             }
-        } catch(boost::filesystem3::filesystem_error& error) {
+        } catch(boost::filesystem::filesystem_error& error) {
         }
     }
 
