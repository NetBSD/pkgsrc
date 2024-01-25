/* Qemu 8+ needs MAP_FIXED_NOREPLACE for linux user-mode emulation.
   They offically do not support systems that are too old (glibc
   version), but we're trying to build the rest, anyway. */
#include <sys/mman.h>
#ifndef MAP_FIXED_NOREPLACE
#error "Your libc is too old."
#endif
