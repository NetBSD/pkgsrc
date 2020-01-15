# $NetBSD: Makefile,v 1.6 2020/01/15 09:03:39 adam Exp $

DISTNAME=	anytree-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anytree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/c0fec0de/anytree
COMMENT=	Powerful and Lightweight Python Tree Data Structure
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	nosetests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
