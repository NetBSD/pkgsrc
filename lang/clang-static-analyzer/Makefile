# $NetBSD: Makefile,v 1.9 2018/08/22 09:45:19 wiz Exp $

PKGNAME=	${DISTNAME:S/cfe/clang-static-analyzer/:S/.src//}
PKGREVISION=	1

DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang

USE_TOOLS+=	perl:run

BUILD_TARGET=	clang-check scan-build scan-view
INSTALL_DIRS=	../build/tools/clang-check ../build/tools/scan-build ../build/tools/scan-view

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=ON

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 5.0.1

.include "../../lang/python/pyversion.mk"
.include "../../lang/clang/Makefile.common"
