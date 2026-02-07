# $NetBSD: Makefile,v 1.20 2026/02/07 22:47:54 wiz Exp $

DISTNAME=	ascii-3.31
CATEGORIES=	misc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/ascii/
COMMENT=	ASCII character table program
LICENSE=	modified-bsd

USE_TOOLS=		gmake
USE_LIBTOOL=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX}

BUILD_TARGET=		ascii
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
