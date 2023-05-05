# $NetBSD: Makefile,v 1.2 2023/05/05 09:24:06 wiz Exp $

DISTNAME=	lsprotocol-2023.0.0a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lsprotocol/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/lsprotocol/
COMMENT=	Python implementation of the Language Server Protocol
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
