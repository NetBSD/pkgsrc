# $NetBSD: Makefile,v 1.4 2023/05/05 09:36:15 wiz Exp $

DISTNAME=	lsprotocol-2023.0.0a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lsprotocol/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/lsprotocol/
COMMENT=	Python implementation of the Language Server Protocol
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
# from https://github.com/microsoft/lsprotocol/blob/main/requirements.in
DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-cattrs>=0:../../devel/py-cattrs
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=0:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-hamcrest>=0:../../devel/py-hamcrest

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
