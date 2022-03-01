$NetBSD: patch-qmail-qfilter.c,v 1.4 2022/03/01 19:15:38 schmonz Exp $

Apply all upstream changes since 2.1 (aff0c4a) through master (795718f).

--- qmail-qfilter.c.orig	2005-08-12 23:40:51.000000000 +0000
+++ qmail-qfilter.c
@@ -1,21 +1,5 @@
-/* Copyright (C) 2001,2004-2005 Bruce Guenter <bruceg@em.ca>
- *
- * This program is free software; you can redistribute it and/or modify
- * it under the terms of the GNU General Public License as published by
- * the Free Software Foundation; either version 2 of the License, or
- * (at your option) any later version.
- *
- * This program is distributed in the hope that it will be useful,
- * but WITHOUT ANY WARRANTY; without even the implied warranty of
- * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
- * GNU General Public License for more details.
- *
- * You should have received a copy of the GNU General Public License
- * along with this program; if not, write to the Free Software
- * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
- */
+/* This is free and unencumbered software released into the public * domain. */
 
-#include <sysdeps.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -332,6 +316,8 @@ int main(int argc, char* argv[])
   if ((qqargv[0] = getenv("QQF_QMAILQUEUE")) == 0)
     qqargv[0] = QMAIL_QUEUE;
 
+  mysetenvu("QMAILPPID", getppid());
+
   copy_fd(0, 0, &msg_len);
   copy_fd(1, ENVIN, &env_len);
   parse_envelope();
