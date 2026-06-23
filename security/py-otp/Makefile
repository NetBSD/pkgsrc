# $NetBSD: Makefile,v 1.3 2026/06/23 13:19:15 adam Exp $

DISTNAME=	pyotp-2.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyotp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pyauth/pyotp
COMMENT=	Python One-Time Password Library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
