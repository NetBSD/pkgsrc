# $NetBSD: Makefile,v 1.1 2026/05/31 12:15:31 yurix Exp $

DISTNAME=	erlpack-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PYPI:=e/erlpack/}

MAINTAINER=	yurix@NetBSD.org
HOMEPAGE=	https://github.com/discord/erlpack
COMMENT=	Erlang Term Format encoder/decoder for Python
LICENSE=	apache-2.0

USE_LANGUAGES+=	c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
