# $NetBSD: Makefile,v 1.1.1.1 2000/01/31 11:32:49 wulf Exp $
#

DISTNAME=	7pl223sr
PKGNAME=	7plus-223
WRKSRC=		${WRKDIR}/7plsrc.223
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.ping.net.au/pub/unix/ham/
DISTFILES=	7pl223sr.tgz \
		7pl210mg.tgz

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://home.t-online.de/home/dg1bbq/

LICENSE=        no-commercial-use

MAKEFILE=	netbsd.mak
USE_GMAKE=	yes

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/7plus && \
		${INSTALL_DATA} ${WRKDIR}/*.txt ${PREFIX}/share/doc/7plus && \
		${INSTALL_DATA} ${WRKDIR}/readme.now ${PREFIX}/share/doc/7plus

.include "../../mk/bsd.pkg.mk"
