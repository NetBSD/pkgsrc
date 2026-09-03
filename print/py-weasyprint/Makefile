# $NetBSD: Makefile,v 1.63 2026/09/03 06:51:34 adam Exp $

DISTNAME=	weasyprint-69.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/weasyprint/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://weasyprint.org/
COMMENT=	Converts HTML/CSS documents to PDF
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.1.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cffi>=0.6:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cssselect2>=0.8.0:../../textproc/py-cssselect2
DEPENDS+=	${PYPKGPREFIX}-fonttools>=4.59.2:../../fonts/py-fonttools
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-pydyf>=0.11.0:../../print/py-pydyf
DEPENDS+=	${PYPKGPREFIX}-pyphen>=0.9.1:../../textproc/py-pyphen
DEPENDS+=	${PYPKGPREFIX}-tinycss2>=1.5.0:../../textproc/py-tinycss2
DEPENDS+=	${PYPKGPREFIX}-tinyhtml5>=2.0.0:../../textproc/py-tinyhtml5
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8>=0:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort>=0:../../devel/py-test-isort

PY_RENAME_BINARIES=	weasyprint

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

BUILDLINK_API_DEPENDS.pango+=   pango>=1.44.0
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
