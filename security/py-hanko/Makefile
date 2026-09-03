# $NetBSD: Makefile,v 1.4 2026/09/03 10:03:21 adam Exp $
#
# Changelog: https://docs.pyhanko.eu/en/latest/changelog.html#pyhanko

DISTNAME=	pyhanko-0.37.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyhanko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MatthiasValvekens/pyHanko
COMMENT=	Tools for stamping and signing PDF files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.8.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.9:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-asn1crypto>=1.5.1:../../security/py-asn1crypto
DEPENDS+=	${PYPKGPREFIX}-cryptography>=48.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-hanko-certvalidator>=0.32.0:../../security/py-hanko-certvalidator
DEPENDS+=	${PYPKGPREFIX}-lxml>=5.4.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=4.3:../../time/py-tzlocal
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.1.0:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-aiohttp>=1.1.0:../../www/py-test-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
