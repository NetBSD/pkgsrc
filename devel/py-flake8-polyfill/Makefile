# $NetBSD: Makefile,v 1.6 2023/04/30 14:33:06 wiz Exp $

DISTNAME=	flake8-polyfill-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-polyfill/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://gitlab.com/pycqa/flake8
COMMENT=	Polyfill package for Flake8 plugins
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-pep8-[0-9]*:../../devel/py-pep8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# needs to be installed
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
