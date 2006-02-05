# $NetBSD: Makefile,v 1.27 2006/02/05 23:11:02 joerg Exp $

DISTNAME=	glimpse-4.18.0
PKGREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=   http://webglimpse.net/trial/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://webglimpse.net/
COMMENT=	Text search engine

LICENSE=	glimpse-license
RESTRICTED=	"Restrictive copyright (don't sell for profit)"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse

.include "../../mk/bsd.pkg.mk"
