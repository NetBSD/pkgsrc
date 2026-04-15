# $NetBSD: Makefile,v 1.1 2026/04/15 08:08:18 adam Exp $

DISTNAME=	standard_sunau-3.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/standard-sunau/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/youknowone/python-deadlib
COMMENT=	Support for Sun AU sound format
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-audioop-lts>0:../../audio/py-audioop-lts

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 312

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
