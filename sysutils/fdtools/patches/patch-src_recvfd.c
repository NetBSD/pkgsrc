$NetBSD: patch-src_recvfd.c,v 1.1 2017/10/03 00:43:22 schmonz Exp $

Avoid "invalid operands to binary expression" with clang.

--- src/recvfd.c.orig	2015-03-16 06:02:40.000000000 +0000
+++ src/recvfd.c
@@ -65,7 +65,8 @@ int main(int argc, char** argv) {
     if (named_fd<10) {
       type_fd duped=fcntl(named_fd, F_DUPFD, 10);
       if (duped<0) DIE0(dup);
-      if (fd_close(named_fd)!=0) DIE1(close, "descriptor");
+      //if (fd_close(named_fd)!=0) DIE1(close, "descriptor");
+      fd_close(named_fd);
       named_fd=duped;
     }
     buf[int_fmt(buf, named_fd)]='\0';
