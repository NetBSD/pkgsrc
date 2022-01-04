# $NetBSD: Makefile,v 1.3 2022/01/04 20:52:48 wiz Exp $

DISTNAME=	adb-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/adb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/python-adb
COMMENT=	Pure Python implementation of the Android ADB and Fastboot protocols
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-libusb1>=1.0.16:../../devel/py-libusb1

PYTHON_VERSIONED_DEPENDENCIES+=	rsa

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pyadb ${DESTDIR}${PREFIX}/bin/pyadb-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/pyfastboot ${DESTDIR}${PREFIX}/bin/pyfastboot-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
