# $NetBSD: Makefile,v 1.3 2022/10/06 13:07:19 gdt Exp $

# Do not update to 1.3.x without understanding the impacts of a change
# that breaks at least some poetry-using programs.  -gdt
# https://github.com/matrix-org/synapse/issues/14079
DISTNAME=	poetry-core-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-poetry.org/
COMMENT=	Poetry PEP 517 build backend
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=1.7.0:../../devel/py-importlib-metadata
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
