# $NetBSD: Makefile,v 1.27 2020/05/16 09:03:23 adam Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/myhdl/MyHDL/}
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hardware description in Python

PYTHON_VERSIONED_DEPENDENCIES=	test:test

.include "../../lang/python/pyversion.mk"

# Python 2.x only -- subprocess is part of Python 3.x
.if ${_PYTHON_VERSION} < 32
BUILD_DEPENDS+=	${PYPKGPREFIX}-subprocess32-[0-9]*:../../devel/py-subprocess32
.endif

do-test:
	${RUN} cd ${WRKSRC}/myhdl/test/core && \
		${SETENV} ${TEST_ENV} \
		PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} \
			py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
