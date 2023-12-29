# $NetBSD: Makefile,v 1.30 2023/12/29 18:24:48 adam Exp $

DISTNAME=	libgltf-0.1.0
PKGREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	http://dev-www.libreoffice.org/src/libgltf/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://gerrit.libreoffice.org/#/admin/projects/libgltf
COMMENT=	Rendering library for glTF
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

PKGCONFIG_OVERRIDE+=	libgltf.pc.in

# Fix build with GCC 4.8.3 under NetBSD/amd64 7.99.1
CONFIGURE_ARGS+=	--disable-werror

# Fix build with GCC 4.5.3 under NetBSD 6.1
BUILDLINK_TRANSFORM+=	rm:-Weffc++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
