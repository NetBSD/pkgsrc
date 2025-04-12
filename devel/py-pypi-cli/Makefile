# $NetBSD: Makefile,v 1.6 2025/04/12 20:03:46 adam Exp $

DISTNAME=	pypi-cli-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypi-cli/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sloria/pypi-cli
COMMENT=	Command-line interface to the Python Package Index
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=3.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-requests>=2.3.0:../../devel/py-requests

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/pypi bin/pypi-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
