# $NetBSD: Makefile,v 1.2 2016/02/21 10:47:20 wiz Exp $

DISTNAME=	service_identity-16.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/service_identity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/service_identity
COMMENT=	Service identity verification for pyOpenSSL
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.12:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-asn1-modules-[0-9]*:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-characteristic>=14.0.0:../../devel/py-characteristic
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not supported as of 16.0.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
