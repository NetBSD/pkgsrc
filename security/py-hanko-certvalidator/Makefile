# $NetBSD: Makefile,v 1.4 2026/09/05 05:12:23 adam Exp $
#
# Changelog: https://docs.pyhanko.eu/en/latest/changelog.html#pyhanko-certvalidator

DISTNAME=	pyhanko_certvalidator-0.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyhanko_certvalidator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MatthiasValvekens/pyHanko/tree/master/pkgs/pyhanko-certvalidator
COMMENT=	Validates X.509 certificates and paths (wbond/certvalidator fork)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.8.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.9:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-asn1crypto>=1.5.1:../../security/py-asn1crypto
DEPENDS+=	${PYPKGPREFIX}-certifi>=2023.5.:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=48.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-oscrypto>=1.1.0:../../security/py-oscrypto
DEPENDS+=	${PYPKGPREFIX}-uritools>=3.0.1:../../www/py-uritools
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.1.0:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-aiohttp>=1.0.4:../../www/py-test-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=   310 311 # py-aiohttp

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
