# $NetBSD: Makefile,v 1.22 2004/01/24 15:13:20 grant Exp $
# FreeBSD Id: Makefile,v 1.12 1997/07/17 19:29:07 andreas Exp
#

DISTNAME=	glimpse-4.17.2
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

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse

.include "../../mk/bsd.pkg.mk"
