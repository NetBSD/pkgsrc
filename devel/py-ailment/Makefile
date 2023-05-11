#	$NetBSD: Makefile,v 1.4 2023/05/11 07:17:24 adam Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	ailment-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ailment/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/angr/ailment
COMMENT=	The angr intermediate language
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-archinfo-[0-9]*:../../devel/py-archinfo
TEST_DEPENDS+=	${PYPKGPREFIX}-pyvex-[0-9]*:../../devel/py-pyvex

PYTHON_VERSIONS_INCOMPATIBLE+=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest tests/*.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
