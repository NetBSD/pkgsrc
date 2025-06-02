# $NetBSD: Makefile,v 1.25 2025/06/02 16:05:39 adam Exp $

DISTNAME=	prometheus_client-0.22.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prometheus_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prometheus/client_python
COMMENT=	Prometheus instrumentation library for Python applications
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

# 16 due to network access
# 16 failed, 284 passed, 9 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
