# $NetBSD: Makefile,v 1.2 2001/02/16 15:11:05 wiz Exp $
#

DISTNAME=	xtux-arena-src-nov-15
PKGNAME=	xtux-0.2000.11.15
CATEGORIES=	games
MASTER_SITES=	http://www.adelaide.net.au/~philaw/ \
		${MASTER_SITE_SOURCEFORGE:=xtux/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xtux.sourceforge.net/
COMMENT=	2D multi-player shootout using images from the Open Software scene

USE_XPM=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/xtux

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xtux
	cd ${WRKSRC} ; \
	${GTAR} cf - data | ( cd ${PREFIX}/share/xtux ; ${GTAR} vxf - )
	cd ${WRKSRC} ; \
	${GTAR} cf - doc | ( cd ${PREFIX}/share/xtux ; ${GTAR} vxf - )
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/example-config ${PREFIX}/share/xtux
	${INSTALL_PROGRAM} ${WRKSRC}/tux_serv ${PREFIX}/bin/tux_serv
	${INSTALL_PROGRAM} ${WRKSRC}/xtux ${PREFIX}/bin/xtux

.include "../../mk/bsd.pkg.mk"
