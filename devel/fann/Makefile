# $NetBSD: Makefile,v 1.10 2020/05/13 03:37:30 rillig Exp $

PKGREVISION=		2

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		cmake
USE_CMAKE=		yes

USE_LANGUAGES+=	c99
# Perhaps not, but cmake complains
USE_LANGUAGES+=	c++

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	cmake/fann.pc.cmake

.include "../../mk/bsd.pkg.mk"
