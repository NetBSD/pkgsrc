# $NetBSD: Makefile,v 1.2 2022/10/20 09:13:05 adam Exp $

DISTNAME=	matplotlib-inline-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matplotlib-inline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipython/matplotlib-inline
COMMENT=	Inline Matplotlib backend for Jupyter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-traitlets>0:../../devel/py-traitlets

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
