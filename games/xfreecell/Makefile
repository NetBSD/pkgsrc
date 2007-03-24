# $NetBSD: Makefile,v 1.14 2007/03/24 19:21:24 joerg Exp $

DISTNAME=	xfreecell-1.0.5b
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www2.giganet.net/~nakayama/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@infolaunch.com
HOMEPAGE=	http://www2.giganet.net/~nakayama/
COMMENT=	Popular freecell card game for X

USE_X11BASE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

WRKSRC=		${WRKDIR}/xfreecell
NO_CONFIGURE=	YES

MAKE_ENV+=	GMAKE=${GMAKE:Q}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
