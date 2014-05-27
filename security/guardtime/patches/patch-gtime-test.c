$NetBSD: patch-gtime-test.c,v 1.1 2014/05/27 09:59:53 joerg Exp $

--- gtime-test.c.orig	2014-05-26 19:10:53.000000000 +0000
+++ gtime-test.c
@@ -1173,7 +1173,6 @@ int parse_digest(char *arg, GTDataHash *
 	int alg_id;
 	const EVP_MD *evp_md;
 	int len;
-	GTDataHash *tmp_data_hash = NULL;
 	unsigned char* tmp_hash = NULL;
 	size_t tmp_length;
 	
@@ -1203,13 +1202,6 @@ int parse_digest(char *arg, GTDataHash *
 		}
 	}
 	
-	tmp_data_hash = (GTDataHash *) GT_malloc(sizeof(GTDataHash));
-	if (tmp_data_hash == NULL) {
-		res = GT_OUT_OF_MEMORY;
-		goto e;
-	}
-	tmp_data_hash->digest = NULL;
-	tmp_data_hash->context = NULL;
 	tmp_length = EVP_MD_size(evp_md);
 	tmp_hash = (unsigned char *) GT_malloc(tmp_length);
 	if (tmp_hash == NULL) {
@@ -1233,20 +1225,12 @@ int parse_digest(char *arg, GTDataHash *
 			tmp_hash[j] = ch;
 		}
 	}
-	tmp_data_hash->digest = tmp_hash;
-	tmp_hash = NULL;
-	tmp_data_hash->digest_length = tmp_length;
-	tmp_data_hash->algorithm = alg_id;
-	*data_hash = tmp_data_hash;
-	tmp_data_hash = NULL;
-	
-	res = GT_OK;
+	res = GTDataHash_fromAlgorithmAndValue(alg_id, tmp_hash, tmp_length, data_hash);
 	
 e:
 	if (res == GT_OUT_OF_MEMORY)
 		fprintf(stderr, "%s\n", GT_getErrorString(res));
 	GT_free(tmp_hash);
-	GTDataHash_free(tmp_data_hash);
 	return res;
 }
 
