# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:07 wiz Exp $

DISTNAME=	python-dotenv-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} dotenv dotenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
