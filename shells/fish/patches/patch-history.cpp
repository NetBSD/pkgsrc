$NetBSD: patch-history.cpp,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- history.cpp.orig	2015-03-17 21:50:56.000000000 +0000
+++ history.cpp
@@ -380,12 +380,12 @@ static size_t offset_of_next_item_fish_2
         const char * const line_start = begin + cursor;
 
         /* Advance the cursor to the next line */
-        const char *newline = (const char *)memchr(line_start, '\n', mmap_length - cursor);
-        if (newline == NULL)
+        const char *my_newline = (const char *)memchr(line_start, '\n', mmap_length - cursor);
+        if (my_newline == NULL)
             break;
 
         /* Advance the cursor past this line. +1 is for the newline */
-        size_t line_len = newline - line_start;
+        size_t line_len = my_newline - line_start;
         cursor += line_len + 1;
 
         /* Skip lines with a leading space, since these are in the interior of one of our items */
@@ -699,14 +699,14 @@ static size_t read_line(const char *base
     /* Locate the newline */
     assert(cursor <= len);
     const char *start = base + cursor;
-    const char *newline = (char *)memchr(start, '\n', len - cursor);
-    if (newline != NULL)
+    const char *my_newline = (char *)memchr(start, '\n', len - cursor);
+    if (my_newline != NULL)
     {
         /* We found a newline. */
-        result.assign(start, newline - start);
+        result.assign(start, my_newline - start);
 
         /* Return the amount to advance the cursor; skip over the newline */
-        return newline - start + 1;
+        return my_newline - start + 1;
     }
     else
     {
@@ -1610,9 +1610,9 @@ void history_t::populate_from_bash(FILE 
             if (success)
             {
                 /* Skip the newline */
-                char *newline = strchr(buff, '\n');
-                if (newline) *newline = '\0';
-                has_newline = (newline != NULL);
+                char *my_newline = strchr(buff, '\n');
+                if (my_newline) *my_newline = '\0';
+                has_newline = (my_newline != NULL);
 
                 /* Append what we've got */
                 line.append(buff);
@@ -1737,7 +1737,7 @@ void history_t::add_with_file_detection(
                     potential_paths.push_back(potential_path);
 
                     /* What a hack! */
-                    impending_exit = impending_exit || contains(potential_path, L"exec", L"exit", L"reboot");
+                    impending_exit = impending_exit || contains(&potential_path, L"exec", L"exit", L"reboot");
                 }
             }
         }
