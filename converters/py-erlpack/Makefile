# $NetBSD: Makefile,v 1.2 2026/06/06 20:39:27 yurix Exp $

DISTNAME=	erlpack-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PYPI:=e/erlpack/}

MAINTAINER=	yurix@NetBSD.org
HOMEPAGE=	https://github.com/discord/erlpack
COMMENT=	Erlang Term Format encoder/decoder for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+= ${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES+=	c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
