# $NetBSD: Makefile,v 1.13 2022/11/09 22:46:49 wiz Exp $

DISTNAME=	colorama-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colorama/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tartley/colorama
COMMENT=	Cross-platform coloured terminal text
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
