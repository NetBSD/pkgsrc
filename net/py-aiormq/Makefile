# $NetBSD: Makefile,v 1.13 2026/02/23 15:01:32 adam Exp $

DISTNAME=	aiormq-6.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiormq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aiormq
COMMENT=	Pure python AMQP asynchronous client library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.10.4:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-pamqp>=3.3.0:../../net/py-pamqp
DEPENDS+=	${PYPKGPREFIX}-yarl-[0-9]*:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
