# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:22 wiz Exp $

DISTNAME=	prompt_toolkit-1.0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prompt_toolkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jonathanslenders/python-prompt-toolkit
COMMENT=	Library for building powerful interactive command lines
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
