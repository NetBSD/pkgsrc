$NetBSD: patch-src_solx__devfs.c,v 1.1 2013/05/15 03:20:16 richard Exp $

Solaris: probe improvementHEADmaster
Remove pcitool dependency in probing phase. Use the data collected from devinfo tree instead in creating pci file system. 

Solaris: Add domain support for sparc platform
As a result the code of finding nexus node for a device in sparc is simplified and made the same as x86. 

libpciaccess: sparc rom read fix
Get rom address and size from device's "assigned-addresses" property if they exist. 

libpciaccess: implementation of boot_vga in Solaris

libpciaccess: fix memory usage errors
This patch fixes memory usage errors that only occur on large SPARC machines with more than 256 PCI devices. In this case, memory is being used after it has been freed by calls to both free() and realloc(). This error was introduced by a previous patch: 2011-03-30 Solaris support for multiple PCI segments (domains) 

Solaris: Implement map_legacy & legacy_io functions

Solaris: refactor pci_device_solx_devfs_map_range to reduce code duplication
The sparc & x86 cases were doing essentially the same things with different paths, so make the path setup be inside the platform specific #ifdefs, make the open, mmap, & error handling common code. 

--- src/solx_devfs.c.orig	2012-04-09 17:02:57.000000000 +0000
+++ src/solx_devfs.c
@@ -1,6 +1,6 @@
 /*
  * (C) Copyright IBM Corporation 2006
- * Copyright (c) 2007, 2009, 2011, Oracle and/or its affiliates.
+ * Copyright (c) 2007, 2009, 2011, 2012, 2013 Oracle and/or its affiliates.
  * All Rights Reserved.
  *
  * Permission is hereby granted, free of charge, to any person obtaining a
@@ -38,6 +38,11 @@
 #include <libdevinfo.h>
 #include "pci_tools.h"
 
+#ifdef __x86
+# include <sys/sysi86.h>
+# include <sys/psw.h>
+#endif
+
 #include "pciaccess.h"
 #include "pciaccess_private.h"
 
@@ -46,11 +51,6 @@
 #define	INITIAL_NUM_DEVICES	256
 #define	CELL_NUMS_1275	(sizeof(pci_regspec_t) / sizeof(uint_t))
 
-typedef union {
-    uint8_t bytes[16 * sizeof (uint32_t)];
-    uint32_t dwords[16];
-} pci_conf_hdr_t;
-
 typedef struct i_devnode {
     uint8_t bus;
     uint8_t dev;
@@ -66,11 +66,6 @@ typedef struct nexus {
     char *path;			/* for errors/debugging; fd is all we need */
     char *dev_path;
     struct nexus *next;
-#ifdef __sparc
-    struct pci_device **devlist;
-    volatile size_t num_allocated_elems;
-    volatile size_t num_devices;
-#endif
 } nexus_t;
 
 typedef struct probe_info {
@@ -79,6 +74,17 @@ typedef struct probe_info {
     struct pci_device_private * volatile devices;
 } probe_info_t;
 
+typedef struct probe_args {
+    probe_info_t *pinfo;
+    nexus_t *nexus;
+    int ret;
+} probe_args_t;
+
+typedef struct property_info {
+    const char *name;
+    int value;
+} property_info_t;
+
 static nexus_t *nexus_list = NULL;
 #if !defined(__sparc)
 static int xsvc_fd = -1;
@@ -86,6 +92,7 @@ static int xsvc_fd = -1;
 
 #ifdef __sparc
 static di_prom_handle_t di_phdl;
+static size_t  nexus_count = 0;
 #endif
 
 /*
@@ -126,22 +133,6 @@ static di_prom_handle_t di_phdl;
 # define U45_SB_CLASS_RID	0x06040000
 #endif
 
-#ifdef __sparc
-static nexus_t *
-find_nexus_for_dev(struct pci_device *dev)
-{
-    nexus_t *nexus;
-    int i;
-
-    for (nexus = nexus_list ; nexus != NULL ; nexus = nexus->next) {
-	for (i = 0; i < nexus->num_devices; i++) {
-	    if (nexus->devlist[i] == dev)
-		return nexus;
-	}
-    }
-    return NULL;
-}
-#else
 static nexus_t *
 find_nexus_for_bus( int domain, int bus )
 {
@@ -155,16 +146,6 @@ find_nexus_for_bus( int domain, int bus
     }
     return NULL;
 }
-#endif
-
-#define GET_CONFIG_VAL_8(offset) (config_hdr.bytes[offset])
-#define GET_CONFIG_VAL_16(offset) \
-    (uint16_t) (GET_CONFIG_VAL_8(offset) + (GET_CONFIG_VAL_8(offset+1) << 8))
-#define GET_CONFIG_VAL_32(offset) \
-    (uint32_t) (GET_CONFIG_VAL_8(offset) + 		\
-		(GET_CONFIG_VAL_8(offset+1) << 8) +	\
-		(GET_CONFIG_VAL_8(offset+2) << 16) +	\
-		(GET_CONFIG_VAL_8(offset+3) << 24))
 
 /*
  * Release all the resources
@@ -185,19 +166,6 @@ pci_system_solx_devfs_destroy( void )
 	close(nexus->fd);
 	free(nexus->path);
 	free(nexus->dev_path);
-#ifdef __sparc
-	{
-	    struct pci_device *dev;
-	    int i;
-
-	    for (i = 0; i < nexus->num_devices; i++) {
-		dev = nexus->devlist[i];
-		if (MAPPING_DEV_PATH(dev))
-		    di_devfs_path_free((char *) MAPPING_DEV_PATH(dev));
-	    }
-	}
-	free(nexus->devlist);
-#endif
 	free(nexus);
     }
     nexus_list = NULL;
@@ -213,316 +181,122 @@ pci_system_solx_devfs_destroy( void )
 #endif
 }
 
+
+#ifdef __sparc
 /*
- * Retrieve first 16 dwords of device's config header, except for the first
- * dword.  First 16 dwords are defined by the PCI specification.
+ * Release resources per device
  */
-static int
-get_config_header(int fd, uint8_t bus_no, uint8_t dev_no, uint8_t func_no,
-		  pci_conf_hdr_t *config_hdr_p)
+static void
+pci_system_solx_devfs_destroy_device( struct pci_device *dev )
 {
-    pcitool_reg_t cfg_prg;
-    int i;
-    int rval = 0;
-
-    /* Prepare a local pcitool_reg_t so as to not disturb the caller's. */
-    cfg_prg.offset = 0;
-    cfg_prg.acc_attr = PCITOOL_ACC_ATTR_SIZE_4 + NATIVE_ENDIAN;
-    cfg_prg.bus_no = bus_no;
-    cfg_prg.dev_no = dev_no;
-    cfg_prg.func_no = func_no;
-    cfg_prg.barnum = 0;
-    cfg_prg.user_version = PCITOOL_USER_VERSION;
-
-    /* Get dwords 1-15 of config space. They must be read as uint32_t. */
-    for (i = 1; i < (sizeof (pci_conf_hdr_t) / sizeof (uint32_t)); i++) {
-	cfg_prg.offset += sizeof (uint32_t);
-	if ((rval = ioctl(fd, PCITOOL_DEVICE_GET_REG, &cfg_prg)) != 0) {
-	    break;
-	}
-	config_hdr_p->dwords[i] = (uint32_t)cfg_prg.data;
-    }
-
-    return (rval);
+   if (MAPPING_DEV_PATH(dev))
+	di_devfs_path_free((char *) MAPPING_DEV_PATH(dev));
 }
+#endif
 
 
-/*
- * Probe device's functions.  Modifies many fields in the prg_p.
- */
 static int
-probe_dev(nexus_t *nexus, pcitool_reg_t *prg_p, probe_info_t *pinfo)
+probe_device_node(di_node_t node, void *arg)
 {
-    pci_conf_hdr_t	config_hdr;
-    boolean_t		multi_function_device;
-    int8_t		func;
-    int8_t		first_func = 0;
-    int8_t		last_func = PCI_REG_FUNC_M >> PCI_REG_FUNC_SHIFT;
-    int			rval = 0;
-    struct pci_device *	pci_base;
-
-    /*
-     * Loop through at least func=first_func.  Continue looping through
-     * functions if there are no errors and the device is a multi-function
-     * device.
-     *
-     * (Note, if first_func == 0, header will show whether multifunction
-     * device and set multi_function_device.  If first_func != 0, then we
-     * will force the loop as the user wants a specific function to be
-     * checked.
-     */
-    for (func = first_func, multi_function_device = B_FALSE;
-	 ((func <= last_func) &&
-	  ((func == first_func) || (multi_function_device)));
-	 func++) {
-	prg_p->func_no = func;
-
-	/*
-	 * Four things can happen here:
-	 *
-	 * 1) ioctl comes back as EFAULT and prg_p->status is
-	 *    PCITOOL_INVALID_ADDRESS.  There is no device at this location.
-	 *
-	 * 2) ioctl comes back successful and the data comes back as
-	 *    zero.  Config space is mapped but no device responded.
-	 *
-	 * 3) ioctl comes back successful and the data comes back as
-	 *    non-zero.  We've found a device.
-	 *
-	 * 4) Some other error occurs in an ioctl.
-	 */
-
-	prg_p->status = PCITOOL_SUCCESS;
-	prg_p->offset = 0;
-	prg_p->data = 0;
-	prg_p->user_version = PCITOOL_USER_VERSION;
-
-	errno = 0;
-	if (((rval = ioctl(nexus->fd, PCITOOL_DEVICE_GET_REG, prg_p)) != 0) ||
-	    (prg_p->data == 0xffffffff)) {
-
-	    /*
-	     * Accept errno == EINVAL along with status of
-	     * PCITOOL_OUT_OF_RANGE because some systems
-	     * don't implement the full range of config space.
-	     * Leave the loop quietly in this case.
-	     */
-	    if ((errno == EINVAL) ||
-		(prg_p->status == PCITOOL_OUT_OF_RANGE)) {
-		break;
-	    }
+    int *retbuf = NULL;
+    int len = 0, i;
+    struct pci_device	*pci_base;
+    probe_info_t *pinfo = ((probe_args_t *)arg)->pinfo;
+    nexus_t *nexus = ((probe_args_t *)arg)->nexus;
+    property_info_t property_list[] = {
+        { "class-code", 0 },
+        { "device-id", 0 },
+        { "vendor-id", 0 },
+        { "revision-id", 0},
+        { "subsystem-vendor-id", 0},
+        { "subsystem-id", 0},
+    };
+#define NUM_PROPERTIES		sizeof(property_list)/sizeof(property_info_t)
 
-	    /*
-	     * Exit silently with ENXIO as this means that there are
-	     * no devices under the pci root nexus.
-	     */
-	    else if ((errno == ENXIO) &&
-		     (prg_p->status == PCITOOL_IO_ERROR)) {
-		break;
-	    }
+    len = di_prop_lookup_ints(DDI_DEV_T_ANY, node, "reg", &retbuf);
 
-	    /*
-	     * Expect errno == EFAULT along with status of
-	     * PCITOOL_INVALID_ADDRESS because there won't be
-	     * devices at each stop.  Quit on any other error.
-	     */
-	    else if (((errno != EFAULT) ||
-		      (prg_p->status != PCITOOL_INVALID_ADDRESS)) &&
-		     (prg_p->data != 0xffffffff)) {
 #ifdef __sparc
-/* on sparc, devices can be enumerated discontiguously. Do not quit */
-		rval = 0;
+    if ((len <= 0) && di_phdl)
+	len = di_prom_prop_lookup_ints(di_phdl, node, "reg", &retbuf);
 #endif
-		break;
-	    }
 
-	    /*
-	     * If no function at this location,
-	     * just advance to the next function.
-	     */
-	    else {
-		rval = 0;
-	    }
-
-	    /*
-	     * Data came back as 0.
-	     * Treat as unresponsive device and check next device.
-	     */
-	} else if (prg_p->data == 0) {
-	    rval = 0;
-	    break;	/* Func loop. */
-
-	    /* Found something. */
-	} else {
-	    config_hdr.dwords[0] = (uint32_t)prg_p->data;
-
-	    /* Get the rest of the PCI header. */
-	    if ((rval = get_config_header(nexus->fd, prg_p->bus_no,
-					  prg_p->dev_no, prg_p->func_no,
-					  &config_hdr)) != 0) {
-		break;
-	    }
-
-	    /*
-	     * Special case for the type of Southbridge found on
-	     * Ultra-45 and other sun4u fire workstations.
-	     */
-	    if ((config_hdr.dwords[0] == U45_SB_DEVID_VID) &&
-		(config_hdr.dwords[2] == U45_SB_CLASS_RID)) {
-		rval = ECANCELED;
-		break;
-	    }
-
-	    /*
-	     * Found one device with bus number, device number and
-	     * function number.
-	     */
-
-	    pci_base = &pinfo->devices[pinfo->num_devices].base;
-
-	    pci_base->domain = nexus->domain;
-	    pci_base->bus = prg_p->bus_no;
-	    pci_base->dev = prg_p->dev_no;
-	    pci_base->func = func;
-
-	    /*
-	     * for the format of device_class, see struct pci_device;
-	     */
-
-	    pci_base->device_class =
-		(GET_CONFIG_VAL_8(PCI_CONF_BASCLASS) << 16) |
-		(GET_CONFIG_VAL_8(PCI_CONF_SUBCLASS) << 8) |
-		GET_CONFIG_VAL_8(PCI_CONF_PROGCLASS);
-
-	    pci_base->revision		= GET_CONFIG_VAL_8(PCI_CONF_REVID);
-	    pci_base->vendor_id		= GET_CONFIG_VAL_16(PCI_CONF_VENID);
-	    pci_base->device_id		= GET_CONFIG_VAL_16(PCI_CONF_DEVID);
-	    pci_base->subvendor_id 	= GET_CONFIG_VAL_16(PCI_CONF_SUBVENID);
-	    pci_base->subdevice_id 	= GET_CONFIG_VAL_16(PCI_CONF_SUBSYSID);
-	    pci_base->irq		= GET_CONFIG_VAL_8(PCI_CONF_ILINE);
+    /* Exclude usb devices */
+    if (len < 5) {
+	return DI_WALK_CONTINUE;
+    }
 
-	    pinfo->devices[pinfo->num_devices].header_type
-					= GET_CONFIG_VAL_8(PCI_CONF_HEADER);
+    pci_base = &pinfo->devices[pinfo->num_devices].base;
 
-#ifdef DEBUG
-	    fprintf(stderr,
-		    "nexus = %s, busno = %x, devno = %x, funcno = %x\n",
-		    nexus->path, prg_p->bus_no, prg_p->dev_no, func);
-#endif
-
-	    pinfo->num_devices++;
-	    if (pinfo->num_devices == pinfo->num_allocated_elems) {
-		struct pci_device_private *new_devs;
-		size_t new_num_elems = pinfo->num_allocated_elems * 2;
-
-		new_devs = realloc(pinfo->devices,
-			new_num_elems * sizeof (struct pci_device_private));
-		if (new_devs == NULL) {
-		    (void) fprintf(stderr,
-			           "Error allocating memory for PCI devices:"
-				   " %s\n discarding additional devices\n",
-				   strerror(errno));
-		    return (rval);
-		}
-		(void) memset(&new_devs[pinfo->num_devices], 0,
-			pinfo->num_allocated_elems *
-			sizeof (struct pci_device_private));
-		pinfo->num_allocated_elems = new_num_elems;
-		pinfo->devices = new_devs;
-	    }
+    pci_base->domain = nexus->domain;
+    pci_base->bus = PCI_REG_BUS_G(retbuf[0]);
+    pci_base->dev = PCI_REG_DEV_G(retbuf[0]);
+    pci_base->func  = PCI_REG_FUNC_G(retbuf[0]);
 
+    /* Get property values */
+    for (i = 0; i < NUM_PROPERTIES; i++) {
+	len = di_prop_lookup_ints(DDI_DEV_T_ANY, node,
+		property_list[i].name, &retbuf);
 #ifdef __sparc
-	    nexus->devlist[nexus->num_devices++] = pci_base;
-
-	    if (nexus->num_devices == nexus->num_allocated_elems) {
-		struct pci_device **new_devs;
-		size_t new_num_elems = nexus->num_allocated_elems * 2;
-
-		new_devs = realloc(nexus->devlist,
-			new_num_elems * sizeof (struct pci_device *));
-		if (new_devs == NULL)
-		    return (rval);
-		(void) memset(&new_devs[nexus->num_devices], 0,
-			nexus->num_allocated_elems *
-			sizeof (struct pci_device *));
-		nexus->num_allocated_elems = new_num_elems;
-		nexus->devlist = new_devs;
-	    }
+	if ((len <= 0) && di_phdl)
+	    len = di_prom_prop_lookup_ints(di_phdl, node,
+		property_list[i].name, &retbuf);
 #endif
 
-	    /*
-	     * Accommodate devices which state their
-	     * multi-functionality only in their function 0 config
-	     * space.  Note multi-functionality throughout probing
-	     * of all of this device's functions.
-	     */
-	    if (config_hdr.bytes[PCI_CONF_HEADER] & PCI_HEADER_MULTI) {
-		multi_function_device = B_TRUE;
-	    }
+	if (len > 0)
+	    property_list[i].value = retbuf[0];
+	else {
+	    /* a device must have property "class-code", "device-id", "vendor-id" */
+	    if (i < 3)
+		return DI_WALK_CONTINUE;
+#ifdef DEBUG
+	    fprintf(stderr, "cannot get property \"%s\" for nexus = %s :\n",
+		property_list[i].name, nexus->path);
+	    fprintf(stderr, "	domain = %x, busno = %x, devno = %x, funcno = %x\n",
+		pci_base->domain, pci_base->bus, pci_base->dev, pci_base->func);
+#endif
 	}
     }
 
-    return (rval);
-}
+    if ((property_list[1].value == 0) && (property_list[2].value == 0))
+	return DI_WALK_CONTINUE;
 
+    pci_base->device_class = property_list[0].value;
+    pci_base->device_id = property_list[1].value;
+    pci_base->vendor_id = property_list[2].value;
+    pci_base->revision = property_list[3].value;
+    pci_base->subvendor_id = property_list[4].value;
+    pci_base->subdevice_id = property_list[5].value;
 
-/*
- * Solaris version
- * Probe a given nexus config space for devices.
- *
- * fd is the file descriptor of the nexus.
- * input_args contains commandline options as specified by the user.
- */
-static int
-do_probe(nexus_t *nexus, probe_info_t *pinfo)
-{
-    pcitool_reg_t prg;
-    uint32_t bus;
-    uint8_t dev;
-    uint32_t last_bus = nexus->last_bus;
-    uint8_t last_dev = PCI_REG_DEV_M >> PCI_REG_DEV_SHIFT;
-    uint8_t first_bus = nexus->first_bus;
-    uint8_t first_dev = 0;
-    int rval = 0;
-
-    prg.barnum = 0;	/* Config space. */
-
-    /* Must read in 4-byte quantities. */
-    prg.acc_attr = PCITOOL_ACC_ATTR_SIZE_4 + NATIVE_ENDIAN;
-
-    prg.data = 0;
-
-    /*
-     * Loop through all valid bus / dev / func combinations to check for
-     * all devices, with the following exceptions:
-     *
-     * When nothing is found at function 0 of a bus / dev combination, skip
-     * the other functions of that bus / dev combination.
-     *
-     * When a found device's function 0 is probed and it is determined that
-     * it is not a multifunction device, skip probing of that device's
-     * other functions.
-     */
-    for (bus = first_bus; ((bus <= last_bus) && (rval == 0)); bus++) {
-	prg.bus_no = (uint8_t)bus;
-
-	for (dev = first_dev; ((dev <= last_dev) && (rval == 0)); dev++) {
-	    prg.dev_no = dev;
-	    rval = probe_dev(nexus, &prg, pinfo);
-	}
-
-	/*
-	 * Ultra-45 southbridge workaround:
-	 * ECANCELED tells to skip to the next bus.
-	 */
-	if (rval == ECANCELED) {
-	    rval = 0;
-	}
+#ifdef DEBUG
+    fprintf(stderr,
+	    "nexus = %s, domain = %x, busno = %x, devno = %x, funcno = %x\n",
+	    nexus->path, pci_base->domain, pci_base->bus, pci_base->dev, pci_base->func);
+#endif
+
+    pinfo->num_devices++;
+    if (pinfo->num_devices == pinfo->num_allocated_elems) {
+	struct pci_device_private *new_devs;
+	size_t new_num_elems = pinfo->num_allocated_elems * 2;
+
+	new_devs = realloc(pinfo->devices,
+	new_num_elems * sizeof (struct pci_device_private));
+	if (new_devs == NULL) {
+	    (void) fprintf(stderr,
+	           "Error allocating memory for PCI devices:"
+		   " %s\n discarding additional devices\n",
+		   strerror(errno));
+	    ((probe_args_t *)arg)->ret = 1;
+	    return (DI_WALK_TERMINATE);
+	}
+	(void) memset(&new_devs[pinfo->num_devices], 0,
+		pinfo->num_allocated_elems *
+		sizeof (struct pci_device_private));
+	pinfo->num_allocated_elems = new_num_elems;
+	pinfo->devices = new_devs;
     }
 
-    return (rval);
+    return (DI_WALK_CONTINUE);
 }
-
 /*
  * This function is called from di_walk_minor() when any PROBE is processed
  */
@@ -542,6 +316,7 @@ probe_nexus_node(di_node_t di_node, di_m
     int pci_node = 0;
     int first_bus = 0, last_bus = PCI_REG_BUS_G(PCI_REG_BUS_M);
     int domain = 0;
+    di_node_t rnode =  DI_NODE_NIL;
 #ifdef __sparc
     int bus_range_found = 0;
     int device_type_found = 0;
@@ -552,6 +327,7 @@ probe_nexus_node(di_node_t di_node, di_m
 #ifdef DEBUG
     nexus_name = di_devfs_minor_path(minor);
     fprintf(stderr, "-- device name: %s\n", nexus_name);
+    di_devfs_path_free(nexus_name);
 #endif
 
     for (prop = di_prop_next(di_node, NULL); prop != NULL;
@@ -591,12 +367,16 @@ probe_nexus_node(di_node_t di_node, di_m
 #endif
 	    }
 	}
+#ifdef __sparc
+	domain = nexus_count;
+#else
 	else if (strcmp(prop_name, "pciseg") == 0) {
 	    numval = di_prop_ints(prop, &ints);
 	    if (numval == 1) {
 		domain = ints[0];
 	    }
 	}
+#endif
     }
 
 #ifdef __sparc
@@ -636,15 +416,7 @@ probe_nexus_node(di_node_t di_node, di_m
     nexus->domain = domain;
 
 #ifdef __sparc
-    if ((nexus->devlist = calloc(INITIAL_NUM_DEVICES,
-			sizeof (struct pci_device *))) == NULL) {
-	(void) fprintf(stderr, "Error allocating memory for nexus devlist: %s\n",
-                       strerror(errno));
-	free (nexus);
-	return (DI_WALK_TERMINATE);
-    }
-    nexus->num_allocated_elems = INITIAL_NUM_DEVICES;
-    nexus->num_devices = 0;
+    nexus_count++;
 #endif
 
     nexus_name = di_devfs_minor_path(minor);
@@ -664,28 +436,50 @@ probe_nexus_node(di_node_t di_node, di_m
 #endif
 
     if ((fd = open(nexus_path, O_RDWR | O_CLOEXEC)) >= 0) {
+	probe_args_t args;
+
 	nexus->fd = fd;
 	nexus->path = strdup(nexus_path);
 	nexus_dev_path = di_devfs_path(di_node);
 	nexus->dev_path = strdup(nexus_dev_path);
 	di_devfs_path_free(nexus_dev_path);
-	if ((do_probe(nexus, pinfo) != 0) && (errno != ENXIO)) {
-	    (void) fprintf(stderr, "Error probing node %s: %s\n",
-			   nexus_path, strerror(errno));
-	    (void) close(fd);
+
+	if ((rnode = di_init(nexus->dev_path, DINFOCPYALL)) == DI_NODE_NIL) {
+	    (void) fprintf(stderr, "di_init failed: %s\n", strerror(errno));
+	    close(nexus->fd);
 	    free(nexus->path);
 	    free(nexus->dev_path);
 	    free(nexus);
-	} else {
-	    nexus->next = nexus_list;
-	    nexus_list = nexus;
+	    return (DI_WALK_TERMINATE);
 	}
+
+	/* Walk through devices under the rnode */
+	args.pinfo = pinfo;
+	args.nexus = nexus;
+	args.ret = 0;
+
+	(void) di_walk_node(rnode, DI_WALK_CLDFIRST, (void *)&args, probe_device_node);
+	if (args.ret) {
+	    close(nexus->fd);
+	    free(nexus->path);
+	    free(nexus->dev_path);
+	    free(nexus);
+	    di_fini(rnode);
+	    return (DI_WALK_TERMINATE);
+	}
+
+	nexus->next = nexus_list;
+	nexus_list = nexus;
     } else {
 	(void) fprintf(stderr, "Error opening %s: %s\n",
 		       nexus_path, strerror(errno));
 	free(nexus);
     }
 
+    if (rnode != DI_NODE_NIL) {
+	di_fini(rnode);
+    }
+
     return DI_WALK_CONTINUE;
 }
 
@@ -763,15 +557,17 @@ pci_device_solx_devfs_probe( struct pci_
     int i;
     int len = 0;
     uint ent = 0;
+    struct pci_device_private *priv =
+	(struct pci_device_private *) dev;
     nexus_t *nexus;
 
-#ifdef __sparc
-    if ( (nexus = find_nexus_for_dev(dev)) == NULL )
-#else
     if ( (nexus = find_nexus_for_bus(dev->domain, dev->bus)) == NULL )
-#endif
 	return ENODEV;
 
+    pci_device_cfg_read_u8(dev, &priv->header_type, PCI_CONF_HEADER);
+
+    pci_device_cfg_read_u8(dev, (uint8_t *)&dev->irq, PCI_CONF_ILINE);
+
     /*
      * starting to find if it is MEM/MEM64/IO
      * using libdevinfo
@@ -788,10 +584,13 @@ pci_device_solx_devfs_probe( struct pci_
     }
 
     if (args.node != DI_NODE_NIL) {
+	int *prop;
 #ifdef __sparc
 	di_minor_t minor;
 #endif
 
+	priv->is_primary = 0;
+
 #ifdef __sparc
 	if (minor = di_minor_next(args.node, DI_MINOR_NIL))
 	    MAPPING_DEV_PATH(dev) = di_devfs_minor_path (minor);
@@ -799,6 +598,12 @@ pci_device_solx_devfs_probe( struct pci_
 	    MAPPING_DEV_PATH(dev) = NULL;
 #endif
 
+	if (di_prop_lookup_ints(DDI_DEV_T_ANY, args.node,
+				"primary-controller", &prop) >= 1) {
+	    if (prop[0])
+		priv->is_primary = 1;
+	}
+
 	/*
 	 * It will succeed for sure, because it was
 	 * successfully called in find_target_node
@@ -818,83 +623,69 @@ pci_device_solx_devfs_probe( struct pci_
     if (len <= 0)
 	goto cleanup;
 
-
     /*
-     * how to find the size of rom???
-     * if the device has expansion rom,
-     * it must be listed in the last
-     * cells because solaris find probe
-     * the base address from offset 0x10
-     * to 0x30h. So only check the last
-     * item.
-     */
-    reg = (pci_regspec_t *)&regbuf[len - CELL_NUMS_1275];
-    if (PCI_REG_REG_G(reg->pci_phys_hi) == PCI_CONF_ROM) {
-	/*
-	 * rom can only be 32 bits
-	 */
-	dev->rom_size = reg->pci_size_low;
-	len = len - CELL_NUMS_1275;
-    }
-    else {
-	/*
-	 * size default to 64K and base address
-	 * default to 0xC0000
-	 */
-	dev->rom_size = 0x10000;
-    }
-
-    /*
-     * Solaris has its own BAR index.
+     * Each BAR address get its own region slot in sequence.
+     * 32 bit BAR:
+     * BAR 0x10 -> slot0, BAR 0x14 -> slot1...
+     * 64 bit BAR:
+     * BAR 0x10 -> slot0, BAR 0x18 -> slot2...,
+     * slot1 is part of BAR 0x10
      * Linux give two region slot for 64 bit address.
      */
     for (i = 0; i < len; i = i + CELL_NUMS_1275) {
 
 	reg = (pci_regspec_t *)&regbuf[i];
 	ent = reg->pci_phys_hi & 0xff;
-	/*
-	 * G35 broken in BAR0
-	 */
-	ent = (ent - PCI_CONF_BASE0) >> 2;
-	if (ent >= 6) {
+
+	if (ent > PCI_CONF_ROM) {
 	    fprintf(stderr, "error ent = %d\n", ent);
 	    break;
 	}
-
 	/*
-	 * non relocatable resource is excluded
-	 * such like 0xa0000, 0x3b0. If it is met,
-	 * the loop is broken;
+	 * G35 broken in BAR0
 	 */
-	if (!PCI_REG_REG_G(reg->pci_phys_hi))
+	if (ent < PCI_CONF_BASE0) {
+	    /*
+	     * VGA resource here and ignore it
+	     */
 	    break;
+	} else if (ent == PCI_CONF_ROM) {
+	    priv->rom_base = reg->pci_phys_low |
+		((uint64_t)reg->pci_phys_mid << 32);
+	    dev->rom_size = reg->pci_size_low;
+	} else {
+	    ent = (ent - PCI_CONF_BASE0) >> 2;
+	    /*
+	     * non relocatable resource is excluded
+	     * such like 0xa0000, 0x3b0. If it is met,
+	     * the loop is broken;
+	     */
+	    if (!PCI_REG_REG_G(reg->pci_phys_hi))
+		break;
 
-	if (reg->pci_phys_hi & PCI_PREFETCH_B) {
-	    dev->regions[ent].is_prefetchable = 1;
-	}
+	    if (reg->pci_phys_hi & PCI_PREFETCH_B) {
+		dev->regions[ent].is_prefetchable = 1;
+	    }
 
 
-	/*
-	 * We split the shift count 32 into two 16 to
-	 * avoid the complaining of the compiler
-	 */
-	dev->regions[ent].base_addr = reg->pci_phys_low +
-	    ((reg->pci_phys_mid << 16) << 16);
-	dev->regions[ent].size = reg->pci_size_low +
-	    ((reg->pci_size_hi << 16) << 16);
-
-	switch (reg->pci_phys_hi & PCI_REG_ADDR_M) {
-	    case PCI_ADDR_IO:
-		dev->regions[ent].is_IO = 1;
-		break;
-	    case PCI_ADDR_MEM32:
-		break;
-	    case PCI_ADDR_MEM64:
-		dev->regions[ent].is_64 = 1;
-		/*
-		 * Skip one slot for 64 bit address
-		 */
-		break;
+	    dev->regions[ent].base_addr = reg->pci_phys_low |
+		((uint64_t)reg->pci_phys_mid << 32);
+	    dev->regions[ent].size = reg->pci_size_low |
+		((uint64_t)reg->pci_size_hi << 32);
+
+	    switch (reg->pci_phys_hi & PCI_REG_ADDR_M) {
+		case PCI_ADDR_IO:
+		    dev->regions[ent].is_IO = 1;
+		    break;
+		case PCI_ADDR_MEM32:
+		    break;
+		case PCI_ADDR_MEM64:
+		    dev->regions[ent].is_64 = 1;
+		    /*
+		     * Skip one slot for 64 bit address
+		     */
+		    break;
+	    }
 	}
     }
 
@@ -906,7 +697,7 @@ pci_device_solx_devfs_probe( struct pci_
 }
 
 /**
- * Map a memory region for a device using /dev/xsvc.
+ * Map a memory region for a device using /dev/xsvc (x86) or fb device (sparc)
  *
  * \param dev   Device whose memory region is to be mapped.
  * \param map   Parameters of the mapping that is to be created.
@@ -922,44 +713,45 @@ pci_device_solx_devfs_map_range(struct p
 			? (PROT_READ | PROT_WRITE) : PROT_READ;
     int err = 0;
 
-#ifdef __sparc
-    char	map_dev[128];
+    const char *map_dev;
     int		map_fd;
 
-    if (MAPPING_DEV_PATH(dev))
-	snprintf(map_dev, sizeof (map_dev), "%s%s", "/devices", MAPPING_DEV_PATH(dev));
-    else
-	strcpy (map_dev, "/dev/fb0");
+#ifdef __sparc
+    char	map_dev_buf[128];
 
-    if ((map_fd = open(map_dev, O_RDWR | O_CLOEXEC)) < 0) {
-	err = errno;
-	(void) fprintf(stderr, "can not open %s: %s\n", map_dev,
-			   strerror(errno));
-	return err;
+    if (MAPPING_DEV_PATH(dev)) {
+	snprintf(map_dev_buf, sizeof (map_dev_buf), "%s%s",
+		 "/devices", MAPPING_DEV_PATH(dev));
+	map_dev = map_dev_buf;
     }
+    else
+	map_dev = "/dev/fb0";
 
-    map->memory = mmap(NULL, map->size, prot, MAP_SHARED, map_fd, map->base);
+    map_fd = -1;
 #else
     /*
-     * Still used xsvc to do the user space mapping
+     * Still uses xsvc to do the user space mapping on x86/x64,
+     * caches open fd across multiple calls.
      */
-    if (xsvc_fd < 0) {
-	if ((xsvc_fd = open("/dev/xsvc", O_RDWR | O_CLOEXEC)) < 0) {
+    map_dev = "/dev/xsvc";
+    map_fd = xsvc_fd;
+#endif
+
+    if (map_fd < 0) {
+	if ((map_fd = open(map_dev, O_RDWR | O_CLOEXEC)) < 0) {
 	    err = errno;
-	    (void) fprintf(stderr, "can not open /dev/xsvc: %s\n",
+	    (void) fprintf(stderr, "can not open %s: %s\n", map_dev,
 			   strerror(errno));
 	    return err;
 	}
     }
 
-    map->memory = mmap(NULL, map->size, prot, MAP_SHARED, xsvc_fd, map->base);
-#endif
-
+    map->memory = mmap(NULL, map->size, prot, MAP_SHARED, map_fd, map->base);
     if (map->memory == MAP_FAILED) {
 	err = errno;
 
 	(void) fprintf(stderr, "map rom region =%llx failed: %s\n",
-		       map->base, strerror(errno));
+		       (unsigned long long) map->base, strerror(errno));
     }
 
 #ifdef __sparc
@@ -978,15 +770,22 @@ pci_device_solx_devfs_read_rom( struct p
     int err;
     struct pci_device_mapping prom = {
 	.base = 0xC0000,
-	.size = dev->rom_size,
+	.size = 0x10000,
 	.flags = 0
     };
+    struct pci_device_private *priv =
+	(struct pci_device_private *) dev;
+
+    if (priv->rom_base) {
+	prom.base = priv->rom_base;
+	prom.size = dev->rom_size;
+    }
 
     err = pci_device_solx_devfs_map_range(dev, &prom);
     if (err == 0) {
 	(void) bcopy(prom.memory, buffer, dev->rom_size);
 
-	if (munmap(prom.memory, dev->rom_size) == -1) {
+	if (munmap(prom.memory, prom.size) == -1) {
 	    err = errno;
 	}
     }
@@ -1006,11 +805,7 @@ pci_device_solx_devfs_read( struct pci_d
     int i = 0;
     nexus_t *nexus;
 
-#ifdef __sparc
-    nexus = find_nexus_for_dev(dev);
-#else
     nexus = find_nexus_for_bus(dev->domain, dev->bus);
-#endif
 
     *bytes_read = 0;
 
@@ -1036,7 +831,7 @@ pci_device_solx_devfs_read( struct pci_d
 		    cfg_prg.bus_no,
 		    cfg_prg.dev_no,
 		    cfg_prg.func_no,
-		    cfg_prg.offset);
+		    (unsigned long long) cfg_prg.offset);
 	    fprintf(stderr, "Failure cause = %x\n", err);
 	    break;
 	}
@@ -1064,11 +859,7 @@ pci_device_solx_devfs_write( struct pci_
     int cmd;
     nexus_t *nexus;
 
-#ifdef __sparc
-    nexus = find_nexus_for_dev(dev);
-#else
     nexus = find_nexus_for_bus(dev->domain, dev->bus);
-#endif
 
     if ( bytes_written != NULL ) {
 	*bytes_written = 0;
@@ -1122,11 +913,142 @@ pci_device_solx_devfs_write( struct pci_
     return (err);
 }
 
+static int pci_device_solx_devfs_boot_vga(struct pci_device *dev)
+{
+    struct pci_device_private *priv =
+	(struct pci_device_private *) dev;
+
+    return (priv->is_primary);
+
+}
+
+static struct pci_io_handle *
+pci_device_solx_devfs_open_legacy_io(struct pci_io_handle *ret,
+				     struct pci_device *dev,
+				     pciaddr_t base, pciaddr_t size)
+{
+#ifdef __x86
+    if (sysi86(SI86V86, V86SC_IOPL, PS_IOPL) == 0) {
+	ret->base = base;
+	ret->size = size;
+	return ret;
+    }
+#endif
+    return NULL;
+}
+
+static uint32_t
+pci_device_solx_devfs_read32(struct pci_io_handle *handle, uint32_t reg)
+{
+#ifdef __x86
+    uint16_t port = (uint16_t) (handle->base + reg);
+    uint32_t ret;
+    __asm__ __volatile__("inl %1,%0":"=a"(ret):"d"(port));
+    return ret;
+#else
+    return *(uint32_t *)((uintptr_t)handle->memory + reg);
+#endif
+}
+
+static uint16_t
+pci_device_solx_devfs_read16(struct pci_io_handle *handle, uint32_t reg)
+{
+#ifdef __x86
+    uint16_t port = (uint16_t) (handle->base + reg);
+    uint16_t ret;
+    __asm__ __volatile__("inw %1,%0":"=a"(ret):"d"(port));
+    return ret;
+#else
+    return *(uint16_t *)((uintptr_t)handle->memory + reg);
+#endif
+}
+
+static uint8_t
+pci_device_solx_devfs_read8(struct pci_io_handle *handle, uint32_t reg)
+{
+#ifdef __x86
+    uint16_t port = (uint16_t) (handle->base + reg);
+    uint8_t ret;
+    __asm__ __volatile__("inb %1,%0":"=a"(ret):"d"(port));
+    return ret;
+#else
+    return *(uint8_t *)((uintptr_t)handle->memory + reg);
+#endif
+}
+
+static void
+pci_device_solx_devfs_write32(struct pci_io_handle *handle, uint32_t reg,
+    uint32_t data)
+{
+#ifdef __x86
+      uint16_t port = (uint16_t) (handle->base + reg);
+      __asm__ __volatile__("outl %0,%1"::"a"(data), "d"(port));
+#else
+      *(uint16_t *)((uintptr_t)handle->memory + reg) = data;
+#endif
+}
+
+static void
+pci_device_solx_devfs_write16(struct pci_io_handle *handle, uint32_t reg,
+    uint16_t data)
+{
+#ifdef __x86
+      uint16_t port = (uint16_t) (handle->base + reg);
+      __asm__ __volatile__("outw %0,%1"::"a"(data), "d"(port));
+#else
+    *(uint8_t *)((uintptr_t)handle->memory + reg) = data;
+#endif
+}
 
+static void
+pci_device_solx_devfs_write8(struct pci_io_handle *handle, uint32_t reg,
+    uint8_t data)
+{
+#ifdef __x86
+      uint16_t port = (uint16_t) (handle->base + reg);
+      __asm__ __volatile__("outb %0,%1"::"a"(data), "d"(port));
+#else
+      *(uint32_t *)((uintptr_t)handle->memory + reg) = data;
+#endif
+}
+
+static int
+pci_device_solx_devfs_map_legacy(struct pci_device *dev, pciaddr_t base,
+				 pciaddr_t size, unsigned map_flags,
+				 void **addr)
+{
+    int err;
+    struct pci_device_mapping map = {
+	.base = base,
+	.size = size,
+	.flags = map_flags,
+    };
+
+    err = pci_device_solx_devfs_map_range(dev, &map);
+    if (err == 0)
+	*addr = map.memory;
+    return err;
+}
+
+static int
+pci_device_solx_devfs_unmap_legacy(struct pci_device *dev,
+				   void *addr, pciaddr_t size)
+{
+    struct pci_device_mapping map = {
+	.memory = addr,
+	.size = size,
+    };
+
+    return pci_device_generic_unmap_range(dev, &map);
+}
 
 static const struct pci_system_methods solx_devfs_methods = {
     .destroy = pci_system_solx_devfs_destroy,
+#ifdef __sparc
+    .destroy_device = pci_system_solx_devfs_destroy_device,
+#else
     .destroy_device = NULL,
+#endif
     .read_rom = pci_device_solx_devfs_read_rom,
     .probe = pci_device_solx_devfs_probe,
     .map_range = pci_device_solx_devfs_map_range,
@@ -1135,7 +1057,18 @@ static const struct pci_system_methods s
     .read = pci_device_solx_devfs_read,
     .write = pci_device_solx_devfs_write,
 
-    .fill_capabilities = pci_fill_capabilities_generic
+    .fill_capabilities = pci_fill_capabilities_generic,
+    .boot_vga = pci_device_solx_devfs_boot_vga,
+
+    .open_legacy_io = pci_device_solx_devfs_open_legacy_io,
+    .read32 = pci_device_solx_devfs_read32,
+    .read16 = pci_device_solx_devfs_read16,
+    .read8 = pci_device_solx_devfs_read8,
+    .write32 = pci_device_solx_devfs_write32,
+    .write16 = pci_device_solx_devfs_write16,
+    .write8 = pci_device_solx_devfs_write8,
+    .map_legacy = pci_device_solx_devfs_map_legacy,
+    .unmap_legacy = pci_device_solx_devfs_unmap_legacy,
 };
 
 /*
@@ -1176,6 +1109,9 @@ pci_system_solx_devfs_create( void )
     pinfo.num_allocated_elems = INITIAL_NUM_DEVICES;
     pinfo.num_devices = 0;
     pinfo.devices = devices;
+#ifdef __sparc
+    nexus_count = 0;
+#endif
     (void) di_walk_minor(di_node, DDI_NT_REGACC, 0, &pinfo, probe_nexus_node);
 
     di_fini(di_node);
