# $NetBSD: Makefile,v 1.35 2026/01/06 11:18:42 wiz Exp $

DISTNAME=	pydoctor-25.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydoctor/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/twisted/pydoctor
COMMENT=	Python API document generator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-configargparse-[0-9]*:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.12.14:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.17:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-lunr>=0.6.2:../../textproc/py-lunr
DEPENDS+=	${PYPKGPREFIX}-platformdirs-[0-9]*:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.0:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subtests-[0-9]*:../../devel/py-test-subtests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pydoctor pydoctor-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
