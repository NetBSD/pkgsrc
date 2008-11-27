/***************************************************************************
 *
 * drvctl.h : definitions for NetBSD drvctl events
 *
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifndef DRVCTL_H
#define DRVCTL_H

#include <glib.h>
#include <sys/drvctlio.h>

gboolean drvctl_init(void);
void drvctl_fini(void);
int drvctl_list(const gchar *devnode, struct devlistargs *laa);
gboolean drvctl_find_parent(const gchar *devnode, char *parent);
gboolean drvctl_find_device(const gchar *devnode, prop_dictionary_t *properties);

#endif /* DRVCTL_H */
