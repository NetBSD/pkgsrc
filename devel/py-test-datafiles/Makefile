# $NetBSD: Makefile,v 1.2 2026/01/08 10:30:15 adam Exp $

DISTNAME=	pytest_datafiles-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-datafiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/omarkohl/pytest-datafiles
COMMENT=	py.test plugin to create a 'tmp_path' containing predefined files/directories
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
