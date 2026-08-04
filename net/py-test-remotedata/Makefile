# $NetBSD: Makefile,v 1.4 2026/08/04 20:18:59 adam Exp $

DISTNAME=	pytest_remotedata-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^pytest_/test-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-remotedata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/pytest-remotedata
COMMENT=	Pytest plugin for controlling remote data access
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=5.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
