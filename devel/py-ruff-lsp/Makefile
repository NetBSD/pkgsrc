# $NetBSD: Makefile,v 1.2 2024/05/09 17:39:33 wiz Exp $

DISTNAME=	ruff_lsp-0.0.53
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff_lsp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/ruff-lsp
COMMENT=	Language Server Protocol implementation for Ruff
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-lsp-jsonrpc-[0-9]*:../../textproc/py-lsp-jsonrpc
DEPENDS+=	${PYPKGPREFIX}-lsprotocol-[0-9]*:../../lang/py-lsprotocol
DEPENDS+=	${PYPKGPREFIX}-pygls-[0-9]*:../../lang/py-pygls
DEPENDS+=	${PYPKGPREFIX}-ruff-[0-9]*:../../devel/py-ruff
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		ruff
SUBST_FILES.ruff+=	ruff_lsp/server.py
SUBST_SED.ruff+=	-e 's,shutil.which("ruff"),shutil.which("ruff-${PYVERSSUFFIX}"),'
SUBST_STAGE.ruff=	pre-build
SUBST_MESSAGE.ruff=	Fixing path to ruff binary.

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ruff-lsp ruff-lsp-${PYVERSSUFFIX} || ${TRUE}

pre-test:
	${LN} -sf ${DESTDIR}${PREFIX}/bin/ruff-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/ruff

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
