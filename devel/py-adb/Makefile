# $NetBSD: Makefile,v 1.5 2023/05/02 17:12:21 wiz Exp $

DISTNAME=	adb-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/adb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/python-adb
COMMENT=	Pure Python implementation of the Android ADB and Fastboot protocols
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-libusb1>=1.0.16:../../devel/py-libusb1
DEPENDS+=	${PYPKGPREFIX}-rsa>=0:../../security/py-rsa

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pyadb ${DESTDIR}${PREFIX}/bin/pyadb-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/pyfastboot ${DESTDIR}${PREFIX}/bin/pyfastboot-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
