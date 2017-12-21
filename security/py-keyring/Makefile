# $NetBSD: Makefile,v 1.21 2017/12/21 14:06:32 adam Exp $

DISTNAME=	keyring-10.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/keyring/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://github.com/jaraco/keyring
COMMENT=	Store and access your passwords safely
LICENSE=	python-software-foundation

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	keyring/cli.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} keyring keyring-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
