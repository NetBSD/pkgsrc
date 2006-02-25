# $NetBSD: Makefile,v 1.1.1.1 2006/02/25 13:31:28 rpaulo Exp $

DISTNAME=	wmget-0.6.0-src
PKGNAME=	${DISTNAME:S/-src//}
WRKSRC=		${WRKDIR}/wmget
CATEGORIES=	net
MASTER_SITES= 	http://amtrickey.net/wmget/index.html

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://amtrickey.net/download/
COMMENT=	Background download manager in a Window Maker dock app

SUBST_CLASSES+=		ldflags
SUBST_MESSAGE.ldflags=	Fixing hardcoded LDFLAGS.
SUBST_STAGE.ldflags=	pre-configure
SUBST_FILES.ldflags=	Makefile
SUBST_SED.ldflags=	-e 's|^LDFLAGS=|&${LDFLAGS}|'

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's|^PREFIX=.*|PREFIX=${LOCALBASE}|'

USE_TOOLS+=	gmake

.include "../../www/curl/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
