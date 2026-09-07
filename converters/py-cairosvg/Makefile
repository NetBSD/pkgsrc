# $NetBSD: Makefile,v 1.34 2026/09/07 16:36:11 adam Exp $

DISTNAME=	cairosvg-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cairosvg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cairosvg.org/
COMMENT=	Simple SVG Converter for Cairo
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cairocffi>=0:../../graphics/py-cairocffi
DEPENDS+=	${PYPKGPREFIX}-cssselect2>=0:../../textproc/py-cssselect2
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-tinycss2>=0:../../textproc/py-tinycss2
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-isort>=0:../../devel/py-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	cairosvg

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

# tests need a copy of the directory test_non_regression/cairosvg_reference

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
