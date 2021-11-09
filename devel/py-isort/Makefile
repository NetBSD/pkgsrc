# $NetBSD: Makefile,v 1.20 2021/11/09 10:17:02 adam Exp $

DISTNAME=	isort-5.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/isort
COMMENT=	Python utility/library to sort imports
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.3:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in isort isort-identify-imports
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests/unit/test_isort.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
