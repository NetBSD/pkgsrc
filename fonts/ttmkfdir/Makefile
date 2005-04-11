# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:47 tv Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
