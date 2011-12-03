# $NetBSD: Makefile,v 1.4 2011/12/03 00:02:15 joerg Exp $
#

DISTNAME=	msgpack-python-0.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python-/-/}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/msgpack-python/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

EGG_NAME=	${DISTNAME:S/-/_/}

PYTHON_VERSIONS_INCOMPATIBLE=	24

.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
