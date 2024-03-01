# $NetBSD: Makefile,v 1.8 2024/03/01 12:16:36 adam Exp $

DISTNAME=	py_serializable-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-serializable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/madpah/serializable
COMMENT=	Library for (de)serializing Python Objects to and from JSON and XML
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
