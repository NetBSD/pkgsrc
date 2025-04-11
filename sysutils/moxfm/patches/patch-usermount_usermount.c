$NetBSD: patch-usermount_usermount.c,v 1.1 2025/04/11 01:49:11 nia Exp $

Convert errno to a string in a more standard way.

--- usermount/usermount.c.orig	2025-04-11 00:48:16.259958076 +0000
+++ usermount/usermount.c
@@ -34,7 +34,7 @@ void logAction(char *device, int err)
      now = time(NULL);
      fprintf(flog, "%s", asctime(localtime(&now)));
      if (err)
-	 fprintf(flog, "Unsuccessfull trial to mount %s by %s: %s\n", device, pwent->pw_name, sys_errlist[err]);
+	 fprintf(flog, "Unsuccessfull trial to mount %s by %s: %s\n", device, pwent->pw_name, strerror(err));
      else
 	 fprintf(flog, "%s mounted by %s\n", device, pwent->pw_name);
      fclose(flog);
@@ -118,7 +118,7 @@ int main(int argc, char *argv[])
      else errfl = 1;
      if (errfl)
      {
-	 fprintf(stderr, "usermount: Could not mount %s on %s: %s\n", entry->mnt_fsname, entry->mnt_dir, sys_errlist[errno]);
+	 fprintf(stderr, "usermount: Could not mount %s on %s: %s\n", entry->mnt_fsname, entry->mnt_dir, strerror(errno));
 #ifdef LOGFILE
 	 logAction(entry->mnt_fsname, errno);
 #endif
@@ -128,7 +128,7 @@ int main(int argc, char *argv[])
  }
  if  (!(mtab = setmntent(MTAB, "r+")) || addmntent(mtab, entry))
  {
-     fprintf(stderr, "usermount: Warning - error updating %s: %s\n", MTAB, sys_errlist[errno]);
+     fprintf(stderr, "usermount: Warning - error updating %s: %s\n", MTAB, strerror(errno));
      endmntent(mtab);
  }
 #ifdef SET_OWNER
