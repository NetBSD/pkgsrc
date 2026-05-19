$NetBSD: patch-options.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- options.c.orig	2026-05-16 21:28:35.620014816 +0000
+++ options.c
@@ -7,7 +7,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "nn.h"
@@ -124,7 +124,7 @@ parse_options(int ac, char **av, char *e
 next_option:
 
     if (envinit) {
-	while (*cp && isspace(*cp))
+	while (*cp && ISSPACE(*cp))
 	    cp++;
 	if (*cp == '-') {
 	    cp++;
@@ -175,7 +175,7 @@ next_option:
 
 		/* -oSTR or -o STR */
 
-		while (*cp && isspace(*cp))
+		while (*cp && ISSPACE(*cp))
 		    cp++;
 
 		if (*cp == NUL) {
@@ -194,7 +194,7 @@ next_option:
 		*(od->option_address) = cp;
 
 		if (envinit) {
-		    while (*cp && !isspace(*cp))
+		    while (*cp && !ISSPACE(*cp))
 			cp++;
 		    if (*cp)
 			*cp++ = NUL;
@@ -212,17 +212,17 @@ next_option:
 
 		/* -oN or -o N */
 
-		while (*cp && isspace(*cp))
+		while (*cp && ISSPACE(*cp))
 		    cp++;
 
 		if (*cp) {
-		    if (!isdigit(*cp)) {
+		    if (!ISDIGIT(*cp)) {
 			if (od->option_type == 5)
 			    goto opt_int;
 			error("non-numeric argument to -%c", opt);
 		    }
 		} else {
-		    if (envinit || ac == 0 || !isdigit(**av)) {
+		    if (envinit || ac == 0 || !ISDIGIT(**av)) {
 			if (od->option_type == 5)
 			    goto opt_int;
 			error("missing argument to -%c", opt);
@@ -231,7 +231,7 @@ next_option:
 		    ac--;
 		}
 		*((int *) (od->option_address)) = atoi(cp);
-		while (isdigit(*cp))
+		while (ISDIGIT(*cp))
 		    cp++;
 		goto next_option;
 
