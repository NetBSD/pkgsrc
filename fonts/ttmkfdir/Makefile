# $NetBSD: Makefile,v 1.9 2004/10/03 00:14:42 tv Exp $
#

DISTNAME=	ttmkfdir
PKGNAME=	ttmkfdir-0
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.joerg-pommnitz.de/TrueType/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.joerg-pommnitz.de/TrueType/xfsft.html
COMMENT=	Tool that creates a fonts.scale file

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
