$NetBSD: patch-res_ael_pval.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- res/ael/pval.c.orig	2018-05-07 17:37:44.116772314 +0000
+++ res/ael/pval.c
@@ -855,7 +855,7 @@ static void check_timerange(pval *p)
 	}
 	*e = '\0';
 	e++;
-	while (*e && !isdigit(*e))
+	while (*e && !isdigit((unsigned char)*e))
 		e++;
 	if (!*e) {
 		ast_log(LOG_WARNING, "Warning: file %s, line %d-%d: The time range format (%s) is missing the end time!\n",
@@ -3531,11 +3531,11 @@ static int gen_prios(struct ael_extensio
 				for_init->appargs = strdup(buf2);
 			} else {
 				strp2 = p->u1.for_init;
-				while (*strp2 && isspace(*strp2))
+				while (*strp2 && isspace((unsigned char)*strp2))
 					strp2++;
 				if (*strp2 == '&') { /* itsa macro call */
 					char *strp3 = strp2+1;
-					while (*strp3 && isspace(*strp3))
+					while (*strp3 && isspace((unsigned char)*strp3))
 						strp3++;
 					strcpy(buf2, strp3);
 					strp3 = strchr(buf2,'(');
@@ -3581,11 +3581,11 @@ static int gen_prios(struct ael_extensio
 				for_inc->app = strdup("MSet");
 			} else {
 				strp2 = p->u3.for_inc;
-				while (*strp2 && isspace(*strp2))
+				while (*strp2 && isspace((unsigned char)*strp2))
 					strp2++;
 				if (*strp2 == '&') { /* itsa macro call  */
 					char *strp3 = strp2+1;
-					while (*strp3 && isspace(*strp3))
+					while (*strp3 && isspace((unsigned char)*strp3))
 						strp3++;
 					strcpy(buf2, strp3);
 					strp3 = strchr(buf2,'(');
