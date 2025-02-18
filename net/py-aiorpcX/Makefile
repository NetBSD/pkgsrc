# $NetBSD: Makefile,v 1.7 2025/02/18 10:51:10 adam Exp $

DISTNAME=	aiorpcx-0.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/x/X/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiorpcX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kyuupichan/aiorpcX
COMMENT=	Generic async RPC implementation, including JSON-RPC
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/x/X/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
# ws
DEPENDS+=	${PYPKGPREFIX}-websockets>=14.0:../../www/py-websockets

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
