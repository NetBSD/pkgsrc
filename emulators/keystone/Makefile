# $NetBSD: Makefile,v 1.5 2019/04/25 07:32:52 maya Exp $

PKGREVISION= 1
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-platform and multi-arch assembler framework

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
LICENSE=	gnu-gpl-v2

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD=all

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
