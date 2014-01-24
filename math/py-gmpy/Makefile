# $NetBSD: Makefile,v 1.6 2014/01/24 09:16:18 jperkin Exp $
#

DISTNAME=	gmpy-1.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://gmpy.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/gmpy
COMMENT=	Python library for arbitrary precision arithmetic
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=	c
BUILD_TARGET= gmpy.so

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

TEST_ENV+=	PYTHONPATH=${WRKSRC}/test
do-test:
	${ECHO} "Testing py-gmpy:"
	${RUN} cd ${WRKSRC}/test; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} gmpy_test.py

INSTALLATION_DIRS=	share/doc/py-gmpy${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/gmpydoc.txt \
		${DESTDIR}${PREFIX}/share/doc/py-gmpy${PYVERSSUFFIX}

BUILDLINK_API_DEPENDS.gmp+=		gmp>=4.2.1
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
