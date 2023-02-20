# $NetBSD: Makefile,v 1.26 2023/02/20 18:10:50 wiz Exp $

DISTNAME=	bitarray-2.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitarray/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ilanschnell/bitarray
COMMENT=	Efficient arrays of booleans
LICENSE=	python-software-foundation

# https://github.com/ilanschnell/bitarray/issues/189
SUBST_CLASSES+=		pop
SUBST_SED.pop+=		-e 's,popcount64,my_popcount64,'
SUBST_FILES.pop+=	bitarray/_bitarray.c
SUBST_FILES.pop+=	bitarray/_util.c
SUBST_FILES.pop+=	bitarray/bitarray.h
SUBST_MESSAGE.pop=	Fix conflict with NetBSD's popcount.
SUBST_STAGE.pop=	pre-configure

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

do-test:
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -c 'import bitarray; bitarray.test()'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
