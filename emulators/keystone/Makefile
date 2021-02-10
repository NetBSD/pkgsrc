# $NetBSD: Makefile,v 1.6 2021/02/10 10:35:13 adam Exp $

.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-platform and multi-arch assembler framework

USE_CMAKE=	yes
LICENSE=	gnu-gpl-v2

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD=all

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
