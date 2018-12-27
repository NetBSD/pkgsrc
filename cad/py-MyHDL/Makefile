# $NetBSD: Makefile,v 1.25 2018/12/27 16:01:54 joerg Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/myhdl/MyHDL/}
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hardware description in Python

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

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
.include "../../mk/bsd.pkg.mk"
