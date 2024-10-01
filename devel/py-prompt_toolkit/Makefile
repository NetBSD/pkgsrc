# $NetBSD: Makefile,v 1.30 2024/10/01 08:28:22 adam Exp $

DISTNAME=	prompt_toolkit-3.0.48
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prompt_toolkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jonathanslenders/python-prompt-toolkit
COMMENT=	Library for building powerful interactive command lines
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
