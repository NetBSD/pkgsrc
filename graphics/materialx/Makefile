# $NetBSD: Makefile,v 1.1 2026/11/08 15:15:55 ryoon Exp $

DISTNAME=	MaterialX-1.39.5
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	MaterialX
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://materialx.org/
COMMENT=	Representing rich material and look-development content
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting prefix
SUBST_FILES.prefix+=	cmake/modules/MaterialXConfig.cmake.in
SUBST_SED.prefix+=	-e 's,%PKGSRC_PREFIX%,${PREFIX},g'

CMAKE_CONFIGURE_ARGS+=	-DMATERIALX_BUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DMATERIALX_INSTALL_STDLIB_PATH=${PREFIX}/share/materialx/libraries
CMAKE_CONFIGURE_ARGS+=	-DMATERIALX_INSTALL_RESOURCES_PATH=${PREFIX}/share/materialx/resources

post-patch:
	${RM} -f ${WRKSRC}/resources/*.orig

.include "../../devel/cmake/build.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
