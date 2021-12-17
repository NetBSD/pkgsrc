# $NetBSD: Makefile,v 1.15 2021/12/17 00:29:35 wiz Exp $

DISTNAME=	trueskill-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trueskill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://trueskill.org/
COMMENT=	Python module implementing the TrueSkill rating system
LICENSE=	2-clause-bsd

#TEST_DEPENDS+=	${PYPKGPREFIX}-mpmath>=0.17:../../math/py-mpmath
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-almost>=0.1.5:../../math/py-almost

USE_LANGUAGES=			# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
