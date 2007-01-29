/* $Id: mem_dragonfly.c,v 1.1 2007/01/29 16:42:52 joerg Exp $ */

/*
 * mem_dragonfly.c - module to get memory/swap usages in percent, for DragonFly
 *
 * Copyright(c) 2007 Joerg Sonnenenberger <joerg@leaf.dragonflybsd.org>
 *
 * licensed under the GPL
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "mem.h"

#include <kinfo.h>
#include <sys/vmmeter.h>

/* initialize function */
void mem_init(void)
{
}

void mem_getusage(int *per_mem, int *per_swap, const struct mem_options *opts)
{
    struct vmstats vms;
    int vms_size = sizeof(vms);
    unsigned long mused;

    if (sysctlbyname("vm.vmstats", &vms, &vms_size, NULL, 0))
	exit(1);

    mused = vms.v_active_count - vms.v_free_count;
    if (opts->ignore_wired)
	mused -= vms.v_wire_count;
    if (opts->ignore_cached)
	mused -= vms.v_cache_count;

    *per_mem = 100 * mused / vms.v_page_count;
    *per_swap = 0; /* XXX Fill me in */
}
