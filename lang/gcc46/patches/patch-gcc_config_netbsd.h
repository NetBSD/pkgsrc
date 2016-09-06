$NetBSD: patch-gcc_config_netbsd.h,v 1.1 2016/09/06 13:57:02 maya Exp $

when using shared, link against libc.

--- gcc/config/netbsd.h.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/config/netbsd.h
@@ -96,6 +96,7 @@ along with GCC; see the file COPYING3.  
        %{!pg:-lposix}}		\
      %{p:-lposix_p}		\
      %{pg:-lposix_p}}		\
+   %{shared:-lc}		\
    %{!shared:			\
      %{!symbolic:		\
        %{!p:			\
@@ -109,6 +110,7 @@ along with GCC; see the file COPYING3.  
        %{!pg:-lposix}}		\
      %{p:-lposix_p}		\
      %{pg:-lposix_p}}		\
+   %{shared:-lc}		\
    %{!shared:			\
      %{!symbolic:		\
        %{!p:			\
