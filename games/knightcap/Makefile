# $NetBSD: Makefile,v 1.5 2002/06/28 14:54:18 agc Exp $

DISTNAME=		KnightCap-3.6
PKGNAME=		knightcap-3.6
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://anu.samba.org/KnightCap/
COMMENT=		chess engine with 3D OpenGL-rendered chessboard

WRKSRC=			${WRKDIR}/Export
ALL_TARGET=		KnightCap

USE_BUILDLINK_ONLY=	yes

MAKE_ENV+=		MESA=${BUILDLINK_PREFIX.MesaLib}
MAKE_ENV+=		DEFINES="${DEFINES}"

DEFINES=		-DTB_DIR=\\\"${TBDIR}\\\"

TBDIR=			${PREFIX}/share/egtb
DOCDIR=			${PREFIX}/share/doc/knightcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../graphics/Mesa/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
