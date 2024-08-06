# $NetBSD: Makefile,v 1.50 2024/08/06 12:34:35 adam Exp $

DISTNAME=	flake8-7.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycqa/flake8
COMMENT=	Modular source code checker for Python programs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.12.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=3.2.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.7.0:../../devel/py-mccabe

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flake8 flake8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
