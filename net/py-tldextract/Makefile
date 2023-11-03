# $NetBSD: Makefile,v 1.25 2023/11/03 08:17:32 adam Exp $

DISTNAME=	tldextract-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tldextract/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/john-kurkowski/tldextract
COMMENT=	Accurately separate the TLD from the registered domain and subdomains
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.0.8:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-file>=1.4:../../devel/py-requests-file
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-pylint-[0-9]*:../../devel/py-test-pylint

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tldextract tldextract-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
