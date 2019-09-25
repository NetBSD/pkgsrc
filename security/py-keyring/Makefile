# $NetBSD: Makefile,v 1.25 2019/09/25 13:06:12 adam Exp $

DISTNAME=	keyring-19.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/keyring/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://github.com/jaraco/keyring
COMMENT=	Store and access your passwords safely
LICENSE=	python-software-foundation

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-entrypoints-[0-9]*:../../devel/py-entrypoints
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.7.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	keyring/cli.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} keyring keyring-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
