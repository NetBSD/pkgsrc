# $NetBSD: Makefile,v 1.15 2026/10/16 19:43:54 adam Exp $

DISTNAME=	alpha_vantage-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alpha_vantage/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/RomelTorres/alpha_vantage
COMMENT=	Python wrapper for Alpha Vantage API for financial data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
