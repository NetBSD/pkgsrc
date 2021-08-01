# $NetBSD: Makefile,v 1.10 2021/08/01 18:17:10 adam Exp $

DISTNAME=	bitarray-2.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitarray/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ilanschnell/bitarray
COMMENT=	Efficient arrays of booleans
LICENSE=	python-software-foundation

do-test:
	${PYTHONBIN} -c 'import bitarray; bitarray.test()'

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
