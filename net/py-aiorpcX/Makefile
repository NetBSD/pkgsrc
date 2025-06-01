# $NetBSD: Makefile,v 1.10 2025/06/01 05:53:42 adam Exp $

DISTNAME=	aiorpcx-0.25.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/x/X/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiorpcX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kyuupichan/aiorpcX
COMMENT=	Generic async RPC implementation, including JSON-RPC
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# ws
DEPENDS+=	${PYPKGPREFIX}-websockets>=14.0:../../www/py-websockets

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
