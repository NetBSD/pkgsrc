# $NetBSD: Makefile,v 1.3 2001/02/16 15:13:50 wiz Exp $
#

DISTNAME=	7pl225sr
PKGNAME=	7plus-225
WRKSRC=		${WRKDIR}/7plsrc.225
CATEGORIES=	ham
MASTER_SITES=	http://home.t-online.de/home/dg1bbq/
DISTFILES=	7pl225sr.tgz \
		7pl210mg.tgz

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://home.t-online.de/home/dg1bbq/
COMMENT=	uuencode-like file coder for AMPR BBS S&F of binary files

LICENSE=        no-commercial-use

MAKEFILE=	netbsd.mak
USE_GMAKE=	yes

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/7plus && \
		${INSTALL_DATA} ${WRKDIR}/*.txt ${PREFIX}/share/doc/7plus && \
		${INSTALL_DATA} ${WRKDIR}/readme.now ${PREFIX}/share/doc/7plus

.include "../../mk/bsd.pkg.mk"
