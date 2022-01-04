# $NetBSD: Makefile,v 1.17 2022/01/04 20:54:01 wiz Exp $

DISTNAME=	trueskill-0.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trueskill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://trueskill.org/
COMMENT=	Python module implementing the TrueSkill rating system
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
#TEST_DEPENDS+=	${PYPKGPREFIX}-almost>=0.1.5:../../math/py-almost
#TEST_DEPENDS+=	${PYPKGPREFIX}-mpmath>=0.17:../../math/py-mpmath
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.5:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
