# $NetBSD: Makefile,v 1.8 2000/04/24 14:52:33 hubertf Exp $
#

DISTNAME=		xwave2
PKGNAME=		xwave-2.0
CATEGORIES=		audio x11
MASTER_SITES=		http://www.funet.fi/~kouhia/

MAINTAINER=		hubertf@netbsd.org

DEPENDS+=		xpm-3.*:../../graphics/xpm

USE_IMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xwave ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/XWave ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xwave2
	${INSTALL_DATA} ${WRKSRC}/README \
			${WRKSRC}/README-XWAVE2 \
			${WRKSRC}/README.v06 \
			${WRKSRC}/COPYING \
			${WRKSRC}/INSTALL \
			${PREFIX}/share/doc/xwave2

.include "../../mk/bsd.pkg.mk"
