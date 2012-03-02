# $NetBSD: Makefile,v 1.7 2012/03/02 16:39:50 hans Exp $
#

DISTNAME=	pthread-sem-1.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.cit.gu.edu.au/teaching/2105CIT/software/

MAINTAINER=	rh@NetBSD.org
COMMENT=	Semaphore implementation for (PTH) pthreads

PKG_DESTDIR_SUPPORT=	user-destdir

PTHREAD_OPTS+=	require
USE_LIBTOOL=	yes
USE_FEATURES+=	cdefs

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
