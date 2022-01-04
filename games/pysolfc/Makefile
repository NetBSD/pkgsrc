# $NetBSD: Makefile,v 1.38 2022/01/04 20:54:01 wiz Exp $

DISTNAME=	PySolFC-2.14.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysolfc/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pysolfc.sourceforge.io/
COMMENT=	Over 1000 solitaire games
LICENSE=	gnu-gpl-v3

CARDSETS_NAME=	PySolFC-Cardsets-2.0
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	${CARDSETS_NAME}.tar.bz2

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-pysol_cards-[0-9]*:../../games/py-pysol_cards
DEPENDS+=	${PYPKGPREFIX}-random2-[0-9]*:../../devel/py-random2
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-kivy-[0-9]*:../../devel/py-kivy
TEST_DEPENDS+=	${PYPKGPREFIX}-pycotap-[0-9]*:../../devel/py-pycotap
# not listed in setup.py, but needed
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_TOOLS+=	pax

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	pre-configure
SUBST_MESSAGE.datadir=	Use custom data dir.
SUBST_FILES.datadir=	pysollib/settings.py
SUBST_SED.datadir=	-e 's,@DATADIR@,${PREFIX}/share/PySolFC,'

INSTALLATION_DIRS+=	${PKGMANDIR}/man6

PLIST_SRC=	PLIST ${WRKDIR}/PLIST.CS
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

EGG_NAME=	${DISTNAME}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/pysol.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/pysol.py.6
	${INSTALL_MAN} ${WRKSRC}/docs/pysolfc.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/pysolfc.6
	cd ${WRKDIR}/${CARDSETS_NAME} && \
	${PAX} -rw . ${DESTDIR}${PREFIX}/share/PySolFC/ && \
	${FIND} . -type f -print | ${SED} -e 's,^\.,share/PySolFC,' > ${WRKDIR}/PLIST.CS

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
