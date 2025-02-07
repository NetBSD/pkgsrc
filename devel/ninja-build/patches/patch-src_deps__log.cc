$NetBSD: patch-src_deps__log.cc,v 1.1 2025/02/07 16:00:27 tsutsui Exp $

- avoid allocating 512KB on stack.
  The upstream claims systems that cannot allocate 512KB on stack
  should not use ninja:
  https://github.com/ninja-build/ninja/issues/2567

--- src/deps_log.cc.orig	2025-02-07 13:51:02.703555493 +0000
+++ src/deps_log.cc
@@ -151,7 +151,8 @@ void DepsLog::Close() {
 
 LoadStatus DepsLog::Load(const string& path, State* state, string* err) {
   METRIC_RECORD(".ninja_deps load");
-  char buf[kMaxRecordSize + 1];
+  vector<char> vbuf(kMaxRecordSize + 1);
+  char *buf = &vbuf[0];
   FILE* f = fopen(path.c_str(), "rb");
   if (!f) {
     if (errno == ENOENT)
@@ -162,7 +163,7 @@ LoadStatus DepsLog::Load(const string& p
 
   bool valid_header = true;
   int version = 0;
-  if (!fgets(buf, sizeof(buf), f) || fread(&version, 4, 1, f) < 1)
+  if (!fgets(buf, vbuf.size(), f) || fread(&version, 4, 1, f) < 1)
     valid_header = false;
   // Note: For version differences, this should migrate to the new format.
   // But the v1 format could sometimes (rarely) end up with invalid data, so
