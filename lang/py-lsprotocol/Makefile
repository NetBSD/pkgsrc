# $NetBSD: Makefile,v 1.8 2023/10/28 19:57:10 wiz Exp $
# Changes:
# https://github.com/microsoft/lsprotocol/releases

DISTNAME=	lsprotocol-2023.0.0b1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lsprotocol/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/lsprotocol
COMMENT=	Python implementation of the Language Server Protocol
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-attrs>=21.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-cattrs-[0-9]*:../../devel/py-cattrs

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
