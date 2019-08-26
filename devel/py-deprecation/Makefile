# $NetBSD: Makefile,v 1.11 2019/08/26 10:43:17 adam Exp $

DISTNAME=	deprecation-2.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deprecation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://deprecation.readthedocs.io/
COMMENT=	Library to handle automated deprecations
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
