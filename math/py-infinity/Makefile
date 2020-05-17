# $NetBSD: Makefile,v 1.5 2020/05/17 18:57:26 adam Exp $

DISTNAME=	infinity-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/infinity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/infinity
COMMENT=	All-in-one infinity value for Python
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=2.4.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.2:../../devel/py-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
