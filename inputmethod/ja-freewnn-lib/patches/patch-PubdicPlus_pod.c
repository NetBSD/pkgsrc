$NetBSD: patch-PubdicPlus_pod.c,v 1.4 2026/07/10 23:32:37 tsutsui Exp $

- Appease -Wincompatible-pointer-types that are fatal on gcc14 and later
- Add a proper function prototype declaration

--- PubdicPlus/pod.c.orig	2005-12-10 18:50:43.000000000 +0000
+++ PubdicPlus/pod.c
@@ -154,17 +154,18 @@ static struct descpack *searchdesc (Wcha
 static void store_description (void);
 static long internkind (Wchar *s);
 static void listkinds (void);
-static int kindcompar (struct kindpack *k1, struct kindpack *k2);
+static int kindcompar (const void *k1, const void *k2);
 static void sortkind (void);
 static struct dicpack *intern (int key, Wchar *yomi, Wchar *kouho, Wchar *hinshi, int hindo, long kind, int *stat, long flags);
+static void for_all_interned (void (*fn)(struct dicpack *));
 static void storepd (FILE *file);
 static void comparepd (FILE *file);
 static void canna_output (FILE *cf, struct dicpack *p, Wchar *h, int n);
 static void entry_out (FILE *cf, struct dicpack *p, Wchar *h, int n, Wchar *ex);
 static void printentry (FILE *cf, struct dicpack *p);
 static void showentry (struct dicpack **pd, int n);
-static int diccompar (struct dicpack **p1, struct dicpack **p2);
-static int dichindocompar (struct dicpack **p1, struct dicpack **p2);
+static int diccompar (const void *p1, const void *p2);
+static int dichindocompar (const void *p1, const void *p2);
 void shrinkargs (char **argv, int n, int count);
 static void parseargs (int argc, char *argv[]);
 #endif
@@ -823,9 +824,11 @@ listkinds ()
 
 static int
 kindcompar (k1, k2)
-     struct kindpack *k1, *k2;
+     const void *k1, *k2;
 {
-  return Wscmp (k1->kind, k2->kind);
+  const struct kindpack *kp1 = k1;
+  const struct kindpack *kp2 = k2;
+  return Wscmp (kp1->kind, kp2->kind);
 }
 
 static void
@@ -978,8 +981,7 @@ intern (key, yomi, kouho, hinshi, hindo,
 /* 登録されているエントリに対して fn を実行する */
 
 static void
-for_all_interned (fn)
-     void (*fn) ();
+for_all_interned (void (*fn)(struct dicpack *))
 {
   int i;
   struct dicpack *p;
@@ -1365,18 +1367,20 @@ showentry (pd, n)
 
 static int
 diccompar (p1, p2)
-     struct dicpack **p1, **p2;
+     const void *p1, *p2;
 {
   int n;
-  if (n = Wscmp ((*p1)->yomi, (*p2)->yomi))
+  const struct dicpack * const *dp1 = p1;
+  const struct dicpack * const *dp2 = p2;
+  if (n = Wscmp ((*dp1)->yomi, (*dp2)->yomi))
     {
       return n;
     }
-  else if (n = Wscmp ((*p1)->tango, (*p2)->tango))
+  else if (n = Wscmp ((*dp1)->tango, (*dp2)->tango))
     {
       return n;
     }
-  else if (n = Wscmp ((*p1)->hinshi->hinshi, (*p2)->hinshi->hinshi))
+  else if (n = Wscmp ((*dp1)->hinshi->hinshi, (*dp2)->hinshi->hinshi))
     {
       return n;
     }
@@ -1388,22 +1392,24 @@ diccompar (p1, p2)
 
 static int
 dichindocompar (p1, p2)
-     struct dicpack **p1, **p2;
+     const void *p1, *p2;
 {
   int n;
-  if (n = Wscmp ((*p1)->yomi, (*p2)->yomi))
+  const struct dicpack * const *dp1 = p1;
+  const struct dicpack * const *dp2 = p2;
+  if (n = Wscmp ((*dp1)->yomi, (*dp2)->yomi))
     {
       return n;
     }
-  else if (n = ((*p2)->hindo - (*p1)->hindo))
+  else if (n = ((*dp2)->hindo - (*dp1)->hindo))
     {
       return n;
     }
-  else if (n = Wscmp ((*p1)->tango, (*p2)->tango))
+  else if (n = Wscmp ((*dp1)->tango, (*dp2)->tango))
     {
       return n;
     }
-  else if (n = Wscmp ((*p1)->hinshi->hinshi, (*p2)->hinshi->hinshi))
+  else if (n = Wscmp ((*dp1)->hinshi->hinshi, (*dp2)->hinshi->hinshi))
     {
       return n;
     }
