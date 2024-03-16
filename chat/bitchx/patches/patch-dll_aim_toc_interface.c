$NetBSD: patch-dll_aim_toc_interface.c,v 1.1 2024/03/16 13:11:55 nia Exp $

Add a missing #include <string.h> for the strcpy declaration.

Upstream removed the plugin:

commit 35b1a65f03a2ca2dde31c9dbd77968587b6027d3
Author: Kevin Easton <caf@bitchx.org>
Date:   Sun Sep 6 23:33:36 2015 +1000

    Remove obsolete AIM plugin
    
    The servers for the TOC protocol used by this plugin were decomissioned
    by AOL in 2012, so it can't be used any longer.

--- dll/aim/toc/interface.c.orig	2008-02-25 09:49:14.000000000 +0000
+++ dll/aim/toc/interface.c
@@ -8,6 +8,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <time.h>
 #include "toc.h"
 
