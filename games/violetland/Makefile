# $NetBSD: Makefile,v 1.33 2025/09/30 09:35:28 adam Exp $

DISTNAME=	violetland-0.5-source-with-dependencies
PKGNAME=	${DISTNAME:S/-source-with-dependencies//}
PKGREVISION=	26
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ooxi/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://violetland.github.io/
COMMENT=	Help a girl by name of Violet to struggle with monsters
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	xgettext

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
