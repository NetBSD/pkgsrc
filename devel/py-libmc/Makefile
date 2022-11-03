# $NetBSD: Makefile,v 1.11 2022/11/03 11:50:39 adam Exp $

DISTNAME=	pylibmc-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylibmc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sendapatch.se/projects/pylibmc/
COMMENT=	Quick and small memcached client for Python
LICENSE=	modified-bsd

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
