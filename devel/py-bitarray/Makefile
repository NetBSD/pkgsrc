# $NetBSD: Makefile,v 1.16 2022/02/22 08:36:15 adam Exp $

DISTNAME=	bitarray-2.3.7
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
