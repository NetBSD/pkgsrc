# $NetBSD: Makefile,v 1.31 2026/09/04 12:23:47 adam Exp $

DISTNAME=	pikepdf-10.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pikepdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pikepdf/pikepdf
COMMENT=	Read and write PDFs with Python, powered by qpdf
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0.10:../../devel/py-scikit-build-core
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.0.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.8:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.36:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.5.0:../../devel/py-test-xdist

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../devel/py-nanobind/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../print/qpdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
