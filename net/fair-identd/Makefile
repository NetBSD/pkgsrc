# $NetBSD: Makefile,v 1.2 2001/02/17 18:18:51 wiz Exp $
#

DISTNAME=	identd
PKGNAME=	fair-${DISTNAME}-20000201
CATEGORIES=	net security
MASTER_SITES=	http://www.clock.org/~fair/opinion/
EXTRACT_SUFX=	.c

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.clock.org/~fair/opinion/identd.html
COMMENT=	fast RFC-1413 identd running under inetd that returns no useful info

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-build:
	cd ${WRKSRC} &&							\
	${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
