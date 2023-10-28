# $NetBSD: Makefile,v 1.13 2023/10/28 19:57:10 wiz Exp $

DISTNAME=	pygls-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openlawlibrary/pygls
COMMENT=	Pythonic generic implementation of the Language Server Protocol
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-lsprotocol>=2023.0.0b1:../../lang/py-lsprotocol
DEPENDS+=	${PYPKGPREFIX}-typeguard>=3.0.0:../../devel/py-typeguard

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
