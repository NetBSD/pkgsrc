# $NetBSD: Makefile,v 1.4 2001/11/29 01:12:33 hubertf Exp $

DISTNAME=		KnightCap-3.6
PKGNAME=		knightcap-3.6
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://anu.samba.org/KnightCap/
COMMENT=		chess engine with 3D OpenGL-rendered chessboard

DEPENDS+=		Mesa-[0-9]*:../../graphics/Mesa

USE_X11=		# defined
NO_CONFIGURE=		# defined

WRKSRC=			${WRKDIR}/Export
ALL_TARGET=		KnightCap

EVAL_PREFIX+=		MESADIR=Mesa
MAKE_ENV+=		MESA=${MESADIR}
MAKE_ENV+=		DEFINES="${DEFINES}"

DEFINES=		-DTB_DIR=\\\"${TBDIR}\\\"

TBDIR=			${PREFIX}/share/egtb
DOCDIR=			${PREFIX}/share/doc/knightcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
