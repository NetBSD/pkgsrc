# $NetBSD: Makefile,v 1.7 2004/01/20 12:15:17 agc Exp $
#

DISTNAME=	ttmkfdir
PKGNAME=	ttmkfdir-0
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.joerg-pommnitz.de/TrueType/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.joerg-pommnitz.de/TrueType/xfsft.html
COMMENT=	Tool that creates a fonts.scale file

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
