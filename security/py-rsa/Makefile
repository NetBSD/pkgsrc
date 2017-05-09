# $NetBSD: Makefile,v 1.5 2017/05/09 12:37:14 adam Exp $

DISTNAME=	rsa-3.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rsa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://stuvel.eu/rsa
COMMENT=	Pure-Python RSA implementation
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
BUILD_DEPENDS+=	${PYPKGPREFIX}-constants-[0-9]*:../../devel/py-constants
BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
