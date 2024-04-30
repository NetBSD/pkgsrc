# $NetBSD: Makefile,v 1.1 2024/04/30 08:57:29 wiz Exp $

DISTNAME=	pytest-expect-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-expect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gsnedders/pytest-expect
COMMENT=	Py.test plugin storing test expectations by saving the set of failing tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
#TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-u-msgpack>=0:../../devel/py-u-msgpack
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.12:../../devel/py-test-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

#.if ${PYTHON_VERSION} < 311
#DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
#.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
