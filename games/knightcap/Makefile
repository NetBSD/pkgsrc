# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 08:38:22 jlam Exp $

DISTNAME=		KnightCap-3.6
PKGNAME=		knightcap-3.6nb1
CATEGORIES=		games
MASTER_SITES=		ftp://samba.anu.edu.au/pub/KnightCap/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://anu.samba.org/KnightCap/

DEPENDS+=		Mesa-*:../../graphics/Mesa

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
