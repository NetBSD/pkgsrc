$NetBSD: patch-dlib_interposition.c,v 1.1 2019/02/09 19:51:09 rhialto Exp $

o Do not use ssp(3) when compiling interposition.c:

    interposition.c:1728:1: error: redefinition of 'read'
     read(d, buf, nbytes)
     ^
    In file included from /usr/include/ssp/stdio.h:34:0,
		     from /usr/include/stdio.h:597,
		     from ../include/osdep.h:158,
		     from ../include/common.h:56,
		     from interposition.c:47:
    /usr/include/ssp/unistd.h:39:1: note: previous definition of 'read' was here
     __ssp_redirect0(ssize_t, read, (int __fd, void *__buf, size_t __len), \
     ^

--- dlib/interposition.c.orig	2017-01-31 08:17:38.000000000 +0000
+++ dlib/interposition.c
@@ -1,3 +1,4 @@
+#undef _FORTIFY_SOURCE
 /*
  * Copyright (c) 1997, 1998, 1999, 2000, 2001, 2004, 2008, 2009, 2010, 2011,
  *               2012, 2013, 2016, 2017
