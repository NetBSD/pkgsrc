/*
 * cpu_freebsd.c - module to get cpu usage, for DragonFly
 *
 * Copyright (c) 2007 Joerg Sonnenberger <joerg@leaf.dragonflybsd.org>
 *
 * Licensed under the GPL
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <kinfo.h>
#include "cpu.h"

void
cpu_init(void)
{
}

/* returns current CPU usage in percent */
int
cpu_get_usage(cpu_options *opts)
{
	static uint64_t old_used, old_total;
	uint64_t used, total;
	struct kinfo_cputime cp_time;
	int usage;

	if (kinfo_get_sched_cputime(&cp_time) < 0)
		return 0;
	used = cp_time.cp_user + cp_time.cp_sys;
	if (!opts->ignore_nice)
		used += cp_time.cp_nice;
	total = used + cp_time.cp_idle;
	if (old_total == 0 || total == old_total) 
		usage = 0;
	else
		usage = 100 * (used - old_used + used / 2 - old_used / 2) / (total - old_total);
	old_used = used;
	old_total = total;
	return usage;
}
