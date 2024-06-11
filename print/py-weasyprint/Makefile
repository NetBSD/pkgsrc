# $NetBSD: Makefile,v 1.49 2024/06/11 11:24:04 adam Exp $

DISTNAME=	weasyprint-62.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/weasyprint/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://weasyprint.org/
COMMENT=	Converts HTML/CSS documents to PDF
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.1.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cffi>=0.6:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cssselect2>=0.1:../../textproc/py-cssselect2
DEPENDS+=	${PYPKGPREFIX}-fonttools>=4.0.0:../../fonts/py-fonttools
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-pydyf>=0.10.0:../../print/py-pydyf
DEPENDS+=	${PYPKGPREFIX}-pyphen>=0.9.1:../../textproc/py-pyphen
DEPENDS+=	${PYPKGPREFIX}-tinycss2>=1.3.0:../../textproc/py-tinycss2
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} weasyprint weasyprint-${PYVERSSUFFIX} || ${TRUE}

BUILDLINK_API_DEPENDS.pango+=   pango>=1.44.0
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
