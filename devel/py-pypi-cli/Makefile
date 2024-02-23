# $NetBSD: Makefile,v 1.2 2024/02/23 11:37:58 mef Exp $

DISTNAME=	pypi-cli-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypi-cli/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sloria/pypi-cli
COMMENT=	Command-line interface to the Python Package Index
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=3.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

# 1) use wheel.mk (needs appropriate TOOL_DEPENDS)
# 2) add "python" to CATEGORIES
# 3) add PYTHON_VERSIONS_INCOMPATIBLE=27
# 4) bin/pypi should be named pypi-${PYVERSSUFFIX}
# 5) add ALTERNATIVE

post-install:
	(cd ${DESTDIR}${PREFIX};\
	${MV} bin/pypi bin/pypi-${PYVERSSUFFIX} \
	)

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
