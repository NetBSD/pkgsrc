# $NetBSD: Makefile,v 1.4 2014/12/31 13:57:26 wiz Exp $

DISTNAME=	redis-2.10.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/-py-/1}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/r/redis/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/andymccurdy/redis-py/
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	redis-[0-9]*:../../databases/redis

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
