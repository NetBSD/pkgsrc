# $NetBSD: Makefile,v 1.8 2017/11/28 09:24:35 adam Exp $

DISTNAME=	flake8-import-order-0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-import-order/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/flake8-import-order/
COMMENT=	Flake8 and pylama plugin that checks the ordering of import statements
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-asttokens-[0-9]*:../../lang/py-asttokens
DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-lama-[0-9]*:../../devel/py-lama
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# error during collection
# https://github.com/PyCQA/flake8-import-order/issues/105
do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
