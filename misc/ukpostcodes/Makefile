# $NetBSD: Makefile,v 1.1.1.1 2005/05/26 08:58:43 agc Exp $

DISTNAME=	postcodes
PKGNAME=	postcodes-20040515
CATEGORIES=	misc
MASTER_SITES=	http://www.jibble.org/ukpostcodes/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.jibble.org/
COMMENT=	UK national postcode information

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ukpostcodes
	${INSTALL_DATA} ${WRKSRC}/jibble-postcodes.csv ${PREFIX}/share/ukpostcodes/

.include "../../mk/bsd.pkg.mk"
