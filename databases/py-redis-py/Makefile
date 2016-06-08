# $NetBSD: Makefile,v 1.5 2016/06/08 17:43:22 wiz Exp $

DISTNAME=	redis-2.10.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/-py-/1}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/andymccurdy/redis-py/
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	redis-[0-9]*:../../databases/redis

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
