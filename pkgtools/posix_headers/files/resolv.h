/* $NetBSD: resolv.h,v 1.1 2007/04/27 13:54:24 tnn Exp $ */
#ifndef _PKGSRC_RESOLV_H_
#define _PKGSRC_RESOLV_H_
#include "@REAL_HEADER@"
#ifdef __hpux
/* Missing prototypes. We have them in libc though. */
ssize_t res_query(char*, int, int, u_char, int);
ssize_t res_search(char*, int, int, u_char, int);
ssize_t res_mkquery(int, const char*, int, int, const char*, int,\
			const char*, char*, int);
ssize_t res_send(const char*, ssize_t, char*, int);
int res_init();
ssize_t dn_comp(const char*, u_char*, ssize_t, u_char**, u_char**);
ssize_t dn_expand(const u_char*, const u_char*, u_char*, int);
#endif /* __hpux */
#endif /* _PKGSRC_RESOLV_H_ */
