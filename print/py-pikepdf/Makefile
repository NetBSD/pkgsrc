# $NetBSD: Makefile,v 1.1 2024/04/30 08:14:43 wiz Exp $

DISTNAME=	pikepdf-8.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pikepdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pikepdf/
COMMENT=	Read and write PDFs with Python, powered by qpdf
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-deprecated-[0-9]*:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.8:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.0.1:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++17

.include "../../print/qpdf/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
