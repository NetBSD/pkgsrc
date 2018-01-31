# $NetBSD: Makefile,v 1.1 2018/01/31 19:13:17 minskim Exp $

DISTNAME=	alpha_vantage-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=RomelTorres/}
GITHUB_PROJECT=	alpha_vantage

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/RomelTorres/alpha_vantage
COMMENT=	Python wrapper for Alpha Vantage API for financial data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
