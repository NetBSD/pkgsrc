/*	$NetBSD: sha1.h,v 1.8 2010/01/23 13:25:12 obache Exp $	*/

/*
 * SHA-1 in C
 * By Steve Reid <steve@edmweb.com>
 * 100% Public Domain
 */

#ifndef _SYS_SHA1_H_
#define	_SYS_SHA1_H_

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

typedef struct {
	uint32_t state[5];
	uint32_t count[2];  
	uint8_t buffer[64];
} SHA1_CTX;
  
void	SHA1Transform(uint32_t state[5], const uint8_t buffer[64]);
void	SHA1Init(SHA1_CTX *context);
void	SHA1Update(SHA1_CTX *context, const uint8_t *data, size_t len);
void	SHA1Final(uint8_t digest[20], SHA1_CTX *context);
#ifndef _KERNEL
char	*SHA1End(SHA1_CTX *, char *);
char	*SHA1File(char *, char *);
char	*SHA1Data(const uint8_t *, size_t, char *);
#endif /* _KERNEL */

#endif /* _SYS_SHA1_H_ */
