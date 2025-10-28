$NetBSD: patch-src_bin_edje__cc__sources.c,v 1.1 2025/10/28 00:24:02 gutteridge Exp $

Use ctype.h correctly.

--- src/bin/edje_cc_sources.c.orig	2013-07-30 14:42:43.000000000 +0000
+++ src/bin/edje_cc_sources.c
@@ -103,7 +103,7 @@ source_fetch_file(const char *fil, const
 	  {
 	     if (!got_hash)
 	       {
-		  if (!isspace(*p))
+		  if (!isspace((unsigned char)*p))
 		    {
 		       if (*p == '#')
 			 got_hash = 1;
@@ -115,7 +115,7 @@ source_fetch_file(const char *fil, const
 
 	     if (!haveinclude)
 	       {
-		  if (!isspace(*p))
+		  if (!isspace((unsigned char)*p))
 		    {
 		       if (!strncmp(p, "include", 7))
 			 {
@@ -140,7 +140,7 @@ source_fetch_file(const char *fil, const
 	       }
 	     else
 	       {
-		  if (!isspace(*p))
+		  if (!isspace((unsigned char)*p))
 		    {
 		       char end = '\0';
 
