$NetBSD: patch-btparse_src_string__util.c,v 1.1 2026/04/29 21:08:25 markd Exp $

Fix ctype(3) usage.

--- btparse/src/string_util.c.orig	2025-01-29 15:47:18.000000000 +0000
+++ btparse/src/string_util.c
@@ -239,7 +239,7 @@ purify_special_char (char *str, int * sr
 
    *src += 2;                           /* jump to start of control sequence */
    peek = *src;                         /* scan to end of control sequence */
-   while (isalpha (str[peek]))
+   while (isalpha ((unsigned char)str[peek]))
       peek++;
    if (peek == *src)                    /* in case of single-char, non-alpha */
       peek++;                           /* control sequence (eg. {\'e}) */
@@ -249,7 +249,7 @@ purify_special_char (char *str, int * sr
       assert (peek - *src == 1 || peek - *src == 2);
       str[(*dst)++] = str[(*src)++];    /* copy first char */
       if (*src < peek)                  /* copy second char, downcasing */
-         str[(*dst)++] = tolower (str[(*src)++]);
+         str[(*dst)++] = tolower ((unsigned char)str[(*src)++]);
    }
    else                                 /* not a foreign letter -- skip */
    {                                    /* the control sequence entirely */
@@ -270,7 +270,7 @@ purify_special_char (char *str, int * sr
             (*src)++;
             break;
          default:
-            if (isalpha (str[*src]))    /* copy alphabetic chars */
+            if (isalpha ((unsigned char)str[*src]))    /* copy alphabetic chars */
                str[(*dst)++] = str[(*src)++];
             else                        /* skip everything else */
                (*src)++;
@@ -442,7 +442,7 @@ convert_special_char (char transform, 
          case '\\':                     /* a control sequence */
          {
             cs_end = *src+1;            /* scan over chars of c.s. */
-            while (isalpha (string[cs_end])) 
+            while (isalpha ((unsigned char)string[cs_end])) 
                cs_end++;
 
             /* 
@@ -535,10 +535,10 @@ convert_special_char (char transform, 
                 */
                case 'l':
                case 't':
-                  string[(*dst)++] = tolower (string[(*src)++]);
+                  string[(*dst)++] = tolower ((unsigned char)string[(*src)++]);
                   break;
                case 'u':
-                  string[(*dst)++] = toupper (string[(*src)++]);
+                  string[(*dst)++] = toupper ((unsigned char)string[(*src)++]);
                   break;
                default:
                   internal_error ("impossible case transform \"%c\"",
@@ -647,7 +647,7 @@ bt_change_case (char   transform,
             break;
 
          default:
-            if (isspace (string[src]))
+            if (isspace ((unsigned char)string[src]))
             {
                string[dst++] = string[src++];
             }
@@ -658,10 +658,10 @@ bt_change_case (char   transform,
                   switch (transform)
                   {
                      case 'u':
-                        string[dst++] = toupper (string[src++]);
+                        string[dst++] = toupper ((unsigned char)string[src++]);
                         break;
                      case 'l':
-                        string[dst++] = tolower (string[src++]);
+                        string[dst++] = tolower ((unsigned char)string[src++]);
                         break;
                      case 't':
                         if (start_sentence || after_colon)
@@ -673,12 +673,12 @@ bt_change_case (char   transform,
                             * punctuation, and second I force uppercase
                             * at start of sentence or after a colon.
                             */
-                           string[dst++] = toupper (string[src++]);
+                           string[dst++] = toupper ((unsigned char)string[src++]);
                            start_sentence = after_colon = FALSE;
                         }
                         else
                         {
-                           string[dst++] = tolower (string[src++]);
+                           string[dst++] = tolower ((unsigned char)string[src++]);
                         }
                         break;
                      default:
