# $NetBSD: Makefile,v 1.10 2025/12/20 22:23:08 wiz Exp $

DISTNAME=	aiodns-3.6.1
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

# as of 3.6.1
# 11 failed, 113 passed, 55 skipped, 8 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
