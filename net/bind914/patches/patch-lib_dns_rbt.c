$NetBSD: patch-lib_dns_rbt.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/rbt.c
@@ -315,12 +315,13 @@ Name(dns_rbtnode_t *node) {
 }
 
 static void
-hexdump(const char *desc, unsigned char *data, size_t size) {
+hexdump(const char *desc, void *blob, size_t size) {
 	char hexdump[BUFSIZ * 2 + 1];
 	isc_buffer_t b;
 	isc_region_t r;
 	isc_result_t result;
 	size_t bytes;
+	uint8_t *data  = blob;
 
 	fprintf(stderr, "%s: ", desc);
 	do {
@@ -338,6 +339,10 @@ hexdump(const char *desc, unsigned char 
 }
 #endif /* DEBUG */
 
+#if !defined(inline) && defined(__powerpc__)
+#define        inline  /**/
+#endif
+
 /*
  * Upper node is the parent of the root of the passed node's
  * subtree. The passed node must not be NULL.
@@ -592,7 +597,7 @@ serialize_node(FILE *file, dns_rbtnode_t
 	fprintf(stderr, "serialize ");
 	dns_name_print(&nodename, stderr);
 	fprintf(stderr, "\n");
-	hexdump("node header", (unsigned char*) &temp_node,
+	hexdump("node header", &temp_node,
 		sizeof(dns_rbtnode_t));
 	hexdump("node data", node_data, datasize);
 #endif
@@ -712,7 +717,7 @@ dns_rbt_serialize_tree(FILE *file, dns_r
 
 	isc_crc64_final(&crc);
 #ifdef DEBUG
-	hexdump("serializing CRC", (unsigned char *)&crc, sizeof(crc));
+	hexdump("serializing CRC", &crc, sizeof(crc));
 #endif
 
 	/* Serialize header */
@@ -833,7 +838,7 @@ treefix(dns_rbt_t *rbt, void *base, size
 	fprintf(stderr, "deserialize ");
 	dns_name_print(&nodename, stderr);
 	fprintf(stderr, "\n");
-	hexdump("node header", (unsigned char *) &header,
+	hexdump("node header", &header,
 		sizeof(dns_rbtnode_t));
 	hexdump("node data", node_data, datasize);
 #endif
@@ -913,7 +918,7 @@ dns_rbt_deserialize_tree(void *base_addr
 
 	isc_crc64_final(&crc);
 #ifdef DEBUG
-	hexdump("deserializing CRC", (unsigned char *)&crc, sizeof(crc));
+	hexdump("deserializing CRC", &crc, sizeof(crc));
 #endif
 
 	/* Check file hash */
