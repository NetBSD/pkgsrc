# $NetBSD: Makefile,v 1.16 2002/07/12 19:53:01 mycroft Exp $
# FreeBSD Id: Makefile,v 1.12 1997/07/17 19:29:07 andreas Exp
#

DISTNAME=	glimpse-4.16.2
CATEGORIES=	textproc databases
MASTER_SITES=   http://webglimpse.net/trial/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://webglimpse.net/
COMMENT=	Text search engine

CONFLICT=	openssl-[0-9]*

LICENSE=	glimpse-license
RESTRICTED=	"Restrictive copyright (don't sell for profit)"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse

.include "../../mk/bsd.pkg.mk"
