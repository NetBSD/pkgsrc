# $NetBSD: Makefile,v 1.18 2022/01/13 19:31:24 wiz Exp $

DISTNAME=	mpmath-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpmath/}
MASTER_SITES+=	http://mpmath.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpmath.org/
COMMENT=	Python library for arbitrary-precision FP arithmetic
LICENSE=	modified-bsd

# py-gmpy provides faster backend
DEPENDS+=	${PYPKGPREFIX}-gmpy-[0-9]*:../../math/py-gmpy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
