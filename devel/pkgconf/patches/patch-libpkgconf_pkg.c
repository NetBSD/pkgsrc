$NetBSD: patch-libpkgconf_pkg.c,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- libpkgconf/pkg.c.orig	2023-01-21 21:27:30.000000000 +0000
+++ libpkgconf/pkg.c
@@ -857,9 +857,9 @@ pkgconf_compare_version(const char *a, c
 
 	while (*one || *two)
 	{
-		while (*one && !isalnum((unsigned int)*one) && *one != '~')
+		while (*one && !isalnum((unsigned char)*one) && *one != '~')
 			one++;
-		while (*two && !isalnum((unsigned int)*two) && *two != '~')
+		while (*two && !isalnum((unsigned char)*two) && *two != '~')
 			two++;
 
 		if (*one == '~' || *two == '~')
@@ -880,22 +880,22 @@ pkgconf_compare_version(const char *a, c
 		str1 = one;
 		str2 = two;
 
-		if (isdigit((unsigned int)*str1))
+		if (isdigit((unsigned char)*str1))
 		{
-			while (*str1 && isdigit((unsigned int)*str1))
+			while (*str1 && isdigit((unsigned char)*str1))
 				str1++;
 
-			while (*str2 && isdigit((unsigned int)*str2))
+			while (*str2 && isdigit((unsigned char)*str2))
 				str2++;
 
 			isnum = true;
 		}
 		else
 		{
-			while (*str1 && isalpha((unsigned int)*str1))
+			while (*str1 && isalpha((unsigned char)*str1))
 				str1++;
 
-			while (*str2 && isalpha((unsigned int)*str2))
+			while (*str2 && isalpha((unsigned char)*str2))
 				str2++;
 
 			isnum = false;
