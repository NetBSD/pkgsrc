# $NetBSD: Makefile,v 1.4 2024/04/30 03:57:55 adam Exp $

DISTNAME=	pyproject_hooks-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyproject_hooks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyproject-hooks.readthedocs.io/
COMMENT=	Wrappers to call pyproject.toml-based build backend hooks
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
