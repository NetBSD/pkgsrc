# $NetBSD: Makefile,v 1.6 2010/02/11 20:53:21 joerg Exp $
#

DISTNAME=	identd
PKGNAME=	fair-${DISTNAME}-20000201
CATEGORIES=	net security
MASTER_SITES=	http://www.clock.org/~fair/opinion/
EXTRACT_SUFX=	.c

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.clock.org/~fair/opinion/identd.html
COMMENT=	Fast RFC-1413 identd running under inetd that returns no useful info

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	libexec

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-build:
	cd ${WRKSRC} &&							\
	${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
