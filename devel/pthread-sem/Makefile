# $NetBSD: Makefile,v 1.1.1.1 2004/01/20 21:29:10 rh Exp $
#

DISTNAME=	pthread-sem-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.cit.gu.edu.au/teaching/2105CIT/software/

MAINTAINER=	rh@NetBSD.org
COMMENT=	Semaphore implementation for (PTH) pthreads

USE_BUILDLINK3=	yes
PTHREAD_OPTS+=	require

TEST_TARGET=	test

MAKE_ENV+=	LIBDIR=${PREFIX}/lib
MAKE_ENV+=	MANDIR=${PREFIX}/man
MAKE_ENV+=	DESTDIR=/	# trick bsd.lib.mk into adding -R
MAKE_ENV+=	NOPROFILE=1

MANCOMPRESSED_IF_MANZ=	yes

post-install:
	${INSTALL_DATA}	${WRKSRC}/semaphore.h ${PREFIX}/include

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
