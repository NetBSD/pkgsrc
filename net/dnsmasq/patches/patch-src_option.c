$NetBSD: patch-src_option.c,v 1.1 2023/02/25 03:30:47 riastradh Exp $

Fix ctype(3) misuse.

--- src/option.c.orig	2023-02-02 20:24:24.000000000 +0000
+++ src/option.c
@@ -2751,7 +2751,7 @@ static int one_opt(int option, char *arg
 		ret_err(gen_err);
 	      
 	      for (p = arg; *p; p++)
-		if (!isxdigit((int)*p))
+		if (!isxdigit((unsigned char)*p))
 		  ret_err(gen_err);
 	      
 	      set_option_bool(OPT_UMBRELLA_DEVID);
@@ -4836,7 +4836,7 @@ err:
 	    new->target = target;
 	    new->ttl = ttl;
 
-	    for (arg += arglen+1; *arg && isspace(*arg); arg++);
+	    for (arg += arglen+1; *arg && isspace((unsigned char)*arg); arg++);
 	  }
       
 	break;
@@ -5227,7 +5227,7 @@ err:
 	unhide_metas(keyhex);
 	/* 4034: "Whitespace is allowed within digits" */
 	for (cp = keyhex; *cp; )
-	  if (isspace(*cp))
+	  if (isspace((unsigned char)*cp))
 	    for (cp1 = cp; *cp1; cp1++)
 	      *cp1 = *(cp1+1);
 	  else
@@ -5315,7 +5315,7 @@ static void read_file(char *file, FILE *
 	      memmove(p, p+1, strlen(p+1)+1);
 	    }
 
-	  if (isspace(*p))
+	  if (isspace((unsigned char)*p))
 	    {
 	      *p = ' ';
 	      white = 1;
