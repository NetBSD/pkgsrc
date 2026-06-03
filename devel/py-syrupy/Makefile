# $NetBSD: Makefile,v 1.13 2026/06/03 08:10:39 adam Exp $

DISTNAME=	syrupy-5.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/syrupy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/syrupy-project/syrupy
COMMENT=	Pytest Snapshot Test Utility
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-test>=8.0.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
