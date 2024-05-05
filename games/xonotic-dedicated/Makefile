# $NetBSD: Makefile,v 1.1 2024/05/05 09:31:37 nia Exp $

.include "../../games/xonotic/Makefile.common"

PKGNAME=	${DISTNAME:S/xonotic-/xonotic-dedicated-/1}

CONFLICTS+=	xonotic-[0-9]*

COMMENT=	Fast arena-style FPS (dedicated server)

BUILD_TARGET=	server

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/xonotic/data
INSTALLATION_DIRS+=	share/xonotic

CHECK_WRKREF_SKIP+=	share/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/darkplaces/darkplaces-dedicated \
	    ${DESTDIR}${PREFIX}/bin/xonotic-dedicated
	${INSTALL_DATA} ${WRKSRC}/key_0.d0pk \
	    ${DESTDIR}${PREFIX}/share/xonotic
	${INSTALL_DATA} ${WRKSRC}/data/*.pk3 \
	    ${DESTDIR}${PREFIX}/share/xonotic/data

.include "../../mk/bsd.pkg.mk"
