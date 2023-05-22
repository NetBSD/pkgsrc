# $NetBSD: Makefile,v 1.9 2023/05/22 07:19:32 adam Exp $

DISTNAME=	pylint_plugin_utils-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-plugin-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-plugin-utils
COMMENT=	Utilities and helpers for writing Pylint plugins
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pylint>=1.7:../../devel/py-pylint

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
