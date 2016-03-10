# $NetBSD: Makefile,v 1.3 2016/03/10 15:01:52 tnn Exp $

PKGNAME=	${DISTNAME:S/cfe/clang-static-analyzer/:S/.src//}

DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang

USE_TOOLS+=	perl:run

BUILD_TARGET=	clang-check scan-build scan-view

INSTALL_DIRS=	../build/tools/clang-check ../build/tools/scan-build ../build/tools/scan-view

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=ON

REPLACE_PYTHON=	# empty
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 3.5

.include "../../lang/python/application.mk"
.include "../../lang/clang/Makefile.common"
