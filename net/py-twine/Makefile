# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:34 wiz Exp $

DISTNAME=	twine-1.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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

PYTHON_VERSIONED_DEPENDENCIES+=	test:test
PYTHON_VERSIONED_DEPENDENCIES+= setuptools
PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-tqdm

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} twine twine-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
