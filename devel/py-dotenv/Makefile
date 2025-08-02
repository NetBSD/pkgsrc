# $NetBSD: Makefile,v 1.19 2025/08/02 09:40:57 adam Exp $

DISTNAME=	python_dotenv-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dotenv/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://github.com/theskumar/python-dotenv
COMMENT=	Add .env support to your django/flask apps
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
# cli
DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-sh>=2:../../sysutils/py-sh
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} dotenv dotenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
