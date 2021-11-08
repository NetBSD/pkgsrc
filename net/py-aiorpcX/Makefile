# $NetBSD: Makefile,v 1.3 2021/11/08 16:33:15 cirnatdan Exp $

DISTNAME=	aiorpcX-0.18.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiorpcX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kyuupichan/aiorpcX
COMMENT=	Generic async RPC implementation, including JSON-RPC
LICENSE=	mit

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-websockets-[0-9]*:../../www/py-websockets

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
