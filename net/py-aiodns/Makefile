# $NetBSD: Makefile,v 1.12 2026/05/17 15:50:31 wiz Exp $

DISTNAME=	aiodns-4.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiodns/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saghul/aiodns
COMMENT=	Simple DNS resolver for asyncio
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cares>=5.0.0:../../net/py-cares

USE_LANGUAGES=	# none

# as of 4.0.3
# 29 failed, 110 passed, 55 skipped, 63 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
