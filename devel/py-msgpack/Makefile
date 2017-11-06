# $NetBSD: Makefile,v 1.18 2017/11/06 13:34:45 wiz Exp $

DISTNAME=	msgpack-python-0.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python-/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgpack-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
