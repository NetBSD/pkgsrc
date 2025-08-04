# $NetBSD: Makefile,v 1.1 2025/08/04 08:00:59 wiz Exp $

DISTNAME=	cucumber_tag_expressions-6.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cucumber_tag_expressions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/cucumber_tag_expressions/
COMMENT=	Provides a tag-expression parser and evaluation logic for cucumber/behave
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-html-[0-9]*:../../devel/py-test-html

# TODO: Extract dependencies from pyproject.toml

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
