# $NetBSD: Makefile,v 1.1 2024/05/07 15:40:59 nikita Exp $

DISTNAME=	ruff_lsp-0.0.53
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff_lsp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/ruff-lsp
COMMENT=	Language Server Protocol implementation for Ruff
LICENSE=	mit

# runtime
DEPENDS+=	${PYPKGPREFIX}-ruff-[0-9]*:../../devel/py-ruff

# build-time
DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ruff-lsp ruff-lsp-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
