# $NetBSD: Makefile,v 1.2 2025/11/17 09:32:22 adam Exp $

DISTNAME=	cucumber_tag_expressions-8.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cucumber_tag_expressions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/tag-expressions
COMMENT=	Provides a tag-expression parser and evaluation logic for cucumber/behave
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.9.0:../../devel/py-uv-build

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
