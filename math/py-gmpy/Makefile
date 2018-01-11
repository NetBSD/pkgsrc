# $NetBSD: Makefile,v 1.10 2018/01/11 07:59:47 adam Exp $

DISTNAME=	gmpy-1.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gmpy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/aleaxit/gmpy
COMMENT=	Python library for arbitrary precision arithmetic
LICENSE=	gnu-lgpl-v2.1

.include "../../lang/python/pyversion.mk"
do-test:
.if ${_PYTHON_VERSION} == "27"
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} gmpy_test.py
.else
	cd ${WRKSRC}/test3 && ${SETENV} ${TEST_ENV} ${PYTHONBIN} gmpy_test.py
.endif

BUILDLINK_API_DEPENDS.gmp+=	gmp>=4.2.1
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
