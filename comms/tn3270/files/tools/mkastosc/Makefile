#	$NetBSD: Makefile,v 1.1.1.1 2010/01/17 01:33:25 dholland Exp $
#	From NetBSD: Makefile,v 1.10 2002/09/15 01:27:46 thorpej Exp 

HOSTPROG=	mkastosc
HOST_CPPFLAGS+=	-DHOST_TOOL
SRCS=	mkastosc.c dohits.c asc_ebc.c ebc_disp.c

HOST_CPPFLAGS+=-I${.CURDIR}/../mkhits
.PATH: ${.CURDIR}/../mkhits

.include <bsd.hostprog.mk>

