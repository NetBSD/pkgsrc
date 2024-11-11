# $NetBSD: Makefile,v 1.5 2024/11/11 07:28:20 wiz Exp $

DISTNAME=	pypi-cli-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypi-cli/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sloria/pypi-cli
COMMENT=	Command-line interface to the Python Package Index
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=3.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-requests>=2.3.0:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/pypi bin/pypi-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
