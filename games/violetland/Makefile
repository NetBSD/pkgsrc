# $NetBSD: Makefile,v 1.10 2018/08/16 18:54:50 adam Exp $

DISTNAME=	violetland-0.5-source-with-dependencies
GITHUB_RELEASE=	${PKGVERSION_NOREV}
PKGNAME=	${DISTNAME:S/-source-with-dependencies//}
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ooxi/}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://violetland.github.io/
COMMENT=	Help a girl by name of Violet to struggle with monsters
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	xgettext

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
