# $NetBSD: Makefile,v 1.13 2022/01/04 20:54:13 wiz Exp $

DISTNAME=	gmpy-1.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
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
.include "../../lang/python/egg.mk"

.if ${PYPKGPREFIX} == "py27"
_PYSETUPTOOLSINSTALLARGS:=	${PYSETUPTOOLSINSTALLARGS:N--single-version-externally-managed}
.endif

.include "../../mk/bsd.pkg.mk"
