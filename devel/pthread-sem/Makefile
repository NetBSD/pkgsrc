# $NetBSD: Makefile,v 1.10 2013/12/23 11:57:03 wiz Exp $

DISTNAME=	pthread-sem-1.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.cit.gu.edu.au/teaching/2105CIT/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Semaphore implementation for (PTH) pthreads

CONFLICTS=		man-pages-[0-9]*

PTHREAD_OPTS+=	require
USE_LIBTOOL=	yes
USE_FEATURES+=	cdefs

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
