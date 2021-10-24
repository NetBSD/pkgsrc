$NetBSD: patch-lib_dns_rbt.c,v 1.3 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.
* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/dns/rbt.c
@@ -319,12 +319,13 @@ Name(dns_rbtnode_t *node) {
 }
 
 static void
-hexdump(const char *desc, unsigned char *data, size_t size) {
+hexdump(const char *desc, void *blob, size_t size) {
 	char hexdump[BUFSIZ * 2 + 1];
 	isc_buffer_t b;
 	isc_region_t r;
 	isc_result_t result;
 	size_t bytes;
+	uint8_t *data = blob;
 
 	fprintf(stderr, "%s: ", desc);
 	do {
@@ -342,6 +343,10 @@ hexdump(const char *desc, unsigned char 
 }
 #endif /* DEBUG */
 
+#if !defined(inline) && defined(__powerpc__)
+#define        inline  /**/
+#endif
+
 /*
  * Upper node is the parent of the root of the passed node's
  * subtree. The passed node must not be NULL.
@@ -748,7 +753,7 @@ dns_rbt_serialize_tree(FILE *file, dns_r
 
 	isc_crc64_final(&crc);
 #ifdef DEBUG
-	hexdump("serializing CRC", (unsigned char *)&crc, sizeof(crc));
+	hexdump("serializing CRC", &crc, sizeof(crc));
 #endif /* ifdef DEBUG */
 
 	/* Serialize header */
@@ -769,7 +774,7 @@ cleanup:
 			result = ISC_R_INVALIDFILE; \
 			goto cleanup;               \
 		}                                   \
-	} while (0);
+	} while(0)
 
 static isc_result_t
 treefix(dns_rbt_t *rbt, void *base, size_t filesize, dns_rbtnode_t *n,
@@ -880,7 +885,7 @@ treefix(dns_rbt_t *rbt, void *base, size
 	fprintf(stderr, "deserialize ");
 	dns_name_print(&nodename, stderr);
 	fprintf(stderr, "\n");
-	hexdump("node header", (unsigned char *)&header, sizeof(dns_rbtnode_t));
+	hexdump("node header", &header, sizeof(dns_rbtnode_t));
 	hexdump("node data", node_data, datasize);
 #endif /* ifdef DEBUG */
 	isc_crc64_update(crc, (const uint8_t *)&header, sizeof(dns_rbtnode_t));
@@ -956,7 +961,7 @@ dns_rbt_deserialize_tree(void *base_addr
 
 	isc_crc64_final(&crc);
 #ifdef DEBUG
-	hexdump("deserializing CRC", (unsigned char *)&crc, sizeof(crc));
+	hexdump("deserializing CRC", &crc, sizeof(crc));
 #endif /* ifdef DEBUG */
 
 	/* Check file hash */
