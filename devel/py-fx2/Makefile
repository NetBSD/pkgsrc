# $NetBSD: Makefile,v 1.5 2025/04/12 10:59:19 adam Exp $

DISTNAME=	fx2-0.13
PKGREVISION=	2
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

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-libusb1-[0-9]*:../../devel/py-libusb1

USE_LANGUAGES=	# none

MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION_NOREV}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
