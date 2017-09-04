# $NetBSD: Makefile,v 1.6 2017/09/04 18:08:20 wiz Exp $

DISTNAME=	pylibmc-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylibmc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pylibmc
COMMENT=	Quick and small memcached client for Python
LICENSE=	modified-bsd

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
