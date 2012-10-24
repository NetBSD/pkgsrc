--- src/pkcs11/pkcs11-global.c.orig	2012-10-22 09:11:56.000000000 +0200
+++ src/pkcs11/pkcs11-global.c	2012-10-22 09:12:14.000000000 +0200
@@ -43,9 +43,9 @@
 #if defined(HAVE_PTHREAD) && defined(PKCS11_THREAD_LOCKING)
 #include <pthread.h>
 CK_RV mutex_create(void **mutex)
 {
-	pthread_mutex_t *m = (pthread_mutex_t *) malloc(sizeof(*mutex));
+	pthread_mutex_t *m = (pthread_mutex_t *) malloc(sizeof(*m));
 	if (m == NULL)
 		return CKR_GENERAL_ERROR;;
 	pthread_mutex_init(m, NULL);
 	*mutex = m;
