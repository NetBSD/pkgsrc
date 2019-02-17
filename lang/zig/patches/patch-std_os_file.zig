$NetBSD: patch-std_os_file.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/os/file.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/os/file.zig
@@ -237,7 +237,7 @@ pub const File = struct {
 
     pub fn seekForward(self: File, amount: isize) SeekError!void {
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
                 const result = posix.lseek(self.handle, amount, posix.SEEK_CUR);
                 const err = posix.getErrno(result);
                 if (err > 0) {
@@ -268,7 +268,7 @@ pub const File = struct {
 
     pub fn seekTo(self: File, pos: usize) SeekError!void {
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
                 const ipos = try math.cast(isize, pos);
                 const result = posix.lseek(self.handle, ipos, posix.SEEK_SET);
                 const err = posix.getErrno(result);
@@ -309,7 +309,7 @@ pub const File = struct {
 
     pub fn getPos(self: File) GetSeekPosError!usize {
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
                 const result = posix.lseek(self.handle, 0, posix.SEEK_CUR);
                 const err = posix.getErrno(result);
                 if (err > 0) {
