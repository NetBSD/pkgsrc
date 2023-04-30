# $NetBSD: Makefile,v 1.21 2023/04/30 12:12:52 wiz Exp $

DISTNAME=	attrs-21.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/attrs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.attrs.org/
COMMENT=	Attributes without boilerplate
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-Pympler-[0-9]*:../../devel/py-Pympler
# not required and does not support python 2.x
#TEST_DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES+=	coverage:test
PYTHON_VERSIONED_DEPENDENCIES+=	hypothesis:test
PYTHON_VERSIONED_DEPENDENCIES+=	test:test

USE_LANGUAGES=	# none

# 13 failed, 1155 passed, 11 skipped, 1 xfailed, 6 warnings
# with py-ZopeInterface
# 13 failed, 1158 passed, 8 skipped, 1 xfailed, 6 warnings
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
