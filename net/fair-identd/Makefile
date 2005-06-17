# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:25 jlam Exp $
#

DISTNAME=	identd
PKGNAME=	fair-${DISTNAME}-20000201
CATEGORIES=	net security
MASTER_SITES=	http://www.clock.org/~fair/opinion/
EXTRACT_SUFX=	.c

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.clock.org/~fair/opinion/identd.html
COMMENT=	Fast RFC-1413 identd running under inetd that returns no useful info

INSTALLATION_DIRS=	libexec

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-build:
	cd ${WRKSRC} &&							\
	${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
