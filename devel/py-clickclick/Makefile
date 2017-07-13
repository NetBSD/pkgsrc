# $NetBSD: Makefile,v 1.4 2017/07/13 06:12:40 adam Exp $

DISTNAME=	clickclick-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/clickclick/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zalando/python-clickclick
COMMENT=	Click utility functions
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click>=4.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
