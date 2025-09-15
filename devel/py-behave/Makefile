# $NetBSD: Makefile,v 1.14 2025/09/15 15:07:12 adam Exp $

DISTNAME=	behave-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/behave/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/behave/behave
COMMENT=	Behaviour-driven development
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.7:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-cucumber-expressions>=17.1.0:../../devel/py-cucumber-expressions
DEPENDS+=	${PYPKGPREFIX}-cucumber-tag-expressions>=4.1.0:../../devel/py-cucumber-tag-expressions
DEPENDS+=	${PYPKGPREFIX}-parse>=1.18.0:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-parse_type>=0.6.0:../../textproc/py-parse_type
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-assertpy>=0:../../devel/py-assertpy
TEST_DEPENDS+=	${PYPKGPREFIX}-chardet>=0:../../converters/py-chardet
TEST_DEPENDS+=	${PYPKGPREFIX}-hamcrest>=1.8:../../devel/py-hamcrest
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.1:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-html>=0:../../devel/py-test-html

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

# as of 1.3.0
# 1846 passed, 10 skipped, 2 xfailed

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} behave behave-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
