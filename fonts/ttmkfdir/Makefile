# $NetBSD: Makefile,v 1.6 2003/07/21 16:47:10 martti Exp $
#

DISTNAME=	ttmkfdir
PKGNAME=	ttmkfdir-0
WRKSRC=		${WRKDIR}
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.joerg-pommnitz.de/TrueType/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.joerg-pommnitz.de/TrueType/xfsft.html
COMMENT=	Tool that creates a fonts.scale file

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
