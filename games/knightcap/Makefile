# $NetBSD: Makefile,v 1.8 2003/03/29 12:41:05 jmmv Exp $

DISTNAME=		KnightCap-3.6
PKGNAME=		knightcap-3.6
PKGREVISION=		2
WRKSRC=			${WRKDIR}/Export
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://anu.samba.org/KnightCap/
COMMENT=		chess engine with 3D OpenGL-rendered chessboard

ALL_TARGET=		KnightCap

USE_BUILDLINK2=		# defined
USE_X11=		# defined

MAKE_ENV+=		MESA=${BUILDLINK_PREFIX.MesaLib}
MAKE_ENV+=		DEFINES="${DEFINES}"

DEFINES=		-DTB_DIR=\\\"${TBDIR}\\\"

TBDIR=			${PREFIX}/share/egtb
DOCDIR=			${PREFIX}/share/doc/knightcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
