# $NetBSD: Makefile,v 1.17 2026/07/11 08:20:41 wiz Exp $

DISTNAME=	stone-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dropbox/stone
COMMENT=	Interface description language (IDL) for APIs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.1.0:../../devel/py-coverage

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	stone

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
