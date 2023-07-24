# $NetBSD: Makefile,v 1.31 2023/07/24 18:43:28 adam Exp $

DISTNAME=	bitarray-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitarray/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ilanschnell/bitarray
COMMENT=	Efficient arrays of booleans
LICENSE=	python-software-foundation

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

do-test:
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -c 'import bitarray; bitarray.test()'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
