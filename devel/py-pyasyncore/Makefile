# $NetBSD: Makefile,v 1.2 2025/04/20 12:29:26 adam Exp $

DISTNAME=	pyasyncore-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyasyncore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simonrob/pyasyncore
COMMENT=	Make asyncore available for Python 3.12 onwards
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# Removed in Python 3.12
PYTHON_VERSIONS_INCOMPATIBLE=	39 310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
