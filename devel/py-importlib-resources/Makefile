# $NetBSD: Makefile,v 1.12 2022/10/26 10:56:27 adam Exp $

DISTNAME=	importlib_resources-5.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib_resources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-resources.readthedocs.io/
COMMENT=	Read resources from Python packages
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-zipp>=3.1.0:../../archivers/py-zipp
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
