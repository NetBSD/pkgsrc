$NetBSD: patch-lib_dns_rbt.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.
* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/rbt.c
@@ -301,12 +301,13 @@ Name(dns_rbtnode_t *node) {
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
@@ -324,6 +325,10 @@ hexdump(const char *desc, unsigned char 
 }
 #endif /* DEBUG */
 
+#if !defined(inline) && defined(__powerpc__)
+#define        inline  /**/
+#endif
+
 /*
  * Upper node is the parent of the root of the passed node's
  * subtree. The passed node must not be NULL.
@@ -545,6 +550,9 @@ serialize_node(FILE *file, dns_rbtnode_t
 	off_t file_position;
 	unsigned char *node_data = NULL;
 	size_t datasize;
+#ifdef DEBUG
+	dns_name_t nodename;
+#endif
 
 	INSIST(node != NULL);
 
@@ -597,10 +605,12 @@ serialize_node(FILE *file, dns_rbtnode_t
 	CHECK(isc_stdio_write(node_data, 1, datasize, file, NULL));
 
 #ifdef DEBUG
+	dns_name_init(&nodename, NULL);
+	NODENAME(node, &nodename);
 	fprintf(stderr, "serialize ");
-	dns_name_print(name, stderr);
+	dns_name_print(&nodename, stderr);
 	fprintf(stderr, "\n");
-	hexdump("node header", (unsigned char *)&temp_node,
+	hexdump("node header", &temp_node,
 		sizeof(dns_rbtnode_t));
 	hexdump("node data", node_data, datasize);
 #endif /* ifdef DEBUG */
@@ -721,7 +731,7 @@ dns_rbt_serialize_tree(FILE *file, dns_r
 
 	isc_crc64_final(&crc);
 #ifdef DEBUG
-	hexdump("serializing CRC", (unsigned char *)&crc, sizeof(crc));
+	hexdump("serializing CRC", &crc, sizeof(crc));
 #endif /* ifdef DEBUG */
 
 	/* Serialize header */
@@ -742,7 +752,7 @@ cleanup:
 			result = ISC_R_INVALIDFILE; \
 			goto cleanup;               \
 		}                                   \
-	} while (0);
+	} while(/*CONSTCOND*/0)
 
 static isc_result_t
 treefix(dns_rbt_t *rbt, void *base, size_t filesize, dns_rbtnode_t *n,
@@ -852,7 +862,7 @@ treefix(dns_rbt_t *rbt, void *base, size
 	fprintf(stderr, "deserialize ");
 	dns_name_print(&nodename, stderr);
 	fprintf(stderr, "\n");
-	hexdump("node header", (unsigned char *)&header, sizeof(dns_rbtnode_t));
+	hexdump("node header", &header, sizeof(dns_rbtnode_t));
 	hexdump("node data", node_data, datasize);
 #endif /* ifdef DEBUG */
 	isc_crc64_update(crc, (const uint8_t *)&header, sizeof(dns_rbtnode_t));
@@ -928,7 +938,7 @@ dns_rbt_deserialize_tree(void *base_addr
 
 	isc_crc64_final(&crc);
 #ifdef DEBUG
-	hexdump("deserializing CRC", (unsigned char *)&crc, sizeof(crc));
+	hexdump("deserializing CRC", &crc, sizeof(crc));
 #endif /* ifdef DEBUG */
 
 	/* Check file hash */
