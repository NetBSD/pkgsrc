# $NetBSD: Makefile,v 1.1 2024/08/10 14:18:49 js Exp $

# IMPORTANT: When updating this, extract the METADATA file from the PyPI wheel
# as PKG-INFO and update the patch!
DISTNAME=	fx2-0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=whitequark/}
GITHUB_PROJECT=	libfx2
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel python
PYSETUPSUBDIR=	software

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/fx2/
COMMENT=	Library for interacting with Cypress EZ-USB FX2 series microcontrollers
LICENSE=	0-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-usb-[0-9]*:../../devel/py-usb

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
