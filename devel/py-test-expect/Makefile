# $NetBSD: Makefile,v 1.3 2026/10/16 18:11:51 adam Exp $

DISTNAME=	pytest-expect-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-expect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gsnedders/pytest-expect
COMMENT=	Py.test plugin storing test expectations by saving the set of failing tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
#TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-u-msgpack>=0:../../devel/py-u-msgpack
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.12:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
