# $NetBSD: Makefile,v 1.26 2026/09/22 12:57:44 adam Exp $

DISTNAME=	pypiserver-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypiserver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypiserver/pypiserver
COMMENT=	Minimal PyPI server for use with pip/easy_install
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.26:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-packaging>=26.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pip>=26.0.1:../../devel/py-pip
# passlib
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.4:../../security/py-passlib
# cache
DEPENDS+=	${PYPKGPREFIX}-watchdog>=6.0.0:../../sysutils/py-watchdog

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pypi-server

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=6.5.2:../../devel/py-importlib-resources
.endif
.if ${PYTHON_VERSION} > 312
DEPENDS+=	${PYPKGPREFIX}-legacy-cgi>=2.6.4:../../www/py-legacy-cgi
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
