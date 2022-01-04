# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:51 wiz Exp $

DISTNAME=	gns3-gui-2.2.1
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gns3-gui/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://github.com/GNS3/gns3-gui
COMMENT=	GNS3 network simulator - Graphical user interface package
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-distro>=1.3.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-psutil>=2.2.1:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.6.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-raven>=5.23.0:../../www/py-raven
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

# we have newer jsonschema and it seems fine
SUBST_CLASSES+=		inst
SUBST_STAGE.inst=	pre-configure
SUBST_FILES.inst=	requirements.txt
SUBST_SED.inst=		-e "s:jsonschema==2.6.0:jsonschema:"

post-install:
	chmod go-w,a-x ${DESTDIR}${PREFIX}/${PYSITELIB}/gns3/ui/*.ui
	chmod go-w,a-x ${DESTDIR}${PREFIX}/${PYSITELIB}/gns3/modules/*/ui/*.ui

.include "../../lang/python/egg.mk"

.include "../../mk/bsd.pkg.mk"
