# $NetBSD: Makefile,v 1.14 2023/01/24 09:00:48 adam Exp $

DISTNAME=	prometheus_client-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prometheus_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prometheus/client_python
COMMENT=	Prometheus instrumentation library for Python applications
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# as of 0.16.0
# Ran 276 tests
# FAILED (errors=1, skipped=9)

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
