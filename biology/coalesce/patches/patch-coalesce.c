$NetBSD: patch-coalesce.c,v 1.1 2015/11/07 21:06:37 dholland Exp $

gets() considered harmful.

--- coalesce.c~	1996-02-29 16:00:09.000000000 +0000
+++ coalesce.c
@@ -70,6 +70,20 @@ void readparmfile()
 boolean		accept_slide;
 long		slid, slacc, indecks, chaintype;
 
+static void dogets(char *buf, size_t max)
+{
+   size_t len;
+
+   if (!fgets(buf, max, stdin)) {
+      *buf = '\0';
+      return;
+   }
+   len = strlen(buf);
+   if (len > 0 && buf[len-1] == '\n') {
+      buf[len-1] = '\0';
+   }
+}
+
 void openfile(FILE **fp, char *filename, char *mode, char *application,
    char *perm)
 {
@@ -88,7 +102,7 @@ void openfile(FILE **fp, char *filename,
         file[0] = '\0';
         while (file[0] =='\0'){
           fprintf(stdout,"Please enter a new filename>");
-          gets(file);
+          dogets(file, sizeof(file));
           }
         break;
       case 'w':
@@ -96,7 +110,7 @@ void openfile(FILE **fp, char *filename,
         file[0] = '\0';
         while (file[0] =='\0'){
           fprintf(stdout,"Please enter a new filename>");
-          gets(file);
+          dogets(file, sizeof(file));
           }
         break;
       }
@@ -775,7 +789,7 @@ void getoptions()
     }
     printf("\n");
     printf("Are these settings correct? (type Y or the letter for one to change)\n");
-    gets(input);
+    dogets(input, sizeof(input));
     ch = input[0];
     ch = toupper(ch);
     done = (ch == 'Y');
@@ -787,7 +801,7 @@ void getoptions()
 	case 'S':
 	  do {
 	    printf("How many Short Chains?\n");
-            gets(input);
+            dogets(input, sizeof(input));
             chains[0] = atoi(input);
 	    if (chains[0] < 0)
 	      printf("Must be non-negative\n");
@@ -797,7 +811,7 @@ void getoptions()
 	case 'L':
 	  do {
 	    printf("How many Long Chains?\n");
-            gets(input);
+            dogets(input, sizeof(input));
             chains[1] = atoi(input);
 	    if (chains[1] < 0)
 	      printf("Must be non-negative\n");
@@ -811,7 +825,7 @@ void getoptions()
 	  if (ctgry) {
 	    do {
 	      printf("Number of categories ?");
-              gets(input);
+              dogets(input, sizeof(input));
               categs = atoi(input);
 	    } while (categs < 1);
 	    free(rate);
@@ -869,7 +883,7 @@ void getoptions()
 	case 'T':
 	  do {
 	    printf("Transition/transversion ratio?\n");
-            gets(input);
+            dogets(input, sizeof(input));
             locus_ttratio = atof(input);
 	  } while (locus_ttratio < 0.0);
 	  break;
@@ -883,7 +897,7 @@ void getoptions()
 	  if (!watt) {
 	    do {
 	      printf("Initial theta estimate?\n");
-              gets(input);
+              dogets(input, sizeof(input));
               theta0 = atof(input);
 	    } while (theta0 <= 0.0);
 	  }
@@ -909,7 +923,7 @@ void getoptions()
 	  done1 = false;
 	  while (!done1) {
 	    printf("How often to sample trees?\n");
-            gets(input);
+            dogets(input, sizeof(input));
             increm[0] = atoi(input);
 	    if (increm[0] > 0)
 	      done1 = true;
@@ -922,7 +936,7 @@ void getoptions()
 	  done1 = false;
 	  while (!done1) {
 	    printf("How many short steps?\n");
-            gets(input);
+            dogets(input, sizeof(input));
             steps[0] = atoi(input);
 	    if (steps[0] > 0)
 	      done1 = true;
@@ -935,7 +949,7 @@ void getoptions()
 	  done1 = false;
 	  while (!done1) {
 	    printf("How often to sample trees?\n");
-            gets(input);
+            dogets(input, sizeof(input));
             increm[1] = atoi(input);
 	    if (increm[1] > 0)
 	      done1 = true;
@@ -948,7 +962,7 @@ void getoptions()
 	  done1 = false;
 	  while (!done1) {
 	    printf("How many long steps?\n");
-            gets(input);
+            dogets(input, sizeof(input));
             steps[1] = atoi(input);
 	    if (steps[1] > 0)
 	      done1 = true;
