# $NetBSD: Makefile,v 1.3 2003/03/29 12:40:59 jmmv Exp $
#

DISTNAME=	ttmkfdir
PKGNAME=	ttmkfdir-0
WRKSRC=		${WRKDIR}
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.joerg-pommnitz.de/TrueType/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.joerg-pommnitz.de/TrueType/xfsft.html
COMMENT=	tool that creates a fonts.scale file

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
