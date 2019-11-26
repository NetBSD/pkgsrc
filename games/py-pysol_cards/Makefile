# $NetBSD: Makefile,v 1.1 2019/11/26 18:50:59 markd Exp $

DISTNAME=	pysol_cards-0.8.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysol-cards/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fc-solve.shlomifish.org/
COMMENT=	Deal PySol FC Cards
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-pbr>=2.0:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
