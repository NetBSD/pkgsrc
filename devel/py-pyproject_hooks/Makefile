# $NetBSD: Makefile,v 1.3 2023/10/25 22:27:13 wiz Exp $

DISTNAME=	pyproject_hooks-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyproject_hooks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyproject-hooks.readthedocs.io/
COMMENT=	Wrappers to call pyproject.toml-based build backend hooks
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
