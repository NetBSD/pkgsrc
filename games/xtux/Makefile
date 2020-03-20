# $NetBSD: Makefile,v 1.27 2020/03/20 11:57:45 nia Exp $

DISTNAME=	xtux-arena-src-nov-15
PKGNAME=	xtux-0.2000.11.15
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xtux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xtux.sourceforge.net/
COMMENT=	2D multi-player shootout using images from the Open Software scene

#--- server ---
#clang: error: no such file or directory: '../../src/common/xtuxlib.a'
MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/xtux

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xtux
	cd ${WRKSRC} && pax -rw data ${DESTDIR}${PREFIX}/share/xtux
	cd ${WRKSRC} && pax -rw doc ${DESTDIR}${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DESTDIR}${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/xtux
	${INSTALL_DATA} ${WRKSRC}/example-config ${DESTDIR}${PREFIX}/share/xtux
	${INSTALL_PROGRAM} ${WRKSRC}/tux_serv ${DESTDIR}${PREFIX}/bin/tux_serv
	${INSTALL_PROGRAM} ${WRKSRC}/xtux ${DESTDIR}${PREFIX}/bin/xtux

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
