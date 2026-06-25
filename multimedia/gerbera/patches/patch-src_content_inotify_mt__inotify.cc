$NetBSD: patch-src_content_inotify_mt__inotify.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/content/inotify/mt_inotify.cc.orig	2026-06-25 08:07:25.541654487 +0000
+++ src/content/inotify/mt_inotify.cc
@@ -108,12 +108,12 @@ int Inotify::addWatch(const fs::path& path, InotifyFla
                 throw_fmt_system_error("The user limit on the total number of inotify watches was reached or the kernel failed to allocate a needed resource.");
             if (errno == EACCES) {
                 if (retryCount > 0) {
-                    log_debug("Retrying {} to add inotify watch for {}: {}", retryCount, path.c_str(), std::strerror(errno));
+                    log_debug("Retrying {} to add inotify watch for {}: {}", retryCount, path.c_str(), strerror(errno));
                     std::this_thread::sleep_for(std::chrono::milliseconds(100));
                     retryCount--;
                     continue;
                 } else {
-                    log_warning("Cannot add inotify watch for {}: {}", path.c_str(), std::strerror(errno));
+                    log_warning("Cannot add inotify watch for {}: {}", path.c_str(), strerror(errno));
                     return -1;
                 }
             }
@@ -128,7 +128,7 @@ void Inotify::removeWatch(int wd) const
 void Inotify::removeWatch(int wd) const
 {
     if (inotify_rm_watch(inotify_fd, wd) < 0) {
-        log_debug("Error removing watch: {}", std::strerror(errno));
+        log_debug("Error removing watch: {}", strerror(errno));
     }
 }
 
@@ -160,7 +160,7 @@ struct inotify_event* Inotify::nextEvent()
 
             // how much of the event do we have?
             bytes = reinterpret_cast<char*>(event.data()) + bytes - reinterpret_cast<char*>(ret);
-            std::memcpy(event.data(), ret, bytes);
+            memcpy(event.data(), ret, bytes);
             return nextEvent();
         }
         return ret;
@@ -196,7 +196,7 @@ struct inotify_event* Inotify::nextEvent()
     if (FD_ISSET(stop_fd_read, &readFds)) {
         char buf;
         if (read(stop_fd_read, &buf, 1) == -1) {
-            log_error("Inotify: could not read stop: {}", std::strerror(errno));
+            log_error("Inotify: could not read stop: {}", strerror(errno));
         }
     }
 
@@ -241,7 +241,7 @@ void Inotify::stop() const
 {
     char stop = 's';
     if (write(stop_fd_write, &stop, 1) == -1) {
-        log_error("inotify: could not send stop: {}", std::strerror(errno));
+        log_error("inotify: could not send stop: {}", strerror(errno));
     }
 }
 
