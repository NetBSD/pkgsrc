/*	$NetBSD: sha1.h,v 1.3 2007/07/31 13:17:34 joerg Exp $	*/

/*
 * SHA-1 in C
 * By Steve Reid <steve@edmweb.com>
 * 100% Public Domain
 */

#ifndef _NBCOMPAT_SYS_SHA1_H_
#define	_NBCOMPAT_SYS_SHA1_H_

typedef struct {
	u_int32_t state[5];
	u_int32_t count[2];  
	unsigned char buffer[64];
} SHA1_CTX;
  
void	SHA1Transform __P((u_int32_t state[5], const unsigned char buffer[64]));
void	SHA1Init __P((SHA1_CTX *context));
void	SHA1Update __P((SHA1_CTX *context, const unsigned char *data, unsigned int len));
void	SHA1Final __P((unsigned char digest[20], SHA1_CTX *context));
#ifndef _KERNEL
char	*SHA1End __P((SHA1_CTX *, char *));
char	*SHA1File __P((char *, char *));
char	*SHA1Data __P((const unsigned char *, size_t, char *));
#endif /* _KERNEL */

#endif /* _NBCOMPAT_SYS_SHA1_H_ */
