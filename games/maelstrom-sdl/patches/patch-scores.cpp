$NetBSD: patch-scores.cpp,v 1.1 2011/05/06 05:28:39 dholland Exp $

Support running setgid instead of installing the scores file mode 666.
Put the scores file in VARBASE instead of /usr/pkg/share.

--- scores.cpp~	2000-09-24 17:55:39.000000000 +0000
+++ scores.cpp
@@ -18,8 +18,13 @@
 #define MAELSTROM_SCORES	"Maelstrom-Scores"
 #define NUM_SCORES		10		// Do not change this!
 
+#ifndef MAELSTROM_SETGID
 /* Everyone can write to scores file if defined to 0 */
 #define SCORES_PERMMASK		0
+#else
+#define SCORES_PERMMASK		022
+extern gid_t gamesgid;
+#endif
 
 #define CLR_DIALOG_WIDTH	281
 #define CLR_DIALOG_HEIGHT	111
@@ -29,10 +34,19 @@ Scores hScores[NUM_SCORES];
 
 void LoadScores(void)
 {
+#ifndef MAELSTROM_SCOREDIR
 	LibPath path;
+#endif
+	const char *pathstr;
 	SDL_RWops *scores_src;
 	int i;
 
+#ifndef MAELSTROM_SCOREDIR
+	pathstr = path.Path(MAELSTROM_SCORES);
+#else
+	pathstr = MAELSTROM_SCOREDIR "/" MAELSTROM_SCORES;
+#endif
+
 	/* Try to load network scores, if we can */
 	if ( gNetScores ) {
 		if ( NetLoadScores() == 0 )
@@ -44,7 +58,7 @@ void LoadScores(void)
 	}
 	memset(&hScores, 0, sizeof(hScores));
 
-	scores_src = SDL_RWFromFile(path.Path(MAELSTROM_SCORES), "rb");
+	scores_src = SDL_RWFromFile(pathstr, "rb");
 	if ( scores_src != NULL ) {
 		for ( i=0; i<NUM_SCORES; ++i ) {
 			SDL_RWread(scores_src, hScores[i].name,
@@ -58,7 +72,10 @@ void LoadScores(void)
 
 void SaveScores(void)
 {
+#ifndef MAELSTROM_SCOREDIR
 	LibPath path;
+#endif
+	const char *pathstr;
 	SDL_RWops *scores_src;
 	int i;
 #ifdef unix
@@ -69,10 +86,22 @@ void SaveScores(void)
 	if ( gNetScores )
 		return;
 
+#ifndef MAELSTROM_SCOREDIR
+	pathstr = path.Path(MAELSTROM_SCORES);
+#else
+	pathstr = MAELSTROM_SCOREDIR "/" MAELSTROM_SCORES;
+#endif
+
 #ifdef unix
 	omask=umask(SCORES_PERMMASK);
 #endif
-	scores_src = SDL_RWFromFile(path.Path(MAELSTROM_SCORES), "wb");
+#ifdef MAELSTROM_SETGID
+	setegid(gamesgid);
+#endif
+	scores_src = SDL_RWFromFile(pathstr, "wb");
+#ifdef MAELSTROM_SETGID
+	setegid(getgid());
+#endif
 	if ( scores_src != NULL ) {
 		for ( i=0; i<NUM_SCORES; ++i ) {
 			SDL_RWwrite(scores_src, hScores[i].name,
@@ -82,8 +111,7 @@ void SaveScores(void)
 		}
 		SDL_RWclose(scores_src);
 	} else {
-		error("Warning: Couldn't save scores to %s\n",
-						path.Path(MAELSTROM_SCORES));
+		error("Warning: Couldn't save scores to %s\n", pathstr);
 	}
 #ifdef unix
 	umask(omask);
