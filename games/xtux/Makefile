# $NetBSD: Makefile,v 1.11 2004/01/24 13:30:57 grant Exp $

DISTNAME=	xtux-arena-src-nov-15
PKGNAME=	xtux-0.2000.11.15
CATEGORIES=	games
MASTER_SITES=	http://www.adelaide.net.au/~philaw/ \
		${MASTER_SITE_SOURCEFORGE:=xtux/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://xtux.sourceforge.net/
COMMENT=	2D multi-player shootout using images from the Open Software scene

WRKSRC=		${WRKDIR}/xtux
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

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

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
