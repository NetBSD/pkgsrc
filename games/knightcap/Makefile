# $NetBSD: Makefile,v 1.14 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		KnightCap-3.6
PKGNAME=		knightcap-3.6
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://anu.samba.org/KnightCap/
COMMENT=		Chess engine with 3D OpenGL-rendered chessboard

ALL_TARGET=		KnightCap

WRKSRC=			${WRKDIR}/Export
USE_BUILDLINK3=		yes
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

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
