# $NetBSD: Makefile,v 1.21 2005/06/16 06:57:54 jlam Exp $

DISTNAME=		KnightCap-3.6
PKGNAME=		knightcap-3.6
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://anu.samba.org/KnightCap/
COMMENT=		Chess engine with 3D OpenGL-rendered chessboard

BUILD_TARGET=		KnightCap

WRKSRC=			${WRKDIR}/Export

MAKE_ENV+=		MESA=${BUILDLINK_PREFIX.MesaLib}
MAKE_ENV+=		DEFINES="${DEFINES}"

DEFINES=		-DTB_DIR=\\\"${TBDIR}\\\"

TBDIR=			${PREFIX}/share/egtb
DOCDIR=			${PREFIX}/share/doc/knightcap
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
