# $NetBSD: Makefile,v 1.12 2022/11/14 15:22:01 wiz Exp $

DISTNAME=	pylibmc-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylibmc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sendapatch.se/projects/pylibmc/
COMMENT=	Quick and small memcached client for Python
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/libmemcached/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
