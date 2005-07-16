# $NetBSD: Makefile,v 1.11 2005/07/16 19:10:39 jlam Exp $
#

DISTNAME=		netmaj-2.0.7
CATEGORIES=		games
MASTER_SITES=		http://www.sfc.wide.ad.jp/~kusune/netmaj/files/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.sfc.wide.ad.jp/~kusune/netmaj/
COMMENT=		Mahjongg game with network and 1-4 player(s) support

WRKSRC=			${WRKDIR}/netmaj
USE_TOOLS+=		perl:run

INSTALL_TARGET=		install install-pf
HTMLDIR=		${PREFIX}/share/doc/html/netmaj

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} libs
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
