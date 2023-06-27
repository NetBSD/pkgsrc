# $NetBSD: Makefile,v 1.5 2023/06/27 11:47:39 adam Exp $

DISTNAME=	click-repl-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-repl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/untitaker/click-repl
COMMENT=	REPL plugin for Click
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.36:../../devel/py-prompt_toolkit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
