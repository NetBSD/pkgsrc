# $NetBSD: Makefile,v 1.3 2024/04/19 04:27:20 adam Exp $

DISTNAME=	matplotlib_inline-0.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matplotlib-inline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipython/matplotlib-inline
COMMENT=	Inline Matplotlib backend for Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-traitlets>0:../../devel/py-traitlets

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
