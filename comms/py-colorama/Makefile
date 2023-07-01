# $NetBSD: Makefile,v 1.15 2023/07/01 08:54:01 wiz Exp $

DISTNAME=	colorama-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_WHEEL:=colorama/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tartley/colorama
COMMENT=	Cross-platform coloured terminal text
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
