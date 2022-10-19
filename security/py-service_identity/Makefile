# $NetBSD: Makefile,v 1.10 2022/10/19 14:25:20 nia Exp $

DISTNAME=	service_identity-18.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/service_identity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/service_identity
COMMENT=	Service identity verification for pyOpenSSL
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-asn1-modules-[0-9]*:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-characteristic>=14.0.0:../../devel/py-characteristic
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
