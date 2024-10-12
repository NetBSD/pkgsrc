# $NetBSD: Makefile,v 1.6 2024/10/12 11:04:07 wiz Exp $

DISTNAME=	pyproject_hooks-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyproject_hooks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyproject-hooks.readthedocs.io/
COMMENT=	Wrappers to call pyproject.toml-based build backend hooks
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
