# $NetBSD: Makefile,v 1.15 2022/02/08 08:54:22 adam Exp $

DISTNAME=	bitarray-2.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitarray/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ilanschnell/bitarray
COMMENT=	Efficient arrays of booleans
LICENSE=	python-software-foundation

do-test:
	${PYTHONBIN} -c 'import bitarray; bitarray.test()'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
