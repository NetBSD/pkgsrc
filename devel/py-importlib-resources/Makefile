# $NetBSD: Makefile,v 1.21 2023/10/28 19:57:01 wiz Exp $

DISTNAME=	importlib_resources-6.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib_resources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-resources.readthedocs.io/
COMMENT=	Read resources from Python packages
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-zipp>=3.1.0:../../archivers/py-zipp
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
