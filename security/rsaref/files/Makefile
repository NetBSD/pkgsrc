# $NetBSD: Makefile,v 1.3 1998/05/29 19:57:27 tv Exp $

LIB=		rsaref
LIBDIR=		${PREFIX}/lib
CFLAGS=		-O2 -I.
SHLIB_MAJOR=	2
SHLIB_MINOR=	0
NOLINT=		1

SRCS=	desc.c digit.c md2c.c nn.c prime.c rsa.c r_encode.c r_dh.c \
	r_enhanc.c r_keygen.c r_random.c r_stdlib.c

.include <bsd.lib.mk>
