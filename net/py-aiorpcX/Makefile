# $NetBSD: Makefile,v 1.1 2020/04/14 19:41:53 js Exp $

DISTNAME=	aiorpcX-0.18.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiorpcX/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/kyuupichan/aiorpcX
COMMENT=	Generic async RPC implementation, including JSON-RPC
LICENSE=	mit

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-websockets-[0-9]*:../../www/py-websockets

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
