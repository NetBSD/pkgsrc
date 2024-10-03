# $NetBSD: Makefile,v 1.12 2024/10/03 08:43:22 adam Exp $

DISTNAME=	py_serializable-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-serializable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/madpah/serializable
COMMENT=	Library for (de)serializing Python Objects to and from JSON and XML
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-xmldiff>=0:../../textproc/py-xmldiff

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
