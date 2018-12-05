# $NetBSD: Makefile,v 1.8 2018/12/05 16:20:45 adam Exp $

DISTNAME=	pylibmc-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylibmc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sendapatch.se/projects/pylibmc/
COMMENT=	Quick and small memcached client for Python
LICENSE=	modified-bsd

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
