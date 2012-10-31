# $NetBSD: Makefile,v 1.7 2012/10/31 11:19:32 asau Exp $
#

DISTNAME=	msgpack-python-0.1.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python-/-/}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/msgpack-python/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCLUDE_3X=	yes

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
