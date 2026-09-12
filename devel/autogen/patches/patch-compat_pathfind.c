$NetBSD: patch-compat_pathfind.c,v 1.1 2026/09/12 12:14:41 wiz Exp $

Do not copy overlapping regions with strcpy().

Upstream's own file taken whole at v5.19.98; master does not compile.

--- compat/pathfind.c.orig
+++ compat/pathfind.c
@@ -1,11 +1,21 @@
-/*  -*- Mode: C -*-  */
 
-/* pathfind.c --- find a FILE  MODE along PATH */
+/**
+ * @file pathfind.c
+ * --- find a FILE  MODE along PATH
+ */
 
 /* Author: Gary V Vaughan <gvaughan@oranda.demon.co.uk> */
 
 /* Code: */
 
+#ifndef DIRCH
+# if defined(_WIN32) && !defined(__CYGWIN__)
+#  define DIRCH                  '\\'
+# else
+#  define DIRCH                  '/'
+# endif
+#endif
+
 static char *
 pathfind( char const * path,
           char const * fname,
@@ -24,9 +34,200 @@
 #else
 
 static char * make_absolute(char const * string, char const * dot_path);
-static char * canonicalize_pathname(char * path);
 static char * extract_colon_unit(char * dir, char const * string, int * p_index);
 
+/*
+ *    Multiple `/'s     are collapsed to a single `/'.
+ *    Leading `./'s     are removed.
+ */
+static char const *
+trim_path_leader( char const * path )
+{
+    for (;;) {
+        switch (*path) {
+        case NUL:
+            return NULL;
+
+        case '.':
+            if (path[1] != DIRCH)
+                return path;
+            path += 2;
+            continue;
+
+        case DIRCH:
+            while (path[1] == DIRCH)
+                path++;
+            return path;
+        }
+    }
+}
+
+/**
+ * Remove directory characters at the end of a path.
+ *
+ * @param path      the full path
+ * @param cur_size  the number of characters in @path we're examining
+ * @return          the remaining size
+ */
+static size_t
+strip_trailing_slashes( char const * path, size_t cur_size )
+{
+    while ((cur_size > 0) && (path[cur_size - 1] == DIRCH))
+        cur_size--; // skip any remaining dir separators
+    return cur_size;
+}
+
+/**
+ *    Trailing `/.'s    are removed.
+ *    Trailing `xxx/..'s   are removed.
+ *    Trailing `/'s     are removed.
+ */
+static size_t
+real_path_length( char const * path )
+{
+    size_t res = strlen(path);
+
+    for (;;) {
+        char const * end;
+        res = strip_trailing_slashes(path, res);
+        if (res == 0)
+            return res;
+        end = path + res;
+        // end[-1] cannot be DIRCH
+
+        if (end[-1] != '.')
+            return res;
+        if (res == 1)
+            return 1; // path is '.' by itself
+
+        if (end[-2] == DIRCH) {
+            // path ends with "/." strip and continue
+            //
+            res -= 2;
+            continue;
+        }
+        if (res == 2)
+            // path is not "/." but may be "..". We don't care.
+            //
+            return 2;
+
+        // path is 3 or more characters. Check for "/.."
+        //
+        if (end[-2] != '.')
+            return res;
+        // path ends with ".."
+
+        if (end[-3] != DIRCH)
+            return res;
+
+        // Strip the trailing "/..", the resulting trailing DIRCH-es
+        // and then the last directory name
+        //
+        res = strip_trailing_slashes(path, res - 3);
+        if (res == 0)
+            return 1; // "////.." is "/"
+
+        for (;;) {
+            if (path[res - 1] == DIRCH)
+                break; // found '/' before 'y' in "x///yyy///.."
+
+            if (--res == 0)
+                return res; // "xxx/.." is empty
+        }
+    }
+}
+
+static void
+strip_up_dirs(char * path)
+{
+    static char const up_dir[] = "/../";
+    static size_t const skip_up_dir_sz = sizeof(up_dir) - 1;
+
+    char * scn;
+ restart:
+    scn = path;
+
+    for (;;) {
+        char * upone = scn = strstr(scn, up_dir);
+
+        if (scn == NULL)
+            return;
+
+        upone += skip_up_dir_sz;
+
+        /*
+         * scan backward for DIR character or start of path.
+         * IF start of path, then everything after "/../" is
+         * the canonical path. Otherwise, remove the directory
+         * name, "/" and the two dots.
+         */
+        for (;;) {
+            if (scn <= path) {
+                memmove(path, upone, strlen(upone) + 1);
+                goto restart;
+            }
+            if (*(--scn) == DIRCH)
+                break;
+        }
+        /*
+         * We found a "/", so remove the directory name
+         */
+        memmove(++scn, upone, strlen(upone) + 1);
+    }
+}
+
+/*
+ * Canonicalize PATH, and return a  new path.  The new path differs from
+ * PATH in that:
+ *
+ *    Multiple `/'s     are collapsed to a single `/'.
+ *    Leading `./'s     are removed.
+ *    Trailing `/.'s    are removed.
+ *    Trailing `/..'s   are removed.
+ *    Trailing `/'s     are removed.
+ *    Non-leading `../'s and trailing `..'s are handled by removing
+ *                    portions of the path.
+ */
+static char *
+canonicalize_pathname(char const * path)
+{
+    size_t psz;
+    char * scn;
+    char * res;
+
+    path = trim_path_leader(path);
+    if (path == NULL)
+        goto leave_empty_handed;
+
+    psz = real_path_length(path);
+    if (psz == 0)
+        goto leave_empty_handed;
+
+    res = scn = malloc(psz + 1);
+    memcpy(res, path, psz);
+    res[psz] = '\0';
+
+    /*
+     * Strip no-op dirs
+     */
+    for (;;) {
+        char * noop = strstr(scn, "/./");
+        if (noop == NULL)
+            break;
+        memmove(noop, noop + 2, strlen(noop + 1));
+        scn = noop;
+    }
+
+    strip_up_dirs(res);
+    return res;
+
+ leave_empty_handed:
+    res  = malloc(2);
+    res[0] = (*path == DIRCH) ? DIRCH : '.';
+    res[1] = NUL;
+    return res;
+}
+
 /**
  * local implementation of pathfind.
  * @param[in] path  colon separated list of directories
@@ -81,12 +282,11 @@
                 /*
                  *  Make sure we can access it in the way we want
                  */
-                if (access(abs_name, mode_bits) >= 0) {
+                if (access(abs_name, mode_bits) >= 0)
                     /*
                      *  We can, so normalize the name and return it below
                      */
                     res_path = canonicalize_pathname(abs_name);
-                }
 
                 free(abs_name);
                 break;
@@ -113,20 +313,20 @@
     char * result;
     int result_len;
 
-    if (!dot_path || *string == '/') {
+    if (!dot_path || *string == DIRCH) {
         result = strdup( string );
     } else {
         if (dot_path && dot_path[0]) {
             result = malloc( 2 + strlen( dot_path ) + strlen( string ) );
             strcpy( result, dot_path );
             result_len = (int)strlen(result);
-            if (result[result_len - 1] != '/') {
-                result[result_len++] = '/';
+            if (result[result_len - 1] != DIRCH) {
+                result[result_len++] = DIRCH;
                 result[result_len] = '\0';
             }
         } else {
             result = malloc( 3 + strlen( string ) );
-            result[0] = '.'; result[1] = '/'; result[2] = '\0';
+            result[0] = '.'; result[1] = DIRCH; result[2] = '\0';
             result_len = 2;
         }
 
@@ -137,96 +337,6 @@
 }
 
 /*
- * Canonicalize PATH, and return a  new path.  The new path differs from
- * PATH in that:
- *
- *    Multiple `/'s     are collapsed to a single `/'.
- *    Leading `./'s     are removed.
- *    Trailing `/.'s    are removed.
- *    Trailing `/'s     are removed.
- *    Non-leading `../'s and trailing `..'s are handled by removing
- *                    portions of the path.
- */
-static char *
-canonicalize_pathname( char *path )
-{
-    int i, start;
-    char stub_char, *result;
-
-    /* The result cannot be larger than the input PATH. */
-    result = strdup( path );
-
-    stub_char = (*path == '/') ? '/' : '.';
-
-    /* Walk along RESULT looking for things to compact. */
-    i = 0;
-    while (result[i]) {
-        while (result[i] != '\0' && result[i] != '/')
-            i++;
-
-        start = i++;
-
-        /* If we didn't find any  slashes, then there is nothing left to
-         * do.
-         */
-        if (!result[start])
-            break;
-
-        /* Handle multiple `/'s in a row. */
-        while (result[i] == '/')
-            i++;
-
-#if !defined (apollo)
-        if ((start + 1) != i)
-#else
-        if ((start + 1) != i && (start != 0 || i != 2))
-#endif /* apollo */
-        {
-            strcpy( result + start + 1, result + i );
-            i = start + 1;
-        }
-
-        /* Handle backquoted `/'. */
-        if (start > 0 && result[start - 1] == '\\')
-            continue;
-
-        /* Check for trailing `/', and `.' by itself. */
-        if ((start && !result[i])
-            || (result[i] == '.' && !result[i+1])) {
-            result[--i] = '\0';
-            break;
-        }
-
-        /* Check for `../', `./' or trailing `.' by itself. */
-        if (result[i] == '.') {
-            /* Handle `./'. */
-            if (result[i + 1] == '/') {
-                strcpy( result + i, result + i + 1 );
-                i = (start < 0) ? 0 : start;
-                continue;
-            }
-
-            /* Handle `../' or trailing `..' by itself. */
-            if (result[i + 1] == '.' &&
-                (result[i + 2] == '/' || !result[i + 2])) {
-                while (--start > -1 && result[start] != '/')
-                    ;
-                strcpy( result + start + 1, result + i + 2 );
-                i = (start < 0) ? 0 : start;
-                continue;
-            }
-        }
-    }
-
-    if (!*result) {
-        *result = stub_char;
-        result[1] = '\0';
-    }
-
-    return result;
-}
-
-/*
  * Given a  string containing units of information separated  by colons,
  * return the next one  pointed to by (P_INDEX), or NULL if there are no
  * more.  Advance (P_INDEX) to the character after the colon.
