# $NetBSD: Makefile,v 1.1 2020/04/03 23:06:35 nia Exp $

DISTNAME=	adb-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/adb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/python-adb
COMMENT=	Pure Python implementation of the Android ADB and Fastboot protocols
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-libusb1>=1.0.16:../../devel/py-libusb1
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pyadb ${DESTDIR}${PREFIX}/bin/pyadb-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/pyfastboot ${DESTDIR}${PREFIX}/bin/pyfastboot-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
