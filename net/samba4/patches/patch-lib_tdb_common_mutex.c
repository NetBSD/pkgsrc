$NetBSD: patch-lib_tdb_common_mutex.c,v 1.2 2021/04/29 15:21:16 taca Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- lib/tdb/common/mutex.c.orig	2019-01-15 10:07:00.000000000 +0000
+++ lib/tdb/common/mutex.c
@@ -567,6 +567,7 @@ int tdb_mutex_init(struct tdb_context *t
 	}
 	m = tdb->mutexes;
 
+	memset(&ma, 0, sizeof(pthread_mutexattr_t));
 	ret = pthread_mutexattr_init(&ma);
 	if (ret != 0) {
 		goto fail_munmap;
@@ -587,6 +588,7 @@ int tdb_mutex_init(struct tdb_context *t
 	for (i=0; i<tdb->hash_size+1; i++) {
 		pthread_mutex_t *chain = &m->hashchains[i];
 
+		memset(chain, 0, sizeof(pthread_mutex_t));
 		ret = pthread_mutex_init(chain, &ma);
 		if (ret != 0) {
 			goto fail;
@@ -595,6 +597,7 @@ int tdb_mutex_init(struct tdb_context *t
 
 	m->allrecord_lock = F_UNLCK;
 
+	memset(&m->allrecord_mutex, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(&m->allrecord_mutex, &ma);
 	if (ret != 0) {
 		goto fail;
@@ -672,6 +675,7 @@ static bool tdb_mutex_locking_supported(
 
 	initialized = true;
 
+	memset(&ma, 0, sizeof(pthread_mutexattr_t));
 	ret = pthread_mutexattr_init(&ma);
 	if (ret != 0) {
 		return false;
@@ -688,6 +692,7 @@ static bool tdb_mutex_locking_supported(
 	if (ret != 0) {
 		goto cleanup_ma;
 	}
+	memset(&m, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(&m, &ma);
 	if (ret != 0) {
 		goto cleanup_ma;
@@ -868,6 +873,7 @@ _PUBLIC_ bool tdb_runtime_check_for_robu
 		goto cleanup;
 	}
 
+	memset(&ma, 0, sizeof(pthread_mutexattr_t));
 	ret = pthread_mutexattr_init(&ma);
 	if (ret != 0) {
 		goto cleanup;
@@ -885,6 +891,7 @@ _PUBLIC_ bool tdb_runtime_check_for_robu
 	if (ret != 0) {
 		goto cleanup;
 	}
+	memset(ptr, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(ptr, &ma);
 	if (ret != 0) {
 		goto cleanup;
