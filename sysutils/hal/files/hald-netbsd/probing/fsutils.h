/***************************************************************************
 *
 * fsutils.h : definitions for filesystem utilities
 *
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifndef FSUTILS_H
#define FSUTILS_H

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

bool dos_to_dev(char *path, char **devpath, int *num);
char *get_slice_name (char *devlink);
bool is_dos_drive(u_char id);
bool is_dos_extended(u_char id);
bool find_dos_drive(int fd, int num, int *relsect, int *numsect, int *systid);

#endif /* FSUTILS_H */
