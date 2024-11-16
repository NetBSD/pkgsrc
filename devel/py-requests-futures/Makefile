# $NetBSD: Makefile,v 1.8 2024/11/16 20:54:09 adam Exp $

DISTNAME=	requests_futures-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-futures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ross/requests-futures
COMMENT=	Asynchronous Python HTTP for Humans
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin>=2.0.0:../../www/py-test-httpbin

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
