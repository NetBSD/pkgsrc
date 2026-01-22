# $NetBSD: Makefile,v 1.6 2026/01/22 08:45:07 wiz Exp $

DISTNAME=	postcodes
PKGNAME=	postcodes-20040515
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://www.jibble.org/ukpostcodes/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jibble.org/ukpostcodes/
COMMENT=	UK national postcode information

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/ukpostcodes
	${INSTALL_DATA} ${WRKSRC}/jibble-postcodes.csv \
		${DESTDIR}${PREFIX}/share/ukpostcodes/

.include "../../mk/bsd.pkg.mk"
