# $NetBSD: Makefile,v 1.3 2006/11/19 11:50:25 wiz Exp $

DISTNAME=	wmget-0.6.0-src
PKGNAME=	${DISTNAME:S/-src//}
WRKSRC=		${WRKDIR}/wmget
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES= 	http://amtrickey.net/download/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://amtrickey.net/wmget/index.html
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
