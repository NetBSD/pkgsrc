$NetBSD: patch-daemon_ParseFTPList.c,v 1.1 2026/05/10 17:38:14 vins Exp $

Fix misuse of ctype(3) functions.

--- daemon/ParseFTPList.c.orig	2025-11-14 15:53:26.627351338 +0000
+++ daemon/ParseFTPList.c
@@ -127,9 +127,9 @@ int ParseFTPList(const char *line, struc
             result->fe_type = 'f'; /* its a file */
           else if (*p == 'm')
           {
-            if (isdigit(line[pos]))
+            if (isdigit((unsigned char)line[pos]))
             {
-              while (pos < linelen && isdigit(line[pos]))
+              while (pos < linelen && isdigit((unsigned char)line[pos]))
                 pos++;
               if (pos < linelen && line[pos] == ',')
               {
@@ -143,9 +143,9 @@ int ParseFTPList(const char *line, struc
           }
           else if (*p == 's')
           {
-            if (isdigit(line[pos]))
+            if (isdigit((unsigned char)line[pos]))
             {
-              while (pos < linelen && isdigit(line[pos]))
+              while (pos < linelen && isdigit((unsigned char)line[pos]))
                 pos++;
               if (pos < linelen && line[pos] == ',' &&
                  ((&line[pos]) - (p+1)) < (int) (sizeof(result->fe_size)-1) )
@@ -155,7 +155,7 @@ int ParseFTPList(const char *line, struc
               }
             }
           }
-          else if (isalpha(*p)) /* 'i'/'up' or unknown "fact" (property) */
+          else if (isalpha((unsigned char)*p)) /* 'i'/'up' or unknown "fact" (property) */
           {
             while (pos < linelen && *++p != ',')
               pos++;
@@ -233,9 +233,9 @@ int ParseFTPList(const char *line, struc
                 break;
             }
             else if (p[pos] != '.' && p[pos] != '~' && 
-                     !isdigit(p[pos]) && !isalpha(p[pos]))
+                     !isdigit((unsigned char)p[pos]) && !isalpha((unsigned char)p[pos]))
               break;
-            else if (isalpha(p[pos]) && p[pos] != toupper(p[pos]))
+            else if (isalpha((unsigned char)p[pos]) && p[pos] != toupper((unsigned char)p[pos]))
               break;
           }
           if (pos > 0)
@@ -251,9 +251,9 @@ int ParseFTPList(const char *line, struc
           {
             pos--;
             if (p[pos] != '$' && p[pos] != '_' && p[pos] != '-' &&
-                p[pos] != '~' && !isdigit(p[pos]) && !isalpha(p[pos]))
+                p[pos] != '~' && !isdigit((unsigned char)p[pos]) && !isalpha((unsigned char)p[pos]))
               break;
-            else if (isalpha(p[pos]) && p[pos] != toupper(p[pos]))
+            else if (isalpha((unsigned char)p[pos]) && p[pos] != toupper((unsigned char)p[pos]))
               break;
           }
           if (pos == 0)
@@ -289,9 +289,9 @@ int ParseFTPList(const char *line, struc
          ((toklen[3]==10 || toklen[3]==11 ) &&
                         (tokens[3][toklen[3]-3]) == '.' )
         ) &&  /* time in [H]H:MM[:SS[.CC]] format */
-                                    isdigit(*tokens[1]) && /* size */
-                                    isdigit(*tokens[2]) && /* date */
-                                    isdigit(*tokens[3])    /* time */
+                                    isdigit((unsigned char)*tokens[1]) && /* size */
+                                    isdigit((unsigned char)*tokens[2]) && /* date */
+                                    isdigit((unsigned char)*tokens[3])    /* time */
                 )
         {
           lstyle = 'V';
@@ -328,7 +328,7 @@ int ParseFTPList(const char *line, struc
             while (lstyle && pos < toklen[0] && *p != ']')
             {
               if (*p != '$' && *p != '.' && *p != '_' && *p != '-' &&
-                  *p != '~' && !isdigit(*p) && !isalpha(*p))              
+                  *p != '~' && !isdigit((unsigned char)*p) && !isalpha((unsigned char)*p))              
                 lstyle = 0;
               pos++;
               p++;
@@ -348,9 +348,9 @@ int ParseFTPList(const char *line, struc
           while (lstyle && pos < toklen[0] && *p != ';')
           {
             if (*p != '$' && *p != '.' && *p != '_' && *p != '-' &&
-                *p != '~' && !isdigit(*p) && !isalpha(*p))
+                *p != '~' && !isdigit((unsigned char)*p) && !isalpha((unsigned char)*p))
               lstyle = 0;
-            else if (isalpha(*p) && *p != toupper(*p))
+            else if (isalpha((unsigned char)*p) && *p != toupper((unsigned char)*p))
               lstyle = 0;
             p++;
             pos++;
@@ -361,7 +361,7 @@ int ParseFTPList(const char *line, struc
               lstyle = 0;
             for (pos++;lstyle && pos < toklen[0];pos++)
             {
-              if (!isdigit(tokens[0][pos]))
+              if (!isdigit((unsigned char)tokens[0][pos]))
                 lstyle = 0;
             }
           }
@@ -384,11 +384,11 @@ int ParseFTPList(const char *line, struc
             state->carry_buf_len = pos;
             return '?'; /* tell caller to treat as junk */
           }
-          else if (isdigit(*tokens[1])) /* not no-privs message */
+          else if (isdigit((unsigned char)*tokens[1])) /* not no-privs message */
           {
             for (pos = 0; lstyle && pos < (toklen[1]); pos++)
             {
-              if (!isdigit((tokens[1][pos])) && (tokens[1][pos]) != '/')
+              if (!isdigit((unsigned char)(tokens[1][pos])) && (tokens[1][pos]) != '/')
                 lstyle = 0;
             }
             if (lstyle && numtoks > 4) /* Multinet or UCX but not CMU */
@@ -409,7 +409,7 @@ int ParseFTPList(const char *line, struc
         state->parsed_one = 1;
         state->lstyle = lstyle;
 
-        if (isdigit(*tokens[1]))  /* not permission denied etc */
+        if (isdigit((unsigned char)*tokens[1]))  /* not permission denied etc */
         {
           /* strip leading directory name */
           if (*tokens[0] == '[') /* CMU server */
@@ -503,8 +503,8 @@ int ParseFTPList(const char *line, struc
           if (*p == '-')
             p++;
           tbuf[0] = p[0];
-          tbuf[1] = tolower(p[1]);
-          tbuf[2] = tolower(p[2]);
+          tbuf[1] = tolower((unsigned char)p[1]);
+          tbuf[2] = tolower((unsigned char)p[2]);
           month_num = 0;
           for (pos = 0; pos < (12*3); pos+=3)
           {
@@ -587,9 +587,9 @@ int ParseFTPList(const char *line, struc
                 if ( (*tokens[pos+1] == '-' &&
                       *tokens[pos+2] == '-' &&
                       *tokens[pos+3] == '-')  ||
-                      (isdigit(*tokens[pos+1]) &&
-                       isdigit(*tokens[pos+2]) &&
-                       isdigit(*tokens[pos+3])) )
+                      (isdigit((unsigned char)*tokens[pos+1]) &&
+                       isdigit((unsigned char)*tokens[pos+2]) &&
+                       isdigit((unsigned char)*tokens[pos+3])) )
                 {
                   lstyle = 'C';
                   tokmarker = pos;
@@ -605,7 +605,7 @@ int ParseFTPList(const char *line, struc
       {
         for (pos = 0, p = tokens[0]; lstyle && pos < toklen[0]; pos++, p++)
         {  
-          if (isalpha(*p) && toupper(*p) != *p)
+          if (isalpha((unsigned char)*p) && toupper((unsigned char)*p) != *p)
             lstyle = 0;
         } 
         for (pos = tokmarker+1; pos <= tokmarker+3; pos++)
@@ -614,7 +614,7 @@ int ParseFTPList(const char *line, struc
           {
             for (p = tokens[pos]; lstyle && p<(tokens[pos]+toklen[pos]); p++)
             {
-              if (!isdigit(*p))
+              if (!isdigit((unsigned char)*p))
                 lstyle = 0;
             }
           }
@@ -635,7 +635,7 @@ int ParseFTPList(const char *line, struc
             else if (pos != 2 && pos != 5)
               lstyle = 0;
           }
-          else if (*p != '-' && !isdigit(*p))
+          else if (*p != '-' && !isdigit((unsigned char)*p))
             lstyle = 0;
           else if (*p == '-' && pos != 4 && pos != 7)
             lstyle = 0;
@@ -643,7 +643,7 @@ int ParseFTPList(const char *line, struc
         for (pos = 0, p = tokens[tokmarker+5]; 
              lstyle && pos < toklen[tokmarker+5]; pos++, p++)
         {
-          if (*p != ':' && !isdigit(*p))
+          if (*p != ':' && !isdigit((unsigned char)*p))
             lstyle = 0;
           else if (*p == ':' && pos != (toklen[tokmarker+5]-3)
                              && pos != (toklen[tokmarker+5]-6))
@@ -730,16 +730,16 @@ int ParseFTPList(const char *line, struc
        * "07-14-00  01:38PM              2250540 Valentineoffprank-HiRes.jpg"
       */
       if ((numtoks >= 4) && (toklen[0] == 8 || toklen[0] == 10) && toklen[1] == 7 && 
-          (*tokens[2] == '<' || isdigit(*tokens[2])) )
+          (*tokens[2] == '<' || isdigit((unsigned char)*tokens[2])) )
       {
         p = tokens[0];
-        if ( isdigit(p[0]) && isdigit(p[1]) && p[2]=='-' && 
-             isdigit(p[3]) && isdigit(p[4]) && p[5]=='-' &&
-             isdigit(p[6]) && isdigit(p[7]) )
+        if ( isdigit((unsigned char)p[0]) && isdigit((unsigned char)p[1]) && p[2]=='-' && 
+             isdigit((unsigned char)p[3]) && isdigit((unsigned char)p[4]) && p[5]=='-' &&
+             isdigit((unsigned char)p[6]) && isdigit((unsigned char)p[7]) )
         {
           p = tokens[1];
-          if ( isdigit(p[0]) && isdigit(p[1]) && p[2]==':' && 
-               isdigit(p[3]) && isdigit(p[4]) && 
+          if ( isdigit((unsigned char)p[0]) && isdigit((unsigned char)p[1]) && p[2]==':' && 
+               isdigit((unsigned char)p[3]) && isdigit((unsigned char)p[4]) && 
                (p[5]=='A' || p[5]=='P') && p[6]=='M')
           {
             lstyle = 'W';
@@ -751,7 +751,7 @@ int ParseFTPList(const char *line, struc
               {
                 for (pos = 1; (lstyle && pos < toklen[2]); pos++)
                 {
-                  if (!isdigit(*++p))
+                  if (!isdigit((unsigned char)*++p))
                     lstyle = 0;
                 }
               }
@@ -882,16 +882,16 @@ int ParseFTPList(const char *line, struc
       */
       p = &(line[toklen[0]]);
       /* \s(\d\d-\d\d-\d\d)\s+(\d\d:\d\d)\s */
-      if (numtoks >= 4 && toklen[0] <= 18 && isdigit(*tokens[0]) &&
+      if (numtoks >= 4 && toklen[0] <= 18 && isdigit((unsigned char)*tokens[0]) &&
          (linelen - toklen[0]) >= (53-18)                        &&
          p[18-18] == ' ' && p[34-18] == ' '                      &&
          p[37-18] == '-' && p[40-18] == '-' && p[43-18] == ' '   &&
          p[45-18] == ' ' && p[48-18] == ':' && p[51-18] == ' '   &&
-         isdigit(p[35-18]) && isdigit(p[36-18])                  &&
-         isdigit(p[38-18]) && isdigit(p[39-18])                  &&
-         isdigit(p[41-18]) && isdigit(p[42-18])                  &&
-         isdigit(p[46-18]) && isdigit(p[47-18])                  &&
-         isdigit(p[49-18]) && isdigit(p[50-18])
+         isdigit((unsigned char)p[35-18]) && isdigit((unsigned char)p[36-18])                  &&
+         isdigit((unsigned char)p[38-18]) && isdigit((unsigned char)p[39-18])                  &&
+         isdigit((unsigned char)p[41-18]) && isdigit((unsigned char)p[42-18])                  &&
+         isdigit((unsigned char)p[46-18]) && isdigit((unsigned char)p[47-18])                  &&
+         isdigit((unsigned char)p[49-18]) && isdigit((unsigned char)p[50-18])
       )
       {
         lstyle = 'O'; /* OS/2 */
@@ -899,7 +899,7 @@ int ParseFTPList(const char *line, struc
         {            
           for (pos = 1; lstyle && pos < toklen[0]; pos++)
           {
-            if (!isdigit(tokens[0][pos]))
+            if (!isdigit((unsigned char)tokens[0][pos]))
               lstyle = 0;
           }
         }
@@ -1046,34 +1046,34 @@ int ParseFTPList(const char *line, struc
            *  (\d\d\d\d|\d\:\d\d|\d\d\:\d\d|\d\:\d\d\:\d\d|\d\d\:\d\d\:\d\d)
            *  \s+(.+)$
           */
-          if (isdigit(*tokens[pos]) /* size */
+          if (isdigit((unsigned char)*tokens[pos]) /* size */
               /* (\w\w\w) */
-           && toklen[pos+1] == 3 && isalpha(*tokens[pos+1]) &&
-              isalpha(tokens[pos+1][1]) && isalpha(tokens[pos+1][2])
+           && toklen[pos+1] == 3 && isalpha((unsigned char)*tokens[pos+1]) &&
+              isalpha((unsigned char)tokens[pos+1][1]) && isalpha((unsigned char)tokens[pos+1][2])
               /* (\d|\d\d) */
-           && isdigit(*tokens[pos+2]) &&
+           && isdigit((unsigned char)*tokens[pos+2]) &&
                 (toklen[pos+2] == 1 || 
-                  (toklen[pos+2] == 2 && isdigit(tokens[pos+2][1])))
-           && toklen[pos+3] >= 4 && isdigit(*tokens[pos+3]) 
+                  (toklen[pos+2] == 2 && isdigit((unsigned char)tokens[pos+2][1])))
+           && toklen[pos+3] >= 4 && isdigit((unsigned char)*tokens[pos+3]) 
               /* (\d\:\d\d\:\d\d|\d\d\:\d\d\:\d\d) */
            && (toklen[pos+3] <= 5 || (
                (toklen[pos+3] == 7 || toklen[pos+3] == 8) &&
                (tokens[pos+3][toklen[pos+3]-3]) == ':'))
-           && isdigit(tokens[pos+3][toklen[pos+3]-2])
-           && isdigit(tokens[pos+3][toklen[pos+3]-1])
+           && isdigit((unsigned char)tokens[pos+3][toklen[pos+3]-2])
+           && isdigit((unsigned char)tokens[pos+3][toklen[pos+3]-1])
            && (
               /* (\d\d\d\d) */
                  ((toklen[pos+3] == 4 || toklen[pos+3] == 5) &&
-                  isdigit(tokens[pos+3][1]) &&
-                  isdigit(tokens[pos+3][2])  )
+                  isdigit((unsigned char)tokens[pos+3][1]) &&
+                  isdigit((unsigned char)tokens[pos+3][2])  )
               /* (\d\:\d\d|\d\:\d\d\:\d\d) */
               || ((toklen[pos+3] == 4 || toklen[pos+3] == 7) && 
                   (tokens[pos+3][1]) == ':' &&
-                  isdigit(tokens[pos+3][2]) && isdigit(tokens[pos+3][3]))
+                  isdigit((unsigned char)tokens[pos+3][2]) && isdigit((unsigned char)tokens[pos+3][3]))
               /* (\d\d\:\d\d|\d\d\:\d\d\:\d\d) */
               || ((toklen[pos+3] == 5 || toklen[pos+3] == 8) && 
-                  isdigit(tokens[pos+3][1]) && (tokens[pos+3][2]) == ':' &&
-                  isdigit(tokens[pos+3][3]) && isdigit(tokens[pos+3][4])) 
+                  isdigit((unsigned char)tokens[pos+3][1]) && ((unsigned char)tokens[pos+3][2]) == ':' &&
+                  isdigit((unsigned char)tokens[pos+3][3]) && isdigit((unsigned char)tokens[pos+3][4])) 
               )
            )
           {
@@ -1085,7 +1085,7 @@ int ParseFTPList(const char *line, struc
             p = tokens[tokmarker];
             for (i = 0; i < toklen[tokmarker]; i++)
             {
-              if (!isdigit(*p++))
+              if (!isdigit((unsigned char)*p++))
               {
                 lstyle = 0;
                 break;
@@ -1281,7 +1281,7 @@ int ParseFTPList(const char *line, struc
       * CMT.CSV             0      Jul 06 1995 14:56   RHA
       */
       if (numtoks >= 4 && toklen[0] < 13 && 
-          ((toklen[1] == 5 && *tokens[1] == '<') || isdigit(*tokens[1])) )
+          ((toklen[1] == 5 && *tokens[1] == '<') || isdigit((unsigned char)*tokens[1])) )
       {
         if (numtoks == 4
          && (toklen[2] == 8 || toklen[2] == 9)
@@ -1289,12 +1289,12 @@ int ParseFTPList(const char *line, struc
              ((tokens[2][2]) == '-' && (tokens[2][5]) == '-'))
          && (toklen[3] == 4 || toklen[3] == 5)
          && (tokens[3][toklen[3]-3]) == ':'
-         && isdigit(tokens[2][0]) && isdigit(tokens[2][1])
-         && isdigit(tokens[2][3]) && isdigit(tokens[2][4])
-         && isdigit(tokens[2][6]) && isdigit(tokens[2][7])
-         && (toklen[2] < 9 || isdigit(tokens[2][8]))
-         && isdigit(tokens[3][toklen[3]-1]) && isdigit(tokens[3][toklen[3]-2])
-         && isdigit(tokens[3][toklen[3]-4]) && isdigit(*tokens[3]) 
+         && isdigit((unsigned char)tokens[2][0]) && isdigit((unsigned char)tokens[2][1])
+         && isdigit((unsigned char)tokens[2][3]) && isdigit((unsigned char)tokens[2][4])
+         && isdigit((unsigned char)tokens[2][6]) && isdigit((unsigned char)tokens[2][7])
+         && (toklen[2] < 9 || isdigit((unsigned char)tokens[2][8]))
+         && isdigit((unsigned char)tokens[3][toklen[3]-1]) && isdigit((unsigned char)tokens[3][toklen[3]-2])
+         && isdigit((unsigned char)tokens[3][toklen[3]-4]) && isdigit((unsigned char)*tokens[3]) 
          )
         {
           lstyle = 'w';
@@ -1303,13 +1303,13 @@ int ParseFTPList(const char *line, struc
          && toklen[2] == 3 && toklen[3] == 2
          && toklen[4] == 4 && toklen[5] == 5
          && (tokens[5][2]) == ':'
-         && isalpha(tokens[2][0]) && isalpha(tokens[2][1])
-         &&                          isalpha(tokens[2][2])
-         && isdigit(tokens[3][0]) && isdigit(tokens[3][1])
-         && isdigit(tokens[4][0]) && isdigit(tokens[4][1])
-         && isdigit(tokens[4][2]) && isdigit(tokens[4][3])
-         && isdigit(tokens[5][0]) && isdigit(tokens[5][1])
-         && isdigit(tokens[5][3]) && isdigit(tokens[5][4])
+         && isalpha((unsigned char)tokens[2][0]) && isalpha((unsigned char)tokens[2][1])
+         &&                          isalpha((unsigned char)tokens[2][2])
+         && isdigit((unsigned char)tokens[3][0]) && isdigit((unsigned char)tokens[3][1])
+         && isdigit((unsigned char)tokens[4][0]) && isdigit((unsigned char)tokens[4][1])
+         && isdigit((unsigned char)tokens[4][2]) && isdigit((unsigned char)tokens[4][3])
+         && isdigit((unsigned char)tokens[5][0]) && isdigit((unsigned char)tokens[5][1])
+         && isdigit((unsigned char)tokens[5][3]) && isdigit((unsigned char)tokens[5][4])
          /* could also check that (&(tokens[5][5]) - tokens[2]) == 17 */
         )
         {
@@ -1323,7 +1323,7 @@ int ParseFTPList(const char *line, struc
           {
             for (pos = 0; lstyle && pos < toklen[1]; pos++)
             {
-              if (!isdigit(*p++))
+              if (!isdigit((unsigned char)*p++))
                 lstyle = 0;
             }
           } /* not <DIR> */
@@ -1341,7 +1341,7 @@ int ParseFTPList(const char *line, struc
         result->fe_type = 'd';
 
         p = tokens[1];
-        if (isdigit(*p))
+        if (isdigit((unsigned char)*p))
         {
           result->fe_type = 'f';
           pos = toklen[1];
@@ -1354,9 +1354,9 @@ int ParseFTPList(const char *line, struc
         p = tokens[2];
         if (toklen[2] == 3) /* Chameleon */
         {
-          tbuf[0] = toupper(p[0]);
-          tbuf[1] = tolower(p[1]);
-          tbuf[2] = tolower(p[2]);
+          tbuf[0] = toupper((unsigned char)p[0]);
+          tbuf[1] = tolower((unsigned char)p[1]);
+          tbuf[2] = tolower((unsigned char)p[2]);
           for (pos = 0; pos < (12*3); pos+=3)
           {
             if (tbuf[0] == month_names[pos+0] &&
@@ -1475,7 +1475,7 @@ int ParseFTPList(const char *line, struc
         if (linelen > pos)
         {
           p = &line[pos];
-          if ((*p == '-' || *p == '=' || isdigit(*p)) &&
+          if ((*p == '-' || *p == '=' || isdigit((unsigned char)*p)) &&
               ((linelen == (pos+1)) || 
                (linelen >= (pos+3) && p[1] == ' ' && p[2] == ' ')) )
           {
@@ -1502,7 +1502,7 @@ int ParseFTPList(const char *line, struc
               {
                 for (pos = 0; lstyle && pos < toklen[tokmarker]; pos++) 
                 {
-                  if (!isdigit(tokens[tokmarker][pos]))
+                  if (!isdigit((unsigned char)tokens[tokmarker][pos]))
                     lstyle = 0; 
                 }
               }
@@ -1559,7 +1559,7 @@ int ParseFTPList(const char *line, struc
             result->fe_type  = 'd';
           }
         }
-        else if (isdigit(*tokens[tokmarker]))
+        else if (isdigit((unsigned char)*tokens[tokmarker]))
         {
           pos = toklen[tokmarker];
           if (pos > (sizeof(result->fe_size)-1))
@@ -1577,24 +1577,24 @@ int ParseFTPList(const char *line, struc
           pos = toklen[pos];
 
           if ((pos == 4 || pos == 5)
-          &&  isdigit(*p) && isdigit(p[pos-1]) && isdigit(p[pos-2])
+          &&  isdigit((unsigned char)*p) && isdigit((unsigned char)p[pos-1]) && isdigit((unsigned char)p[pos-2])
           &&  ((pos == 5 && p[2] == ':') ||  
-               (pos == 4 && (isdigit(p[1]) || p[1] == ':')))
+               (pos == 4 && (isdigit((unsigned char)p[1]) || p[1] == ':')))
              )
           {
             month_num = tokmarker+1; /* assumed position of month field */
             pos = tokmarker+2;       /* assumed position of mday field */
-            if (isdigit(*tokens[month_num])) /* positions are reversed */
+            if (isdigit((unsigned char)*tokens[month_num])) /* positions are reversed */
             {
               month_num++;
               pos--;
             }
             p = tokens[month_num];
-            if (isdigit(*tokens[pos]) 
+            if (isdigit((unsigned char)*tokens[pos]) 
             && (toklen[pos] == 1 || 
-                  (toklen[pos] == 2 && isdigit(tokens[pos][1])))
+                  (toklen[pos] == 2 && isdigit((unsigned char)tokens[pos][1])))
             && toklen[month_num] == 3
-            && isalpha(*p) && isalpha(p[1]) && isalpha(p[2])  )
+            && isalpha((unsigned char)*p) && isalpha((unsigned char)p[1]) && isalpha((unsigned char)p[2])  )
             {
               pos = atoi(tokens[pos]);
               if (pos > 0 && pos <= 31)
