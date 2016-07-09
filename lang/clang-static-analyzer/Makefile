# $NetBSD: Makefile,v 1.5 2016/07/09 13:03:53 wiz Exp $

PKGNAME=	${DISTNAME:S/cfe/clang-static-analyzer/:S/.src//}
PKGREVISION=	1

DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang

USE_TOOLS+=	perl:run

BUILD_TARGET=	clang-check scan-build scan-view

INSTALL_DIRS=	../build/tools/clang-check ../build/tools/scan-build ../build/tools/scan-view

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=ON

REPLACE_PYTHON=	# empty
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 3.5

.include "../../lang/python/application.mk"
.include "../../lang/clang/Makefile.common"
