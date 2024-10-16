# $NetBSD: Makefile,v 1.11 2024/10/16 02:15:01 markd Exp $

DISTNAME=	gns3-gui-2.2.49
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gns3-gui/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GNS3/gns3-gui
COMMENT=	GNS3 network simulator - Graphical user interface package
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-distro>=1.9.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-psutil>=6.0.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.23:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk>=2.12:../../devel/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-truststore>=0.9.1:../../security/py-truststore
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

USE_PKG_RESOURCES=	yes

post-install:
	chmod go-w,a-x ${DESTDIR}${PREFIX}/${PYSITELIB}/gns3/ui/*.ui
	chmod go-w,a-x ${DESTDIR}${PREFIX}/${PYSITELIB}/gns3/modules/*/ui/*.ui

.include "../../lang/python/egg.mk"

.include "../../mk/bsd.pkg.mk"
