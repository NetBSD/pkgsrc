# $NetBSD: Makefile,v 1.14 2026/06/28 15:41:18 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
