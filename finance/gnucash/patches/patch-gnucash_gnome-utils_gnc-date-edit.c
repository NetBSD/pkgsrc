$NetBSD: patch-gnucash_gnome-utils_gnc-date-edit.c,v 1.1 2019/01/11 11:50:55 wiz Exp $

Fix build with clang
error: array subscript is of type 'char'

--- gnucash/gnome-utils/gnc-date-edit.c.orig	2018-12-25 22:43:08.000000000 +0000
+++ gnucash/gnome-utils/gnc-date-edit.c
@@ -1113,12 +1113,12 @@ gnc_date_edit_get_date_internal (GNCDate
             temp = gnc_strtok_r (NULL, ": ", &tokp);
             if (temp)
             {
-                if (isdigit (*temp))
+                if (isdigit ((unsigned char)*temp))
                 {
                     tm.tm_min = atoi (temp);
                     flags = gnc_strtok_r (NULL, ": ",
                                           &tokp);
-                    if (flags && isdigit (*flags))
+                    if (flags && isdigit ((unsigned char)*flags))
                     {
                         tm.tm_sec = atoi (flags);
                         flags = gnc_strtok_r (NULL,
