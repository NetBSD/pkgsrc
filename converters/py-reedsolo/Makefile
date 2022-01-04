# $NetBSD: Makefile,v 1.3 2022/01/04 20:52:40 wiz Exp $

DISTNAME=	reedsolo-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES+=	${MASTER_SITE_PYPI:=r/reedsolo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomerfiliba/reedsolomon
COMMENT=	Pure-Python Reed Solomon encoder/decoder
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
