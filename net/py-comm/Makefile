# $NetBSD: Makefile,v 1.9 2025/08/02 10:47:33 adam Exp $

DISTNAME=	comm-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/comm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipython/comm
COMMENT=	Jupyter Python Comm implementation
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.10:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.4:../../devel/py-traitlets

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
