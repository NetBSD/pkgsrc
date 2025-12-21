# $NetBSD: Makefile,v 1.1 2025/12/21 17:21:54 wiz Exp $

DISTNAME=	roman_numerals-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/roman_numerals/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AA-Turner/roman-numerals/
COMMENT=	Manipulate well-formed Roman numerals
LICENSE=	0-clause-bsd OR cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
