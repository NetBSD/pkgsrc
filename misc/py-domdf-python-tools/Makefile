# $NetBSD: Makefile,v 1.1 2024/05/14 09:12:00 adam Exp $

DISTNAME=	domdf_python_tools-3.8.0.post2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/domdf-python-tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/domdfcoding/domdf_python_tools
COMMENT=	Helpful functions for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.34.2:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-natsort>=7.0.1:../../textproc/py-natsort
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.1:../../devel/py-typing-extensions
#TEST_DEPENDS+=	${PYPKGPREFIX}-coincidence

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6.0:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
