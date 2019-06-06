# $NetBSD: Makefile,v 1.2 2019/06/06 21:11:52 adam Exp $

DISTNAME=	latexcodec-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/latexcodec/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/latexcodec
COMMENT=	Lexer and codec for LaTeX
LICENSE=	mit

DEPENDS+=       ${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
