# $NetBSD: Makefile,v 1.11 2026/02/01 17:55:53 wiz Exp $

DISTNAME=	confuse-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/confuse/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/beetbox/confuse
COMMENT=	Painless YAML configuration
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
