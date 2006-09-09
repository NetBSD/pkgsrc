# $NetBSD: Makefile,v 1.10 2006/09/09 02:43:09 obache Exp $
#

DISTNAME=	7pl225sr
PKGNAME=	7plus-225
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	http://home.t-online.de/home/dg1bbq/
DISTFILES=	7pl225sr.tgz \
		7pl210mg.tgz

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://home.t-online.de/home/dg1bbq/
COMMENT=	Uuencode-like file coder for AMPR BBS S&F of binary files

LICENSE=        no-commercial-use

WRKSRC=		${WRKDIR}/7plsrc.225
MAKE_FILE=	netbsd.mak
USE_TOOLS+=	gmake

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/7plus && \
		${INSTALL_DATA} ${WRKDIR}/*.txt ${PREFIX}/share/doc/7plus && \
		${INSTALL_DATA} ${WRKDIR}/readme.now ${PREFIX}/share/doc/7plus

.include "../../mk/bsd.pkg.mk"
