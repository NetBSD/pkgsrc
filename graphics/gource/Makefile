# $NetBSD: Makefile,v 1.30 2018/08/16 18:54:51 adam Exp $

DISTNAME=	gource-0.40
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	http://gource.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://gource.io/
COMMENT=	Software version control visualization
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS=	--with-boost=${BUILDLINK_PREFIX.boost-libs}

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
