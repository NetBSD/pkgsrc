# $NetBSD: Makefile,v 1.3 2016/03/24 13:45:57 wiz Exp $

DISTNAME=	rsa-3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rsa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://stuvel.eu/rsa
COMMENT=	Pure-Python RSA implementation
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
BUILD_DEPENDS+=	${PYPKGPREFIX}-constants-[0-9]*:../../devel/py-constants
BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
