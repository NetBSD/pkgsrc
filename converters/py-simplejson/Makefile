# $NetBSD: Makefile,v 1.57 2025/10/02 14:46:05 adam Exp $

DISTNAME=	simplejson-3.20.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/simplejson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simplejson/simplejson
COMMENT=	Simple, fast, complete and extensible JSON encoder/decoder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
