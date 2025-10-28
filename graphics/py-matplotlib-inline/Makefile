# $NetBSD: Makefile,v 1.6 2025/10/28 10:07:05 adam Exp $

DISTNAME=	matplotlib_inline-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matplotlib-inline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipython/matplotlib-inline
COMMENT=	Inline Matplotlib backend for Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-traitlets>0:../../devel/py-traitlets

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
