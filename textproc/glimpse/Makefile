# $NetBSD: Makefile,v 1.32 2007/02/22 19:27:13 wiz Exp $

DISTNAME=	glimpse-4.18.0
PKGREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://webglimpse.net/trial/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webglimpse.net/
COMMENT=	Text search engine

LICENSE=	glimpse-license
RESTRICTED=	Restrictive copyright (don't sell for profit)
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	yes
MAKE_FLAGS=	mandir=${PREFIX}/${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse

.include "../../mk/bsd.pkg.mk"
