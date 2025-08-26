# $NetBSD: Makefile,v 1.11 2025/08/26 10:33:55 adam Exp $

DISTNAME=	pylint_plugin_utils-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-plugin-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pylint-dev/pylint-plugin-utils
COMMENT=	Utilities and helpers for writing Pylint plugins
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pylint>=1.7:../../devel/py-pylint

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
