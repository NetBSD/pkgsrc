# $NetBSD: Makefile,v 1.5 2022/01/29 08:48:40 wiz Exp $

DISTNAME=	flake8-polyfill-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-polyfill/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://gitlab.com/pycqa/flake8
COMMENT=	Polyfill package for Flake8 plugins
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-pep8-[0-9]*:../../devel/py-pep8

PYTHON_VERSIONED_DEPENDENCIES+=	test:test
PYTHON_VERSIONED_DEPENDENCIES+=	flake8

USE_LANGUAGES=	# none

# needs to be installed
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
