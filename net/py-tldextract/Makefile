# $NetBSD: Makefile,v 1.34 2026/10/20 04:40:45 adam Exp $

DISTNAME=	tldextract-5.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tldextract/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/john-kurkowski/tldextract
COMMENT=	Accurately separate the TLD from the registered domain and subdomains
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.0.8:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-idna>=0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-file>=1.4:../../devel/py-requests-file
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-syrupy>=0:../../devel/py-syrupy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-pylint>=0:../../devel/py-test-pylint

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	tldextract

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
