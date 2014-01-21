# $NetBSD: Makefile,v 1.3 2014/01/21 10:40:19 wiz Exp $

DISTNAME=	pylibmc-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pylibmc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/pylibmc
COMMENT=	Quick and small memcached client for Python
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.2.3

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
