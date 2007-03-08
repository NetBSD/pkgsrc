/* $NetBSD: offsetof.c,v 1.1 2007/03/08 14:31:07 rillig Exp $ */

#include <stddef.h>

#if !defined(offsetof)
"force a syntax error" = 1;
#else
typedef int dummy;
#endif
