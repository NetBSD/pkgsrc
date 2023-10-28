# $NetBSD: Makefile,v 1.17 2023/10/28 19:56:55 wiz Exp $

DISTNAME=	colorama-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colorama/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tartley/colorama
COMMENT=	Cross-platform coloured terminal text
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
