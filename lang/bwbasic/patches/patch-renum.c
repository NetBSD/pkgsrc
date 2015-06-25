$NetBSD: patch-renum.c,v 1.1 2015/06/25 07:52:13 dholland Exp $

- don't use gets()

--- renum.c~	2015-01-21 03:55:10.000000000 +0000
+++ renum.c
@@ -17,6 +17,18 @@ int f2, l2, n, x;
 int sidx[1500][2];
 char rstr[255];
 
+static void dogets(char *buf, size_t max)
+{
+   size_t len;
+
+   fgets(buf, max, stdin);
+   len = strlen(buf);
+   if (len > 0 && buf[len - 1] == '\n')
+   {
+      buf[len - 1] = '\0';
+   }
+}
+
 main(argc, argv)
    int argc;
    char *argv[];
@@ -34,7 +46,7 @@ main(argc, argv)
    else
    {
       printf("Program in file? ");
-      gets(pstr);
+      dogets(pstr, sizeof(pstr));
    }
    if (strlen(pstr) == 0) strcpy(pstr, "0.doc");
 
@@ -124,7 +136,7 @@ main(argc, argv)
       skip = 0;
       bp = 0;
       printf("RENUMBER-");
-      gets(pstr);
+      dogets(pstr, sizeof(pstr));
       p = strlen(pstr);
 
       if (g == 0)
@@ -268,7 +280,7 @@ main(argc, argv)
       printf("%d -> %d\n", sidx[r][0], sidx[r][1]); */
 
    printf("VERIFY? ");
-   gets(pstr);
+   dogets(pstr, sizeof(pstr));
    v1 = 0;
    if (strcmp(midstr2(pstr, 1, 1), "N") == 0) v1 = 1;
 
