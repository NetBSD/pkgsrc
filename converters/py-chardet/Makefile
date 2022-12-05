# $NetBSD: Makefile,v 1.32 2022/12/05 08:35:47 adam Exp $

DISTNAME=	chardet-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chardet/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/chardet/chardet
COMMENT=	Universal encoding detector for Python 3
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-exceptiongroup-[0-9]*:../../devel/py-exceptiongroup
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} chardetect chardetect-${PYVERSSUFFIX} || ${TRUE}

# as of 5.0.0
# 1 failed, 375 passed, 6 xfailed, 1 xpassed
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
