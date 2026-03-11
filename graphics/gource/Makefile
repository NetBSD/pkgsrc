# $NetBSD: Makefile,v 1.66 2026/03/11 10:28:10 adam Exp $

DISTNAME=	gource-0.56
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=acaudwell/}
GITHUB_PROJECT=	Gource
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://gource.io/
COMMENT=	Software version control visualization
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ENV+=	ax_cv_boost_system=yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/glu/buildlink3.mk"
.endif

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
