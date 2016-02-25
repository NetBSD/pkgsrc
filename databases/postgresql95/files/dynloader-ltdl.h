/* $NetBSD: dynloader-ltdl.h,v 1.1 2016/02/25 21:37:35 tnn Exp $ */

/*
 * dynamic loader based on libltdl
 */
#ifndef PORT_PROTOS_H
#define PORT_PROTOS_H

#include <ltdl.h>
#include "utils/dynamic_loader.h"

#define pg_dlopen(a)		((void *)lt_dlopen(a))
#define pg_dlsym(a,b)		lt_dlsym((lt_dlhandle)(a), (b))
#define pg_dlclose(a)		lt_dlclose((lt_dlhandle)(a))
#define pg_dlerror		lt_dlerror

#endif   /* PORT_PROTOS_H */
