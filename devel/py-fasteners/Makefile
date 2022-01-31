# $NetBSD: Makefile,v 1.9 2022/01/31 12:56:13 adam Exp $

DISTNAME=	fasteners-0.17.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fasteners/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/harlowja/fasteners
COMMENT=	Python package providing useful locks
LICENSE=	apache-2.0

PYSETUP=	-c 'from setuptools import setup; setup()'

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
