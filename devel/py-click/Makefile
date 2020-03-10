# $NetBSD: Makefile,v 1.15 2020/03/10 08:25:35 adam Exp $

DISTNAME=	click-7.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://palletsprojects.com/p/click/
COMMENT=	Simple wrapper around optparse for powerful command line utilities
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
