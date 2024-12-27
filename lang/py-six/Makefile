# $NetBSD: Makefile,v 1.24 2024/12/27 09:02:13 wiz Exp $

DISTNAME=	six-1.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/six/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/benjaminp/six
COMMENT=	Python 2 and 3 compatibility utilities
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_27_ACCEPTED=	yes

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 300
TEST_DEPENDS+= ${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
do-test:
	${RUN} cd ${WRKSRC}/${PYSETUPSUBDIR} && \
	${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
