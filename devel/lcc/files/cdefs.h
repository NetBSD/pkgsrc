/* $NetBSD: cdefs.h,v 1.1.1.1 2001/07/21 02:51:35 gmcgarry Exp $ */

/*
 *  cdefs.h compatibility file to compile NetBSD with lcc 4.1
 */

#ifndef _SYS_CDEFS_H_
#define _SYS_CDEFS_H_

#define	__asm__(x)
#define __attribute__(x)

/*
 *  The rest of this is based on:
 *
 *  NetBSD: cdefs.h,v 1.36 2000/05/27 12:22:24 kleink Exp
 */

#include <machine/cdefs.h>
#ifdef __ELF__
#include <sys/cdefs_elf.h>
#else
#include <sys/cdefs_aout.h>
#endif

#define __BEGIN_DECLS
#define __END_DECLS

#define ___STRING(x)    __STRING(x)
#define ___CONCAT(x,y)  __CONCAT(x,y)

#define __P(protos)     protos          /* full-blown ANSI C */
#define __CONCAT(x,y)   x ## y
#define __STRING(x)     #x

#define __const         const           /* define reserved names to standard */
#define __signed        signed
#define __volatile      volatile

#define __inline                        /* delete GCC keyword */

#define __kprintf_attribute__(a)
#define __extension__           /* delete __extension__ if non-gcc or gcc1 */

#define __dead
#define __pure

#define __RENAME(x)
#define __GNUC_PREREQ__(x, y)   0

#ifdef __AUDIT__
#define __aconst        __const
#else
#define __aconst
#endif

#if defined(_KERNEL)
#if defined(NO_KERNEL_RCSIDS)
#undef __KERNEL_RCSID
#define __KERNEL_RCSID(_n, _s)          /* nothing */
#endif /* NO_KERNEL_RCSIDS */
#endif /* _KERNEL */

#endif
