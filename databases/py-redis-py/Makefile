# $NetBSD: Makefile,v 1.2 2014/06/08 15:56:39 rodent Exp $

DISTNAME=	redis-2.10.1
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
