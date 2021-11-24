# $NetBSD: Makefile,v 1.4 2021/11/24 09:00:54 wiz Exp $

DISTNAME=	lazr.delegates-2.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazr.delegates/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/lazr.delegates/
COMMENT=	Easily write objects that delegate behavior
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	nosetests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
