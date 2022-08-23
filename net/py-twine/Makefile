# $NetBSD: Makefile,v 1.7 2022/08/23 22:09:03 wiz Exp $

DISTNAME=	twine-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://twine.readthedocs.io/
COMMENT=	Collection of utilities for publishing packages on PyPI
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.4.2:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-readme_renderer>=21.0:../../textproc/py-readme_renderer
DEPENDS+=	${PYPKGPREFIX}-requests>=2.17:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.14:../../misc/py-tqdm
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} twine twine-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
