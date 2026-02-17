# $NetBSD: Makefile,v 1.2 2026/02/17 09:28:22 adam Exp $

DISTNAME=	pyhanko_certvalidator-0.29.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyhanko_certvalidator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MatthiasValvekens/pyHanko/tree/master/pkgs/pyhanko-certvalidator
COMMENT=	Validates X.509 certificates and paths (wbond/certvalidator fork)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.8.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1crypto>=1.5.1:../../security/py-asn1crypto
DEPENDS+=	${PYPKGPREFIX}-oscrypto>=1.1.0:../../security/py-oscrypto
DEPENDS+=	${PYPKGPREFIX}-cryptography>=41.0.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-uritools>=3.0.1:../../www/py-uritools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
