# $NetBSD: Makefile,v 1.1 2026/11/08 18:59:41 wiz Exp $

DISTNAME=	nbmake-1.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbmake/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/treebeardtech/nbmake
COMMENT=	Pytest plugin for testing notebooks
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-nbclient>=0:../../www/py-nbclient
DEPENDS+=	${PYPKGPREFIX}-nbformat>=0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

# 23 failed, 10 passed

.include "../../lang/python/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
