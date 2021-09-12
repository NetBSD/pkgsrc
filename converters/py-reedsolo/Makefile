# $NetBSD: Makefile,v 1.2 2021/09/12 07:02:05 wiz Exp $

DISTNAME=	reedsolo-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES+=	${MASTER_SITE_PYPI:=r/reedsolo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomerfiliba/reedsolomon
COMMENT=	Pure-Python Reed Solomon encoder/decoder
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
