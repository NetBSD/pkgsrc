# $NetBSD: Makefile,v 1.5 2021/12/30 13:05:40 adam Exp $

DISTNAME=	aiorpcX-0.22.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiorpcX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kyuupichan/aiorpcX
COMMENT=	Generic async RPC implementation, including JSON-RPC
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-websockets-[0-9]*:../../www/py-websockets

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
