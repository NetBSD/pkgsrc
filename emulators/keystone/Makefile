# $NetBSD: Makefile,v 1.3 2016/06/18 14:45:43 kamil Exp $

.include "Makefile.common"

PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-platform and multi-arch assembler framework

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
LICENSE=	gnu-gpl-v2

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD=all

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
