# $NetBSD: Makefile,v 1.42 2025/02/04 06:34:22 adam Exp $

DISTNAME=	bitarray-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitarray/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ilanschnell/bitarray
COMMENT=	Efficient arrays of booleans
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

do-test:
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -c 'import bitarray; bitarray.test()'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
