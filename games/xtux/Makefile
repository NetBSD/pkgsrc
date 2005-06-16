# $NetBSD: Makefile,v 1.17 2005/06/16 06:57:56 jlam Exp $

DISTNAME=	xtux-arena-src-nov-15
PKGNAME=	xtux-0.2000.11.15
CATEGORIES=	games
MASTER_SITES=	http://www.adelaide.net.au/~philaw/ \
		${MASTER_SITE_SOURCEFORGE:=xtux/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xtux.sourceforge.net/
COMMENT=	2D multi-player shootout using images from the Open Software scene

WRKSRC=		${WRKDIR}/xtux

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xtux
	cd ${WRKSRC} && ${PAX} -rw data ${PREFIX}/share/xtux
	cd ${WRKSRC} && ${PAX} -rw doc ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/example-config ${PREFIX}/share/xtux
	${INSTALL_PROGRAM} ${WRKSRC}/tux_serv ${PREFIX}/bin/tux_serv
	${INSTALL_PROGRAM} ${WRKSRC}/xtux ${PREFIX}/bin/xtux

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
