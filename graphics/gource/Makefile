# $NetBSD: Makefile,v 1.47 2022/03/28 10:44:21 tnn Exp $

DISTNAME=	gource-0.51
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=acaudwell/}
GITHUB_PROJECT=	Gource
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://gource.io/
COMMENT=	Software version control visualization
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS=	--with-boost=${BUILDLINK_PREFIX.boost-libs}

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
