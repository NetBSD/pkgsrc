# $NetBSD: Makefile,v 1.16 2016/06/08 17:43:25 wiz Exp $

DISTNAME=	msgpack-python-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python-/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msgpack-python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	MessagePack (de)serializer for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
