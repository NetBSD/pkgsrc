# $NetBSD: Makefile,v 1.6 2026/09/22 18:35:14 adam Exp $

DISTNAME=	click_repl-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-repl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/untitaker/click-repl
COMMENT=	REPL plugin for Click
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.36:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.7.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
