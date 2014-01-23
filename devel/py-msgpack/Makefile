# $NetBSD: Makefile,v 1.8 2014/01/23 09:40:29 obache Exp $
#

DISTNAME=	msgpack-python-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python-/-/}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/msgpack-python/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCLUDE_3X=	yes

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
