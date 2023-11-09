# $NetBSD: Makefile,v 1.14 2023/11/09 06:51:59 adam Exp $

DISTNAME=	pep517-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pep517/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/pep517
COMMENT=	Wrappers to build Python packages using PEP 517 hooks
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif
# but tests don't care and always need it
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
