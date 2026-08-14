# $NetBSD: Makefile,v 1.18 2026/08/14 11:54:44 adam Exp $

DISTNAME=	stone-3.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dropbox/stone
COMMENT=	Interface description language (IDL) for APIs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=83.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=10.2.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.6:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging>=26.2:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.1.0:../../devel/py-coverage

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	stone

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
