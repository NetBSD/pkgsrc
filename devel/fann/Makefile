# $NetBSD: Makefile,v 1.11 2022/07/25 11:12:21 wiz Exp $

PKGREVISION=		2

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		cmake
USE_CMAKE=		yes

USE_LANGUAGES+=	c99
# Perhaps not, but cmake complains
USE_LANGUAGES+=	c++

PKGCONFIG_OVERRIDE+=	cmake/fann.pc.cmake

.include "../../mk/bsd.pkg.mk"
