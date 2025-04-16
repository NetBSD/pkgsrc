# $NetBSD: Makefile,v 1.46 2025/04/16 20:47:34 adam Exp $

DISTNAME=	PySolFC-3.2.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysolfc/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pysolfc.sourceforge.io/
COMMENT=	Over 1000 solitaire games
LICENSE=	gnu-gpl-v3

CARDSETS_NAME=	PySolFC-Cardsets-3.0
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	${CARDSETS_NAME}.tar.bz2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs>=18.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-pysol_cards-[0-9]*:../../games/py-pysol_cards
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
# not listed in setup.py, but needed
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.4:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-kivy-[0-9]*:../../devel/py-kivy
TEST_DEPENDS+=	${PYPKGPREFIX}-pycotap-[0-9]*:../../devel/py-pycotap

USE_TOOLS+=	pax

WHEEL_NAME=	${DISTNAME:tl}

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	pre-configure
SUBST_MESSAGE.datadir=	Use custom data dir.
SUBST_FILES.datadir=	pysollib/settings.py
SUBST_SED.datadir=	-e 's,@DATADIR@,${PREFIX}/share/PySolFC,'

INSTALLATION_DIRS+=	${PKGMANDIR}/man6 share/PySolFC

PLIST_SRC=	PLIST ${WRKDIR}/PLIST.CS
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

pre-install:
	cd ${WRKDIR}/${CARDSETS_NAME} && \
	${PAX} -rw . ${DESTDIR}${PREFIX}/share/PySolFC/ && \
	${FIND} . -type f -print | ${SED} -e 's,^\.,share/PySolFC,' > ${WRKDIR}/PLIST.CS

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/pysol.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/pysol.py.6
	${INSTALL_MAN} ${WRKSRC}/docs/pysolfc.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/pysolfc.6

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
