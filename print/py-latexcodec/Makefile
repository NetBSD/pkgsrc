# $NetBSD: Makefile,v 1.6 2024/04/19 04:33:18 adam Exp $

DISTNAME=	latexcodec-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/latexcodec/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/latexcodec
COMMENT=	Lexer and codec for LaTeX
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
