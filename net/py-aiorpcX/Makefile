# $NetBSD: Makefile,v 1.8 2025/03/05 10:19:04 wiz Exp $

DISTNAME=	aiorpcx-0.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/x/X/}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiorpcX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kyuupichan/aiorpcX
COMMENT=	Generic async RPC implementation, including JSON-RPC
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
# ws
DEPENDS+=	${PYPKGPREFIX}-websockets>=14.0:../../www/py-websockets

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
