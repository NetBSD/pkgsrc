/* $NetBSD: select.h,v 1.1.1.1 2007/04/24 19:35:46 tnn Exp $ */
#ifndef _PKGSRC_SYS_SELECT_H_
#define _PKGSRC_SYS_SELECT_H_
#ifdef __hpux
#include <sys/time.h>
#else
#error This header file only applies to HP-UX.
#endif /* __hpux */
#endif /* _PKGSRC_SYS_SELECT_H_ */
