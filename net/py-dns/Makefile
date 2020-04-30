# $NetBSD: Makefile,v 1.31 2020/04/30 12:07:57 nikita Exp $

DISTNAME=	dnspython-1.16.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	http://www.dnspython.org/kits/${PKGVERSION_NOREV}/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	Python DNS toolkit
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.13:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt-[0-9]*:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
