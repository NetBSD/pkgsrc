# $NetBSD: Makefile,v 1.2 2021/12/30 13:05:36 adam Exp $

DISTNAME=	astroplan-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=astropy/}
GITHUB_PROJECT=	astroplan
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://astroplan.readthedocs.io/en/latest/
COMMENT=	Astropy affiliated module for planning astronomical observations
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.4:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-astropy>=4.2:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-astroquery>=0.3.9:../../math/py-astroquery

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
