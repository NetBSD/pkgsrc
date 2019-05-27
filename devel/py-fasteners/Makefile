# $NetBSD: Makefile,v 1.4 2019/05/27 15:53:09 adam Exp $

DISTNAME=	fasteners-0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fasteners/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://fasteners.readthedocs.io/
COMMENT=	Python package providing useful locks
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-monotonic>=0.1:../../time/py-monotonic
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
