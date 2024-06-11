# $NetBSD: Makefile,v 1.4 2024/06/11 08:52:23 adam Exp $

DISTNAME=	pikepdf-9.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pikepdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pikepdf/pikepdf
COMMENT=	Read and write PDFs with Python, powered by qpdf
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.37:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.0.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-deprecated-[0-9]*:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.8:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++17

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../print/qpdf/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
