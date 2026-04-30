# $NetBSD: Makefile,v 1.18 2026/04/30 12:11:14 adam Exp $

DISTNAME=	fido2-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fido2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/python-fido2/
COMMENT=	Yubico FIDO U2F and FIDO 2.0 USB Python library
LICENSE=	2-clause-bsd AND apache-2.0 AND mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.6:../../security/py-cryptography
# optional
DEPENDS+=	${PYPKGPREFIX}-scard>=2.0.0:../../devel/py-scard

# as of 1.2.0
# check fido2/hid/__init__.py for supported platforms
BROKEN_ON_PLATFORM+=	SunOS-*-*

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
