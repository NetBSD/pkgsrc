# $NetBSD: Makefile,v 1.2 2017/06/17 19:38:10 joerg Exp $
#

DISTNAME=	lazr.delegates-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazr.delegates/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/lazr.delegates/
COMMENT=	Easily write objects that delegate behavior
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

PYSETUPTESTTARGET=	nosetests

.include "../../lang/python/pyversion.mk"

PLIST_VARS+=	python3
.if !empty(PYVERSSUFFIX:M3.*)
PLIST.python3=	yes
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
