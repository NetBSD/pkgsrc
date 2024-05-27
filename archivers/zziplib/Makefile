# $NetBSD: Makefile,v 1.38 2024/05/27 05:01:10 adam Exp $

DISTNAME=	zziplib-0.13.75
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=gdraheim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gdraheim/zziplib
COMMENT=	Library for ZIP archive handling
LICENSE=	gnu-lgpl-v2 OR mpl-1.1

TOOL_DEPENDS+=	zip-[0-9]*:../../archivers/zip

USE_TOOLS+=	bash:build

CMAKE_ARGS+=	-DZZIPTEST=NO

CHECK_PORTABILITY_SKIP+=	old.configure

PKGCONFIG_OVERRIDE+=		${CMAKE_BUILD_DIR}/zzip/*.pc
PKGCONFIG_OVERRIDE+=		${CMAKE_BUILD_DIR}/zzipwrap/*.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../mk/bsd.prefs.mk"

.if ${SHLIB_TYPE} == "dylib"
PLIST_SUBST+=	SOEXT=dylib
.else
PLIST_SUBST+=	SOEXT=so
.endif

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
