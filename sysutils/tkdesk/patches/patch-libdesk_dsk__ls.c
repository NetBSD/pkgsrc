$NetBSD: patch-libdesk_dsk__ls.c,v 1.1 2022/06/06 05:11:58 dholland Exp $

Update for Tcl 8.6 (?)
Don't run off the end of strings.

--- libdesk/dsk_ls.c~	2004-04-14 02:20:01.000000000 +0000
+++ libdesk/dsk_ls.c
@@ -226,7 +226,7 @@ char *path;
 #endif
     
     strncpy (par_path, path, MAXPATHLEN);
-    par_path[MAXPATHLEN] = (char) NULL;
+    par_path[MAXPATHLEN - 1] = 0;
     if (process_cmdline (argc, argv) != TCL_OK)
 	return (TCL_ERROR);
 
@@ -374,8 +374,8 @@ FILE_ENTRY *fe;
 
     if (S_ISLNK(fe->sb.st_mode)) {
 	strcpy (linkname, " -> ");
-	len = readlink (fe->path, linkname + 4, MAXPATHLEN - 4);
-	*(linkname + 4 + len) = (char) NULL;
+	len = readlink (fe->path, linkname + 4, MAXPATHLEN - 5);
+	*(linkname + 4 + len) = 0;
 	return (linkname);
     } else {
 	return (strcpy (linkname, ""));
@@ -1223,7 +1223,8 @@ char *path;
     fprintf (stderr, "Opening %s ...\n", path);
 #endif
     if ((dp = opendir (path)) == NULL) {
-	sprintf (dsk_interp->result, "no such file or dir: %s", path);
+	snprintf(buffer, MAXPATHLEN, "no such file or dir: %s", path);
+	Tcl_SetResult(dsk_interp, buffer, TCL_VOLATILE);
 	return (TCL_ERROR);
     }
 
@@ -1240,18 +1241,15 @@ char *path;
 	    if (   (dir->d_name[1] == '\0')
 		|| (dir->d_name[1] == '.' && dir->d_name[2] == '\0')) {
 		if (!par_no_points) {
-		    strcpy (buffer, path);
-		    strcat (buffer, dir->d_name);
+		    snprintf(buffer, MAXPATHLEN, "%s%s", path, dir->d_name);
 		    new_file_entry (buffer);
 		}
 	    } else if (par_show_all) {
-		strcpy (buffer, path);
-		strcat (buffer, dir->d_name);
+	        snprintf(buffer, MAXPATHLEN, "%s%s", path, dir->d_name);
 		new_file_entry (buffer);
 	    }
     	} else {
-	    strcpy (buffer, path);
-            strcat (buffer, dir->d_name);
+	    snprintf(buffer, MAXPATHLEN, "%s%s", path, dir->d_name);
 	    if (!par_only_directories) {
 		new_file_entry (buffer);
 	    } else {
@@ -1280,16 +1278,19 @@ int read_file_lists ()
 {
     struct stat sb;
     char bc, *slash;
+    char buffer[MAXPATHLEN];
 
     if (par_path[strlen (par_path) - 1] == '/' && !par_one_file) {
 	/* par_path is the name of a directory */
 	if (stat (par_path, &sb) < 0) {
-	    sprintf (dsk_interp->result, "no such file or dir: %s", par_path);
+	    snprintf(buffer, MAXPATHLEN, "no such file or dir: %s", par_path);
+	    Tcl_SetResult(dsk_interp, buffer, TCL_VOLATILE);
 	    return (TCL_ERROR);
 	}
     } else {
 	if (stat (par_path, &sb) < 0) {
-	    sprintf (dsk_interp->result, "no such file or dir: %s", par_path);
+	    snprintf(buffer, MAXPATHLEN, "no such file or dir: %s", par_path);
+	    Tcl_SetResult(dsk_interp, buffer, TCL_VOLATILE);
 	    return (TCL_ERROR);
 	}
 	if (!S_ISDIR(sb.st_mode) || par_one_file) {
@@ -1375,7 +1376,7 @@ char *argv[];
 		break;
 	    case 'M':
 		if (argc == 2) {
-		    strcpy (dsk_interp->result, USAGE);
+		    Tcl_SetResult(dsk_interp, USAGE, TCL_STATIC);
 		    return (TCL_ERROR);
 		}
 		i++; argc--;
@@ -1398,7 +1399,7 @@ char *argv[];
 		break;
 	    case 's':
 		if (argc == 2) {
-		    strcpy (dsk_interp->result, USAGE);
+		    Tcl_SetResult(dsk_interp, USAGE, TCL_STATIC);
 		    return (TCL_ERROR);
 		}
 		i++; argc--;
@@ -1415,9 +1416,11 @@ char *argv[];
 		else if (!strcmp ("not", argv[i]))
 		    par_sort_type = BY_NTH;
 		else {
-		    sprintf (dsk_interp->result,
+		    char buffer[1024];
+		    snprintf(buffer, sizeof(buffer),
 			     "Don't know how to sort by %s.\n%s",
 			     argv[i], USAGE);
+		    Tcl_SetResult(dsk_interp, buffer, TCL_VOLATILE);
 		    return (TCL_ERROR);
 		}
 		break;
@@ -1427,14 +1430,18 @@ char *argv[];
 	    case 't':
 		par_append_char = 1;
 		break;
-	    default:
-		sprintf (dsk_interp->result, "Dont understand: -%c\n%s",
-			 argv[i][1], USAGE);
-		return (TCL_ERROR);
+	    default: {
+		    char buffer[1024];
+		    snprintf(buffer, sizeof(buffer),
+			     "Dont understand: -%c\n%s",
+			     argv[i][1], USAGE);
+		    Tcl_SetResult(dsk_interp, buffer, TCL_VOLATILE);
+		    return (TCL_ERROR);
+		}
 	    }
 	} else {
 	    if (*par_path) {
-		strcpy (dsk_interp->result, USAGE);
+		Tcl_SetResult(dsk_interp, USAGE, TCL_STATIC);
 		return (TCL_ERROR);
 	    }
 	    strcpy (par_path, argv[i]);
@@ -1444,7 +1451,7 @@ char *argv[];
     }
 
     if (!*par_path) {
-	strcpy (dsk_interp->result, USAGE);
+	Tcl_SetResult(dsk_interp, USAGE, TCL_STATIC);
 	return (TCL_ERROR);
     }
 
