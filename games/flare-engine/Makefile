# $NetBSD: Makefile,v 1.10 2020/03/08 16:49:36 wiz Exp $

DISTNAME=	flare-engine-1.11
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=flareteam/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flarerpg.org/
COMMENT=	Free Libre Action Roleplaying Engine
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0 AND ofl-v1.1

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DDATADIR:STRING="${PREFIX}/share/flare" -DBINDIR:STRING=bin -DMANDIR:STRING=${PKGMANDIR}

REPLACE_PYTHON+=	mods/default/languages/xgettext.py

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
