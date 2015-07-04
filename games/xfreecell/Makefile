# $NetBSD: Makefile,v 1.19 2015/07/04 16:18:35 joerg Exp $

DISTNAME=	xfreecell-1.0.5b
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www2.giganet.net/~nakayama/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www2.giganet.net/~nakayama/
COMMENT=	Popular freecell card game for X

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

WRKSRC=		${WRKDIR}/xfreecell
NO_CONFIGURE=	YES

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
