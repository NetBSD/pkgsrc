# $NetBSD: Makefile,v 1.9 2025/04/16 11:08:10 adam Exp $

DISTNAME=	astropy_iers_data-0.2025.4.14.0.37.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astropy-iers-data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/astropy-iers-data
COMMENT=	IERS Earth Rotation and Leap Second tables for astropy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
# Currently unused
#TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-remotedata-[0-9]*:../../net/py-test-remotedata

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
