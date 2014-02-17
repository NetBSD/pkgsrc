# $NetBSD: Makefile,v 1.1 2014/02/17 00:39:26 rodent Exp $

DISTNAME=	redis-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/-py-/1}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/r/redis/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/andymccurdy/redis-py/
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	redis-[0-9]*:../../databases/redis

EGG_NAME=	${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
