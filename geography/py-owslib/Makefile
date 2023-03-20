# $NetBSD: Makefile,v 1.1 2023/03/20 06:40:49 wiz Exp $

DISTNAME=	OWSLib-0.28.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	geography www
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OWSLib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://geopython.github.io/OWSLib
COMMENT=	OGC Web Service utility library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests>=1.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
