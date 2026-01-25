# $NetBSD: Makefile,v 1.3 2026/01/25 07:38:08 wiz Exp $

DISTNAME=	dnspython-1.16.0
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	https://www.dnspython.org/kits/${PKGVERSION_NOREV}/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://www.dnspython.org/
COMMENT=	Python DNS toolkit (v1)
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.13:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py27-idna

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
