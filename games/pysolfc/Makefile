# $NetBSD: Makefile,v 1.28 2019/06/06 21:53:44 adam Exp $

DISTNAME=	PySolFC-2.6.4
PKGNAME=	${DISTNAME:tl}
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

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game

USE_TOOLS+=	pax

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	pre-configure
SUBST_MESSAGE.datadir=	Use custom data dir.
SUBST_FILES.datadir=	pysollib/settings.py
SUBST_SED.datadir=	-e 's,@DATADIR@,${PREFIX}/share/PySolFC,'

INSTALLATION_DIRS+=	${PKGMANDIR}/man6

PLIST_SRC=	PLIST ${WRKDIR}/PLIST.CS

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/pysol.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/pysol.py.6
	${INSTALL_MAN} ${WRKSRC}/docs/pysolfc.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/pysolfc.6
	cd ${WRKDIR}/${CARDSETS_NAME} && \
	${PAX} -rw . ${DESTDIR}${PREFIX}/share/PySolFC/ && \
	${FIND} . -type f -print | ${SED} -e 's,^\.,share/PySolFC,' > ${WRKDIR}/PLIST.CS

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
