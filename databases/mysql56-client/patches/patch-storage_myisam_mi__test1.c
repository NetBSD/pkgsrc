$NetBSD: patch-storage_myisam_mi__test1.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_test1.c.orig	2013-04-28 13:59:06.000000000 +0000
+++ storage/myisam/mi_test1.c
@@ -265,14 +265,14 @@ static int run_test(const char *filename
 	if (verbose || (flags[j] >= 1 ||
 			(error && my_errno != HA_ERR_KEY_NOT_FOUND)))
 	  printf("key: '%.*s'  mi_rkey:  %3d  errno: %3d\n",
-		 (int) key_length,key+test(null_fields),error,my_errno);
+		 (int) key_length,key+my_test(null_fields),error,my_errno);
       }
       else
       {
 	error=mi_delete(file,read_record);
 	if (verbose || error)
 	  printf("key: '%.*s'  mi_delete: %3d  errno: %3d\n",
-		 (int) key_length, key+test(null_fields), error, my_errno);
+		 (int) key_length, key+my_test(null_fields), error, my_errno);
 	if (! error)
 	{
 	  deleted++;
@@ -293,7 +293,7 @@ static int run_test(const char *filename
 	(error && (flags[i] != 0 || my_errno != HA_ERR_KEY_NOT_FOUND)))
     {
       printf("key: '%.*s'  mi_rkey: %3d  errno: %3d  record: %s\n",
-	     (int) key_length,key+test(null_fields),error,my_errno,record+1);
+	     (int) key_length,key+my_test(null_fields),error,my_errno,record+1);
     }
   }
 
