# $NetBSD: Makefile,v 1.3 2022/01/04 20:54:01 wiz Exp $

DISTNAME=	pysol_cards-0.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysol-cards/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fc-solve.shlomifish.org/
COMMENT=	Deal PySol FC Cards
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-random2-[0-9]*:../../devel/py-random2
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
