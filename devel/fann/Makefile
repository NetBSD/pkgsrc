# $NetBSD: Makefile,v 1.13 2025/08/11 08:51:35 wiz Exp $

PKGREVISION=		2

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		cmake

USE_LANGUAGES+=	c
# Perhaps not, but cmake complains
USE_LANGUAGES+=	c++

USE_CC_FEATURES+=	c99

PKGCONFIG_OVERRIDE+=	cmake/fann.pc.cmake

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
