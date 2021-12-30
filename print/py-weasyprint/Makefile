# $NetBSD: Makefile,v 1.33 2021/12/30 13:05:40 adam Exp $

DISTNAME=	weasyprint-53.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/weasyprint/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://weasyprint.org/
COMMENT=	Converts HTML/CSS documents to PDF
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	pango>=1.29.3:../../devel/pango
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cffi>=0.6:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cssselect2>=0.1:../../textproc/py-cssselect2
DEPENDS+=	${PYPKGPREFIX}-fonttools>=4.0.0:../../fonts/py-fonttools
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.0.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-pydyf>=0.0.3:../../print/py-pydyf
DEPENDS+=	${PYPKGPREFIX}-pyphen>=0.9.1:../../textproc/py-pyphen
DEPENDS+=	${PYPKGPREFIX}-tinycss2>=1.0.0:../../textproc/py-tinycss2
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-fonttools

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} weasyprint weasyprint-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
