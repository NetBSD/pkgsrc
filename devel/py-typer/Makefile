# $NetBSD: Makefile,v 1.1 2026/03/06 13:48:21 adam Exp $

DISTNAME=	typer-0.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastapi/typer
COMMENT=	Library for building CLI tools
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-annotated-doc>=0.0.2:../../textproc/py-annotated-doc
DEPENDS+=	${PYPKGPREFIX}-click>=8.2.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.3.0:../../misc/py-shellingham
DEPENDS+=	${PYPKGPREFIX}-rich>=12.3.0:../../comms/py-rich
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.9.5:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.32.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

# as of 0.24.1
# 21 errors
# due to py-shellingham looking for /proc/R/stat
# https://github.com/sarugaku/shellingham/issues/99

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} typer typer-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
