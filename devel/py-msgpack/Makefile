# $NetBSD: Makefile,v 1.10 2014/06/08 23:17:37 rodent Exp $

DISTNAME=	msgpack-python-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python-/-/}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/msgpack-python/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
