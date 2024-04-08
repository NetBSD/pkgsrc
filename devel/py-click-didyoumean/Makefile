# $NetBSD: Makefile,v 1.5 2024/04/08 18:56:31 adam Exp $

DISTNAME=	click_didyoumean-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-didyoumean/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/click-contrib/click-didyoumean
COMMENT=	Enable git-like did-you-mean feature in click
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-click>=7:../../devel/py-click

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
