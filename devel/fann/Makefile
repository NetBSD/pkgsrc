# $NetBSD: Makefile,v 1.12 2023/01/24 18:36:22 wiz Exp $

PKGREVISION=		2

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		cmake

USE_LANGUAGES+=	c99
# Perhaps not, but cmake complains
USE_LANGUAGES+=	c++

PKGCONFIG_OVERRIDE+=	cmake/fann.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
