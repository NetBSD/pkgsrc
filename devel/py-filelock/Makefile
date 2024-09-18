# $NetBSD: Makefile,v 1.30 2024/09/18 08:28:32 adam Exp $

DISTNAME=	filelock-3.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/filelock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/py-filelock
COMMENT=	Platform independent file lock
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.25:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4:../../devel/py-hatch-vcs
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=5:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.24:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.12:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.2:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.26.3:../../devel/py-virtualenv

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
