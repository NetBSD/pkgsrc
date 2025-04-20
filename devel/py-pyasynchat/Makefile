# $NetBSD: Makefile,v 1.1 2025/04/20 12:28:32 adam Exp $

DISTNAME=	pyasynchat-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyasynchat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simonrob/pyasynchat
COMMENT=	Make asynchat available for Python 3.12 onwards
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pyasyncore>=1.0.2:../../devel/py-pyasyncore

USE_LANGUAGES=	# none

# Removed in Python 3.12
PYTHON_VERSIONS_INCOMPATIBLE=	39 310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
