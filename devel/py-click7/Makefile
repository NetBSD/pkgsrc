# $NetBSD: Makefile,v 1.2 2023/04/30 18:42:52 wiz Exp $

DISTNAME=	click-7.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://palletsprojects.com/p/click/
COMMENT=	Simple wrapper around optparse for powerful command line utilities
LICENSE=	modified-bsd

#TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
