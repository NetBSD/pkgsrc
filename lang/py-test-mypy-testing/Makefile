# $NetBSD: Makefile,v 1.3 2024/03/06 18:59:00 adam Exp $

DISTNAME=	pytest-mypy-testing-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-mypy-testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidfritzsche/pytest-mypy-testing
COMMENT=	Pytest plugin to check mypy output
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-mypy>=1.0:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
