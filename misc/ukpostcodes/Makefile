# $NetBSD: Makefile,v 1.3 2006/03/04 21:30:13 jlam Exp $

DISTNAME=	postcodes
PKGNAME=	postcodes-20040515
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.jibble.org/ukpostcodes/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jibble.org/
COMMENT=	UK national postcode information

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ukpostcodes
	${INSTALL_DATA} ${WRKSRC}/jibble-postcodes.csv ${PREFIX}/share/ukpostcodes/

.include "../../mk/bsd.pkg.mk"
