# $NetBSD: Makefile,v 1.17 2026/10/09 09:05:19 adam Exp $

DISTNAME=	aiormq-7.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiormq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aiormq
COMMENT=	Pure python AMQP asynchronous client library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.12.19:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-pamqp>=4:../../net/py-pamqp
DEPENDS+=	${PYPKGPREFIX}-yarl>=0:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
