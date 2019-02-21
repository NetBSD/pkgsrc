$NetBSD: patch-vdcomp.c,v 1.1 2019/02/21 14:32:32 tsutsui Exp $

- don't use malloc.h

--- vdcomp.c.orig	2019-02-21 14:07:37.726880361 +0000
+++ vdcomp.c
@@ -96,41 +96,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-/* include a malloc.h of some sort (if needed...most systems use stdlib.h) */
-#ifndef VMS   /* VMS hates multi-line "#if"s */
-   /*
-    * I want to use BSD macro for checking if this OS is *BSD or not,
-    * but the macro is defined in <sys/parm.h>, which I don't know all
-    * machine has or not.
-    */
-#  if !defined(ibm032)                    && \
-      !defined(__convex__)                && \
-      !(defined(vax) && !defined(ultrix)) && \
-      !defined(mips)                      && \
-      !defined(apollo)                    && \
-      !defined(pyr)                       && \
-      !defined(sequent)                   && \
-      !defined(__UMAXV__)                 && \
-      !defined(aux)                       && \
-      !defined(bsd43)                     && \
-      !defined(__bsd43)                   && \
-      !defined(__bsdi__)                  && \
-      !defined(__386BSD__)                && \
-      !defined(__FreeBSD__)               && \
-      !defined(__OpenBSD__)               && \
-      !defined(__NetBSD__)                && \
-      !defined(__DARWIN__)
-
-#    if defined(hp300) || defined(hp800) || defined(NeXT)
-#      include <sys/malloc.h>    /* it's in "sys" on HPs and NeXT */
-#    else
-#      include <malloc.h>        /* FIXME: should explicitly list systems that NEED this, not everyone that doesn't */
-#    endif
-
-#  endif /* !most modern systems */
-#endif /* !VMS */
-
-
 #include <X11/Xos.h>
 
 #define TRUE         1
