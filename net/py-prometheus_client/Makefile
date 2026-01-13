# $NetBSD: Makefile,v 1.27 2026/01/13 12:41:38 adam Exp $

DISTNAME=	prometheus_client-0.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prometheus_client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prometheus/client_python
COMMENT=	Prometheus instrumentation library for Python applications
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

# 1 failed, 271 passed, 10 skipped, 1 error
.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
