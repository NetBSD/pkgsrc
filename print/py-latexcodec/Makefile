# $NetBSD: Makefile,v 1.10 2025/08/25 08:35:10 wiz Exp $

DISTNAME=	latexcodec-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/latexcodec/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/latexcodec
COMMENT=	Lexer and codec for LaTeX
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
