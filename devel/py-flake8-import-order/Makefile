# $NetBSD: Makefile,v 1.2 2017/08/14 19:27:26 wiz Exp $

DISTNAME=	flake8-import-order-0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-import-order/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/flake8-import-order/
COMMENT=	Flake8 and pylama plugin that checks the ordering of import statements
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-lama-[0-9]*:../../devel/py-lama

# error during collection
# https://github.com/PyCQA/flake8-import-order/issues/105
do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
