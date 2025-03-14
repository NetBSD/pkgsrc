# $NetBSD: Makefile,v 1.32 2025/03/14 08:07:18 adam Exp $

DISTNAME=	filelock-3.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/filelock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/py-filelock
COMMENT=	Platform independent file lock
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.24:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.3.1:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.28.1:../../devel/py-virtualenv

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
