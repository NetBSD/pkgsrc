$NetBSD: patch-sys_default_tty.c,v 1.1 2013/03/28 21:24:54 joerg Exp $

--- sys/default/tty.c.orig	2013-03-28 19:10:58.000000000 +0000
+++ sys/default/tty.c
@@ -272,7 +272,7 @@ ttbeep() {
  * If no scrolling region, use a set
  * of insert and delete line sequences
  */
-ttinsl(row, bot, nchunk) {
+void ttinsl(row, bot, nchunk) {
 	register int	i, nl;
 
 	if (row == bot) {		/* Case of one line insert is	*/
@@ -311,7 +311,7 @@ ttinsl(row, bot, nchunk) {
  * lines.  The presence of the echo area makes a
  * boundry condition go away.
  */
-ttdell(row, bot, nchunk)
+void ttdell(row, bot, nchunk)
 {
 	register int	i, nl;
 
