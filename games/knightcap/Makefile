# $NetBSD: Makefile,v 1.36 2022/08/11 05:08:30 gutteridge Exp $

DISTNAME=		KnightCap-3.6
PKGNAME=		knightcap-3.6
PKGREVISION=		8
CATEGORIES=		games
#MASTER_SITES=		ftp://ftp.samba.org/pub/KnightCap/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://samba.org/KnightCap/
COMMENT=		Chess engine with 3D OpenGL-rendered chessboard

BUILD_TARGET=		KnightCap

WRKSRC=			${WRKDIR}/Export

MAKE_ENV+=		MESA=${BUILDLINK_PREFIX.MesaLib}
MAKE_ENV+=		DEFINES=${DEFINES:Q}

DEFINES=		-DTB_DIR=\"${TBDIR:Q}\"

TBDIR=			${PREFIX}/share/egtb
INSTALLATION_DIRS=	bin share/doc/knightcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/knightcap

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
