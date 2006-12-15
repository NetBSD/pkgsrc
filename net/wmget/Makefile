# $NetBSD: Makefile,v 1.4 2006/12/15 20:32:59 joerg Exp $

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
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
