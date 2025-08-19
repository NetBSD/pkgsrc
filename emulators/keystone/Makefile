# $NetBSD: Makefile,v 1.10 2025/08/19 10:15:19 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-platform and multi-arch assembler framework

USE_CMAKE=	yes
LICENSE=	gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DLLVM_TARGETS_TO_BUILD=all
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
