# $NetBSD: Makefile,v 1.1.1.1 2010/08/10 17:59:00 drochner Exp $
#

DISTNAME=	gmpy-1.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://gmpy.googlecode.com/files/
EXTRACT_SUFX=	.zip
EXTRACT_SUFX=	.zip
# XXX: all text file are DOS style.
# XXX: if future version install binary file,
# XXX: please consider to use another method.
EXTRACT_OPTS_ZIP=	-aaqo

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/gmpy
COMMENT=	Library for arbitrary precision arithmetic wirtten by Python
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
BUILD_TARGET= gmpy.so

PYTHON_VERSIONS_INCOMPATIBLE= 22 21 20
PYDISTUTILSPKG= yes
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
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
