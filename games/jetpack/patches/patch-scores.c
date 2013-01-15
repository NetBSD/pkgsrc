$NetBSD: patch-scores.c,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- scores.c.orig	1992-03-29 19:41:16.000000000 +0000
+++ scores.c
@@ -30,12 +30,12 @@ int		dialogwidth, dialogheight;
 /*	open_scores tries to open the score file, and if it can't it tries to
 	create one.
 */
-open_scores()
+void open_scores(void)
 {
 	numhighs = 0;
 	scorefd = open(SCOREPATH, O_RDWR);
 	if(scorefd == -1) {
-		scorefd = open(SCOREPATH, O_RDWR | O_CREAT, 0444);
+		scorefd = open(SCOREPATH, O_RDWR | O_CREAT, 0644);
 		if(scorefd == -1) {
 			scorefd = open("jetpack.scores", O_RDWR);
 			if(scorefd == -1) {
@@ -133,7 +133,7 @@ read_new_scores()
 	table, and if it makes it, gets the player's name and saves the new
 	high scores in the file.
 */
-check_score()
+void check_score(void)
 {
 	register int	i, spot;
 	char			buf[MAXNAMELENGTH];
