# $NetBSD: Makefile,v 1.5 2026/06/01 19:58:09 adam Exp $

DISTNAME=	cucumber_tag_expressions-9.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cucumber_tag_expressions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/tag-expressions
COMMENT=	Provides a tag-expression parser and evaluation logic for cucumber/behave
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.10.0:../../devel/py-uv-build

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
