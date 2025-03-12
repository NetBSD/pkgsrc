# $NetBSD: Makefile,v 1.1 2025/03/12 15:04:50 adam Exp $

DISTNAME=	ipython_pygments_lexers-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython-pygments-lexers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipython/ipython-pygments-lexers
COMMENT=	Variety of Pygments lexers for highlighting IPython code
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-pygments>0:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
