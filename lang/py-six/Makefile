# $NetBSD: Makefile,v 1.22 2024/06/05 22:44:57 wiz Exp $

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

PYTHON_27_ACCEPTED=	yes
.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 300
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
