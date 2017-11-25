# $NetBSD: Makefile,v 1.17 2017/11/25 12:39:16 wiz Exp $

DISTNAME=		ZConfig-3.2.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_PYPI:=Z/ZConfig/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.zope.org/Members/fdrake/zconfig/
COMMENT=		Configuration library
#LICENSE=		zope-public-license-v2.1

# TEST_DEPENDS
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
#BUILD_DEPENDS+=		${PYPKGPREFIX}-manuel-[0-9]*:../../?/py-manuel
#BUILD_DEPENDS+=		${PYPKGPREFIX}-zope-testrunner-[0-9]*:../../?/py-zope-testrunner

USE_LANGUAGES=		# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
