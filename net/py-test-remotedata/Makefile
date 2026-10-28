# $NetBSD: Makefile,v 1.5 2026/10/28 05:39:25 adam Exp $

DISTNAME=	pytest_remotedata-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^pytest_/test-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-remotedata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/pytest-remotedata
COMMENT=	Pytest plugin for controlling remote data access
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-test>=7.2:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
