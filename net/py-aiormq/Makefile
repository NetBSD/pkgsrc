# $NetBSD: Makefile,v 1.12 2025/10/23 14:05:29 adam Exp $

DISTNAME=	aiormq-6.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiormq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aiormq
COMMENT=	Pure python AMQP asynchronous client library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pamqp>=3.3.0:../../net/py-pamqp
DEPENDS+=	${PYPKGPREFIX}-yarl-[0-9]*:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
