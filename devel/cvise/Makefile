# $NetBSD: Makefile,v 1.20 2024/05/29 16:31:59 adam Exp $

DISTNAME=	cvise-2.10.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=marxin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/marxin/cvise
COMMENT=	Super-parallel Python port of the C-Reduce
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-pebble-[0-9]*:../../devel/py-pebble
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	c c++17
USE_TOOLS+=	flex
TEST_TARGET=	test

USE_CXX_FEATURES+=	c++17

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD"
DEPENDS+=	unifdef-[0-9]*:../../devel/unifdef
.endif

REPLACE_PYTHON+=	cvise.py
REPLACE_PYTHON+=	cvise-delta.py

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
