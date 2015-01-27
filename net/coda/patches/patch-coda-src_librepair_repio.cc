$NetBSD: patch-coda-src_librepair_repio.cc,v 1.1 2015/01/27 15:21:52 hauke Exp $

SunOS has ERR #defined somewhere, rename goto label

--- ./coda-src/librepair/repio.cc.orig	2007-12-17 17:20:11.000000000 +0000
+++ ./coda-src/librepair/repio.cc
@@ -179,7 +179,7 @@ int repair_getdfile(char *fname, int inf
 
     if (replicaList == NULL) {
       sprintf(errmsg, "repair_getdfile: bad replicaList ptr!");
-      goto ERR;
+      goto Error;
     }
 
     if (fname == NULL) ff = fdopen(infd, "r");
@@ -195,14 +195,14 @@ int repair_getdfile(char *fname, int inf
     fread(&x, sizeof(int), 1, ff);
     if (ferror(ff) || feof(ff)) {
       sprintf(errmsg, "repair_getdfile: replicaCount parsing failed!");
-      goto ERR;
+      goto Error;
     }
     *replicaCount = ntohl(x);
 
     *replicaList = (struct listhdr *) calloc(*replicaCount, sizeof(struct listhdr));
     if (*replicaList == NULL) {
       sprintf(errmsg, "repair_getdfile: replicaList allocation failed!\n\telements= %x\tx= %d\tsizeof(struct listhdr)= %d\n", *replicaCount, x, sizeof(struct listhdr));
-      goto ERR;
+      goto Error;
     }
 
     perror("repair_getdfile: list created");
@@ -211,14 +211,14 @@ int repair_getdfile(char *fname, int inf
 	fread(&x, sizeof(int), 1, ff);
 	if (ferror(ff) || feof(ff)) {
 	  sprintf(errmsg, "repair_getdfile: fread failed!");
-	  goto ERR;
+	  goto Error;
 	}
 	(*replicaList)[i].replicaFid.Volume  = ntohl(x);
 
 	fread(&x, sizeof(int), 1, ff);
 	if (ferror(ff) || feof(ff)) {
 	  sprintf(errmsg, "repair_getdfile: fread failed!");
-	  goto ERR;
+	  goto Error;
 	}
 
 	(*replicaList)[i].repairCount  = ntohl(x);	
@@ -232,7 +232,7 @@ int repair_getdfile(char *fname, int inf
 					 sizeof(struct repair));
 	    if (!r) {
 	      sprintf(errmsg, "repair_getdfile: repair calloc failed!\n\tcount = %d\tsize = %d\n\n", (*replicaList)[i].repairCount, sizeof(struct repair));
-	      goto ERR;
+	      goto Error;
 	    }
 	    (*replicaList)[i].repairList = r;
 	}
@@ -245,7 +245,7 @@ int repair_getdfile(char *fname, int inf
 	    fread(&x, sizeof(int), 1, ff);
 	    if (ferror(ff) || feof(ff)) {
 	      sprintf(errmsg, "repair_getdfile: fread failed!\n");
-	      goto ERR;
+	      goto Error;
 	    }
 	    r[j].opcode = ntohl(x);
 
@@ -253,7 +253,7 @@ int repair_getdfile(char *fname, int inf
 	    fgets(s, MAXNAMELEN, ff);
 	    if (ferror(ff) || feof(ff)) {
 	      sprintf(errmsg, "repair_getdfile: fread failed!\n");
-	      goto ERR;
+	      goto Error;
 	    }
 	    *(s + strlen(s) - 1) = 0;  /* nuke the '\n' left behind by fgets() */
 
@@ -261,7 +261,7 @@ int repair_getdfile(char *fname, int inf
 	    fgets(s, MAXNAMELEN, ff);
 	    if (ferror(ff) || feof(ff)) {
 	      sprintf(errmsg, "repair_getdfile: fread failed!\n");
-	      goto ERR;
+	      goto Error;
 	    }
 	    *(s + strlen(s) - 1) = 0;  /* nuke the '\n' left behind by fgets() */
 
@@ -269,7 +269,7 @@ int repair_getdfile(char *fname, int inf
 		fread(&x, sizeof(int), 1, ff);
 		if (ferror(ff) || feof(ff)) {
 		  sprintf(errmsg, "repair_getdfile: fread failed!\n");
-		  goto ERR;
+		  goto Error;
 		}
 		r[j].parms[k] = ntohl(x);
 	    }
@@ -283,7 +283,7 @@ int repair_getdfile(char *fname, int inf
 
     return(0);
 
- ERR: /* Error exit */
+ Error: /* Error exit */
     perror(errmsg);
     if(fname != NULL)
       fclose(ff);
