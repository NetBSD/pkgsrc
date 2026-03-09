# $NetBSD: Makefile,v 1.21 2026/03/09 16:56:18 wiz Exp $

DISTNAME=	python_dotenv-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dotenv/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://github.com/theskumar/python-dotenv
COMMENT=	Add .env support to your django/flask apps
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=77.0:../../devel/py-setuptools
# cli
DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-sh>=2:../../sysutils/py-sh
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

# as of 1.2.2
# 1 failed, 215 passed, 1 skipped

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} dotenv dotenv-${PYVERSSUFFIX} || ${TRUE}

pre-test:
	${LN} -fs ${DESTDIR}${PREFIX}/bin/dotenv-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/dotenv

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
