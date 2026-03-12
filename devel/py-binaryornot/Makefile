# $NetBSD: Makefile,v 1.8 2026/03/12 05:33:28 adam Exp $

DISTNAME=	binaryornot-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/binaryornot/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/audreyr/binaryornot
COMMENT=	Guess whether a file is binary or text
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
