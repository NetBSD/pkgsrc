# $NetBSD: Makefile,v 1.10 2025/08/02 10:48:15 adam Exp $

DISTNAME=	comm-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/comm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipython/comm
COMMENT=	Jupyter Python Comm implementation
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.10:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
