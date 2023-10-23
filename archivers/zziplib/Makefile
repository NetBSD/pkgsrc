# $NetBSD: Makefile,v 1.34 2023/10/23 06:37:32 wiz Exp $

DISTNAME=	zziplib-0.13.72
PKGREVISION=	3
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

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	dylib
.if ${SHLIB_TYPE} == "dylib"
PLIST.dylib=	yes
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
