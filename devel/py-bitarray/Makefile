# $NetBSD: Makefile,v 1.34 2023/11/16 12:28:50 adam Exp $

DISTNAME=	bitarray-2.8.3
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
