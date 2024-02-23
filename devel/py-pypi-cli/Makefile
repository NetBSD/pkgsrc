# $NetBSD: Makefile,v 1.3 2024/02/23 12:17:49 wiz Exp $

DISTNAME=	pypi-cli-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypi-cli/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sloria/pypi-cli
COMMENT=	Command-line interface to the Python Package Index
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-click>=3.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	(cd ${DESTDIR}${PREFIX};\
	${MV} bin/pypi bin/pypi-${PYVERSSUFFIX} \
	)

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
