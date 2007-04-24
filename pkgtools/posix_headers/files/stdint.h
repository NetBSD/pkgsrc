/* $NetBSD: stdint.h,v 1.1.1.1 2007/04/24 19:35:46 tnn Exp $ */
#ifndef _PKGSRC_STDINT_H_
#define _PKGSRC_STDINT_H_
#ifdef __hpux
#include <inttypes.h>
#ifndef UINT_FAST32_MAX
#define UINT_FAST32_MAX 0xffffffffU
#endif /* UINT_FAST32_MAX */
#else
#error No support for this platform.
#endif /* __hpux */
#endif /* _PKGSRC_STDINT_H_ */
