# $NetBSD: Makefile,v 1.17 2026/03/06 06:49:26 adam Exp $

DISTNAME=	astropy_iers_data-0.2026.3.2.0.47.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astropy-iers-data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/astropy-iers-data
COMMENT=	IERS Earth Rotation and Leap Second tables for astropy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5.0:../../devel/py-hatchling
# Currently unused
#TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-remotedata-[0-9]*:../../net/py-test-remotedata

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
