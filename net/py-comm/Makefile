# $NetBSD: Makefile,v 1.6 2023/11/10 18:35:08 adam Exp $

DISTNAME=	comm-0.2.0
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
