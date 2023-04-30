# $NetBSD: Makefile,v 1.21 2023/04/30 19:40:20 wiz Exp $

DISTNAME=	six-1.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/six/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/benjaminp/six
COMMENT=	Python 2 and 3 compatibility utilities
LICENSE=	mit

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 300
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
