$NetBSD: patch-src_solx__devfs.c,v 1.5 2017/07/07 10:13:57 jperkin Exp $

Revert upstream commit fe556c48dad96717b0ba71d489575c6b90b46448 which breaks
device lookup completely on illumos.

--- src/solx_devfs.c.orig	2017-04-04 13:46:41.000000000 +0000
+++ src/solx_devfs.c
@@ -1,6 +1,6 @@
 /*
  * (C) Copyright IBM Corporation 2006
- * Copyright (c) 2007, 2009, 2011, 2012, 2016 Oracle and/or its affiliates.
+ * Copyright (c) 2007, 2009, 2011, 2012, 2015 Oracle and/or its affiliates.
  * All Rights Reserved.
  *
  * Permission is hereby granted, free of charge, to any person obtaining a
@@ -65,7 +65,7 @@ typedef struct nexus {
     int first_bus;
     int last_bus;
     int domain;
-    char *path;			/* for open */
+    char *path;			/* for errors/debugging; fd is all we need */
     char *dev_path;
     struct nexus *next;
 } nexus_t;
@@ -297,6 +297,7 @@ probe_nexus_node(di_node_t di_node, di_m
     int pci_node = 0;
     int first_bus = 0, last_bus = PCI_REG_BUS_G(PCI_REG_BUS_M);
     int domain = 0;
+    di_node_t rnode =  DI_NODE_NIL;
 #ifdef __sparc
     int bus_range_found = 0;
     int device_type_found = 0;
@@ -422,12 +423,21 @@ probe_nexus_node(di_node_t di_node, di_m
 	nexus->dev_path = strdup(nexus_dev_path);
 	di_devfs_path_free(nexus_dev_path);
 
+	if ((rnode = di_init(nexus->dev_path, DINFOCPYALL)) == DI_NODE_NIL) {
+	    (void) fprintf(stderr, "di_init failed: %s\n", strerror(errno));
+	    close(fd);
+	    free(nexus->path);
+	    free(nexus->dev_path);
+	    free(nexus);
+	    return (DI_WALK_TERMINATE);
+	}
+
 	/* Walk through devices under the rnode */
 	args.pinfo = pinfo;
 	args.nexus = nexus;
 	args.ret = 0;
 
-	(void) di_walk_node(di_node, DI_WALK_CLDFIRST, (void *)&args, probe_device_node);
+	(void) di_walk_node(rnode, DI_WALK_CLDFIRST, (void *)&args, probe_device_node);
 
 	close(fd);
 
@@ -435,6 +445,7 @@ probe_nexus_node(di_node_t di_node, di_m
 	    free(nexus->path);
 	    free(nexus->dev_path);
 	    free(nexus);
+	    di_fini(rnode);
 	    return (DI_WALK_TERMINATE);
 	}
 
@@ -446,6 +457,10 @@ probe_nexus_node(di_node_t di_node, di_m
 	free(nexus);
     }
 
+    if (rnode != DI_NODE_NIL) {
+	di_fini(rnode);
+    }
+
     return DI_WALK_CONTINUE;
 }
 
@@ -538,7 +553,7 @@ pci_device_solx_devfs_probe( struct pci_
      * starting to find if it is MEM/MEM64/IO
      * using libdevinfo
      */
-    if ((rnode = di_init(nexus->dev_path, DINFOCACHE)) == DI_NODE_NIL) {
+    if ((rnode = di_init(nexus->dev_path, DINFOCPYALL)) == DI_NODE_NIL) {
 	err = errno;
 	(void) fprintf(stderr, "di_init failed: %s\n", strerror(errno));
     } else {
@@ -1070,7 +1085,7 @@ pci_system_solx_devfs_create( void )
 	return 0;
     }
 
-    if ((di_node = di_init("/", DINFOCACHE)) == DI_NODE_NIL) {
+    if ((di_node = di_init("/", DINFOCPYALL)) == DI_NODE_NIL) {
 	err = errno;
 	(void) fprintf(stderr, "di_init() failed: %s\n",
 		       strerror(errno));
