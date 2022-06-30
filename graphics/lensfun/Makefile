# $NetBSD: Makefile,v 1.41 2022/06/30 11:18:28 nia Exp $

DISTNAME=	lensfun-0.3.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=lensfun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://lensfun.github.io/
COMMENT=	Library for rectifying defects introduced by photographic equipment
LICENSE=	gnu-lgpl-v3

USE_CMAKE=		yes
USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake pkg-config gsed

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools>0:../../devel/py-setuptools
EGG_NAME=	${DISTNAME:C/-([^0-9])/_\1/g}
EGG_INFODIR=	${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PY_PATCHPLIST=	yes
PLIST_SUBST+=	EGG_INFODIR=${EGG_INFODIR}

REPLACE_SH=		apps/g-lensfun-update-data
REPLACE_PYTHON+=	apps/lensfun/__init__.py.in
REPLACE_PYTHON+=	apps/lensfun-add-adapter
REPLACE_PYTHON+=	apps/lensfun-update-data

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "x86_64"
CMAKE_ARGS+=		-DBUILD_FOR_SSE=OFF
CMAKE_ARGS+=		-DBUILD_FOR_SSE2=OFF
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# png: for test programs only
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
# for PYSITELIB
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
