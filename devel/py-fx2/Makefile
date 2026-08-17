# $NetBSD: Makefile,v 1.6 2026/08/17 20:22:30 js Exp $

DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-fx2-0.16
MASTER_SITES=	https://codeberg.org/GlasgowEmbedded/libfx2/archive/
CATEGORIES=	devel python
WRKSRC=		${WRKDIR}/libfx2
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
