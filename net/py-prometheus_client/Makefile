# $NetBSD: Makefile,v 1.13 2022/11/15 15:36:51 wiz Exp $

DISTNAME=	prometheus_client-0.15.0
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

# as of 0.15.0
# Ran 273 tests in 3.987s
# FAILED (errors=1, skipped=7)

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
