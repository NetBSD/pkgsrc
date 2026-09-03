# $NetBSD: Makefile,v 1.1 2026/09/03 05:12:04 adam Exp $

DISTNAME=	questionary-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/questionary/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tmbo/questionary
COMMENT=	Python library to build pretty command line user prompts
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2.0:../../devel/py-prompt_toolkit
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=5.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
