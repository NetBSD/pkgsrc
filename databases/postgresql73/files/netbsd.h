/*-------------------------------------------------------------------------
 *
 * netbsd.h
 *	  port-specific prototypes for NetBSD
 *
 *
 * Portions Copyright (c) 1996-2003, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $Id: netbsd.h,v 1.1 2004/10/10 17:27:43 jdolecek Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef PORT_PROTOS_H
#define PORT_PROTOS_H

#include <sys/types.h>
#include <nlist.h>
#include <link.h>
#include <dlfcn.h>

#include "utils/dynamic_loader.h"

#ifdef HAVE_DLOPEN
/*
 * In some older systems, the RTLD_NOW flag isn't defined and the mode
 * argument to dlopen must always be 1.  The RTLD_GLOBAL flag is wanted
 * if available, but it doesn't exist everywhere.
 * If it doesn't exist, set it to 0 so it has no effect.
 */
#ifndef RTLD_NOW
#define RTLD_NOW 1
#endif
#ifndef RTLD_GLOBAL
#define RTLD_GLOBAL 0
#endif

#define	   pg_dlopen(f)    dlopen((f), RTLD_NOW | RTLD_GLOBAL)
#define	   pg_dlsym		   dlsym
#define	   pg_dlclose	   dlclose
#define	   pg_dlerror	   dlerror

#endif /* HAVE_DLOPEN */

#endif   /* PORT_PROTOS_H */
