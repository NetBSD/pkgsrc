# $NetBSD: Makefile,v 1.20 2026/11/23 07:21:14 wiz Exp $

DISTNAME=	typer-0.29.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastapi/typer
COMMENT=	Library for building CLI tools
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-annotated-doc>=0.0.2:../../textproc/py-annotated-doc
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.5.3:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-rich>=13.8.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.3.0:../../misc/py-shellingham
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.9.5:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.32.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	typer

# as of 0.29.2, all tests pass after 'make install'
TEST_ENV+=	PYTHONPATH=${WRKSRC}
# from scripts/test.sh
TEST_ENV+=	TERMINAL_WIDTH=3000
TEST_ENV+=	_TYPER_FORCE_DISABLE_TERMINAL=1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
