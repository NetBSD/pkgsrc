$NetBSD: patch-netmenu_NMnetlist.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- netmenu/NMnetlist.c.orig	2006-04-10 22:03:14.000000000 +0000
+++ netmenu/NMnetlist.c
@@ -216,9 +216,8 @@ NMAddTerm(new, other)
  * ----------------------------------------------------------------------------
  */
 
-int
-NMDeleteTerm(name)
-    char *name;			/* Name of a terminal. */
+void
+NMDeleteTerm(char *name)
 {
     HashEntry *h;
     NetEntry *entry;
@@ -256,10 +255,8 @@ NMDeleteTerm(name)
  * ----------------------------------------------------------------------------
  */
 
-int
-NMJoinNets(termA, termB)
-    char *termA;		/* Name of a terminal in first net. */
-    char *termB;		/* Name of a terminal in second net. */
+void
+NMJoinNets(char *termA, char *termB)
 {
     HashEntry *ha, *hb;
     NetEntry *netA, *netB, *tmp;
@@ -327,11 +324,8 @@ NMJoinNets(termA, termB)
  * ----------------------------------------------------------------------------
  */
 
-int
-NMDeleteNet(net)
-    char *net;			/* Name of one of the terminals in the net
-				 * to be deleted.
-				 */
+void
+NMDeleteNet(char *net)
 {
     HashEntry *h;
     NetEntry *ne, *next;
@@ -377,12 +371,8 @@ NMDeleteNet(net)
  * ----------------------------------------------------------------------------
  */
 
-int
-NMNewNetlist(name)
-    char *name;			/* Name of the netlist file.  If NULL,
-				 * then the netlist file association
-				 * is eliminated.
-				 */
+void
+NMNewNetlist(char *name)
 {
     Netlist *new;
     FILE *file;
@@ -741,13 +731,8 @@ NMTermInList(name)
  * ----------------------------------------------------------------------------
  */
 
-int
-NMWriteNetlist(fileName)
-    char *fileName;		/* If non-NULL, gives name of file in
-				 * which to write current netlist.  If NULL,
-				 * the netlist gets written to the place
-				 * from which it was read.
-				 */
+void
+NMWriteNetlist(char *fileName)
 {
     FILE *file;
     int nmWriteNetsFunc();
@@ -876,8 +861,8 @@ NMCheckWritten()
  * ----------------------------------------------------------------------------
  */
 
-int
-NMWriteAll()
+void
+NMWriteAll(void)
 {
     Netlist *nl, *saveCurrent;
     static char *(options[]) = {"write", "skip", "abort", NULL};
