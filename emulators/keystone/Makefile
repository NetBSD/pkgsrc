# $NetBSD: Makefile,v 1.9 2024/08/25 06:18:40 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-platform and multi-arch assembler framework

USE_CMAKE=	yes
LICENSE=	gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DLLVM_TARGETS_TO_BUILD=all

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
