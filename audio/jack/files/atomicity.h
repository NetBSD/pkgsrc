/* $NetBSD: atomicity.h,v 1.1 2008/07/31 03:58:05 bjs Exp $ */

#ifndef _NETBSD_ATOMICITY_H
#define _NETBSD_ATOMICITY_H       1

#include <sys/atomic.h>

typedef unsigned int  _Atomic_word;

static inline _Atomic_word 
__attribute__ ((__unused__))
__exchange_and_add(volatile _Atomic_word* __mem, int __val)
{
  return atomic_add_int_nv(__mem, __val);
}

static inline void
__attribute__ ((__unused__))
__atomic_add(volatile _Atomic_word* __mem, int __val)
{
  atomic_add_int(__mem, __val);
}

#endif /* atomicity.h */
