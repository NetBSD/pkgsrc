$NetBSD: patch-IMG__xpm.c,v 1.1 2020/05/14 16:08:07 nia Exp $

Various sanity fixes from upstream preventing potential
security problems.

--- IMG_xpm.c.orig	2012-01-21 01:51:33.000000000 +0000
+++ IMG_xpm.c
@@ -106,7 +106,7 @@ static struct color_hash *create_colorha
 
 	/* we know how many entries we need, so we can allocate
 	   everything here */
-	hash = malloc(sizeof *hash);
+	hash = (struct color_hash *)calloc(1, sizeof(*hash));
 	if(!hash)
 		return NULL;
 
@@ -115,15 +115,32 @@ static struct color_hash *create_colorha
 		;
 	hash->size = s;
 	hash->maxnum = maxnum;
+
 	bytes = hash->size * sizeof(struct hash_entry **);
-	hash->entries = NULL;	/* in case malloc fails */
-	hash->table = malloc(bytes);
-	if(!hash->table)
+	/* Check for overflow */
+	if ((bytes / sizeof(struct hash_entry **)) != hash->size) {
+		IMG_SetError("memory allocation overflow");
+		free(hash);
+		return NULL;
+	}
+	hash->table = (struct hash_entry **)calloc(1, bytes);
+	if(!hash->table) {
+		free(hash);
+		return NULL;
+	}
+
+	bytes = maxnum * sizeof(struct hash_entry);
+	/* Check for overflow */
+	if ((bytes / sizeof(struct hash_entry)) != maxnum) {
+		IMG_SetError("memory allocation overflow");
+		free(hash->table);
+		free(hash);
 		return NULL;
-	memset(hash->table, 0, bytes);
-	hash->entries = malloc(maxnum * sizeof(struct hash_entry));
+	}
+	hash->entries = (struct hash_entry *)calloc(1, bytes);
 	if(!hash->entries) {
 		free(hash->table);
+		free(hash);
 		return NULL;
 	}
 	hash->next_free = hash->entries;
@@ -158,7 +175,7 @@ static Uint32 get_colorhash(struct color
 
 static void free_colorhash(struct color_hash *hash)
 {
-	if(hash && hash->table) {
+	if(hash) {
 		free(hash->table);
 		free(hash->entries);
 		free(hash);
@@ -262,7 +279,7 @@ static char *get_next_line(char ***lines
 			len += 4;	/* "\",\n\0" */
 			if(len > buflen){
 				buflen = len;
-				linebufnew = realloc(linebuf, buflen);
+				linebufnew = (char *)realloc(linebuf, buflen);
 				if(!linebufnew) {
 					free(linebuf);
 					error = "Out of memory";
@@ -282,7 +299,7 @@ static char *get_next_line(char ***lines
 					if(buflen == 0)
 						buflen = 16;
 					buflen *= 2;
-					linebufnew = realloc(linebuf, buflen);
+					linebufnew = (char *)realloc(linebuf, buflen);
 					if(!linebufnew) {
 						free(linebuf);
 						error = "Out of memory";
@@ -359,7 +376,12 @@ static SDL_Surface *load_xpm(char **xpm,
 		goto done;
 	}
 
-	keystrings = malloc(ncolors * cpp);
+	/* Check for allocation overflow */
+	if ((size_t)(ncolors * cpp)/cpp != ncolors) {
+		error = "Invalid color specification";
+		goto done;
+	}
+	keystrings = (char *)malloc(ncolors * cpp);
 	if(!keystrings) {
 		error = "Out of memory";
 		goto done;
@@ -426,8 +448,9 @@ static SDL_Surface *load_xpm(char **xpm,
 				c->g = (Uint8)(rgb >> 8);
 				c->b = (Uint8)(rgb);
 				pixel = index;
-			} else
+			} else {
 				pixel = rgb;
+			}
 			add_colorhash(colors, nextkey, cpp, pixel);
 			nextkey += cpp;
 			if(rgb == 0xffffffff)
@@ -438,9 +461,11 @@ static SDL_Surface *load_xpm(char **xpm,
 
 	/* Read the pixels */
 	pixels_len = w * cpp;
-	dst = image->pixels;
+	dst = (Uint8 *)image->pixels;
 	for(y = 0; y < h; y++) {
 		line = get_next_line(xpmlines, src, pixels_len);
+		if (!line)
+			goto done;
 		if(indexed) {
 			/* optimization for some common cases */
 			if(cpp == 1)
@@ -489,6 +514,10 @@ SDL_Surface *IMG_LoadXPM_RW(SDL_RWops *s
 
 SDL_Surface *IMG_ReadXPMFromArray(char **xpm)
 {
+	if ( !xpm ) {
+		IMG_SetError("array is NULL");
+		return NULL;
+	}
 	return load_xpm(xpm, NULL);
 }
 
