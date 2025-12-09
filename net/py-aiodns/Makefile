# $NetBSD: Makefile,v 1.9 2025/12/09 14:06:15 wiz Exp $

DISTNAME=	aiodns-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiodns/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saghul/aiodns
COMMENT=	Simple DNS resolver for asyncio
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cares>=4.9.0:../../net/py-cares

USE_LANGUAGES=	# none

# as of 3.6.0
# 11 failed, 113 passed, 55 skipped, 8 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
