# $NetBSD: Makefile,v 1.12 2026/08/07 18:49:37 adam Exp $

DISTNAME=	typer-0.27.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastapi/typer
COMMENT=	Library for building CLI tools
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-annotated-doc>=0.0.2:../../textproc/py-annotated-doc
DEPENDS+=	${PYPKGPREFIX}-rich>=13.8.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.3.0:../../misc/py-shellingham
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.9.5:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.32.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	typer

# as of 0.25.1
# 22 errors
# due to py-shellingham looking for /proc/R/stat
# https://github.com/sarugaku/shellingham/issues/99

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
