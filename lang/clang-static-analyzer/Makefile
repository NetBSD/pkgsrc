# $NetBSD: Makefile,v 1.16 2019/10/24 11:40:00 tnn Exp $

.include "../../lang/clang/Makefile.common"

PKGNAME=	${DISTNAME:S/cfe/clang-static-analyzer/:S/.src//}
PKGREVISION=	1

DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang

USE_TOOLS+=	perl:run

DISTINFO_FILE?=	${.CURDIR}/../../lang/clang/distinfo
PATCHDIR?=	${.CURDIR}/../../lang/clang/patches

BUILD_TARGET=	clang-check scan-build scan-view
INSTALL_DIRS=	../build/tools/clang-check ../build/tools/scan-build ../build/tools/scan-view

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=ON

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 5.0.1

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
