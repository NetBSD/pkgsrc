# $NetBSD: Makefile,v 1.2 2002/10/09 23:59:49 wiz Exp $
#

DISTNAME=	ttmkfdir
PKGNAME=	ttmkfdir-0
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.joerg-pommnitz.de/TrueType/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.joerg-pommnitz.de/TrueType/xfsft.html
COMMENT=	tool that creates a fonts.scale file

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
