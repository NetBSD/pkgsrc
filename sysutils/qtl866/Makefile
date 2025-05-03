# $NetBSD: Makefile,v 1.2 2025/05/03 07:38:18 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVER}
PKGVER=		0.3.0.53
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wd5gnr/}
GITHUB_PROJECT=	qtl866
GITHUB_TAG=	1173c3e048c9b777611b379892f397dd5c64a261
EXTRACT_SUFX=	.zip

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://github.com/wd5gnr/qtl866/
COMMENT=	GUI driver for minipro EPROM/Device programmer software
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=	c++

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	minipro-[0-9]*:../../sysutils/minipro
DEPENDS+=	ghex-[0-9]*:../../editors/ghex
#DEPENDS+=	hexedit-[0-9]*:../../editors/hexedit

# Since we do not have bless in pkgsrc
HEXEDIT=	ghex

REPLACE_SH=	binhexedit miniprohex

ICONDIR=		share/icons/hicolor/scalable/apps
DOCDIR=			share/doc/qtl866

INSTALLATION_DIRS+=	bin share/applications ${DOCDIR} ${ICONDIR}

SUBST_CLASSES=		hexedit
SUBST_STAGE.hexedit=	pre-configure
SUBST_MESSAGE.hexedit=	Setting hex editor
SUBST_FILES.hexedit=	binhexedit
SUBST_VARS.hexedit=	HEXEDIT

.include "../../mk/bsd.prefs.mk"

# Apparently, USE_TOOLS+=qmake is not a thing
pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/qmake

do-configure:
	cd ${WRKSRC} && qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtl866 ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/miniprohex ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/binhexedit ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qtl866.svg \
		${DESTDIR}${PREFIX}/${ICONDIR}/qtl866.svg
	${INSTALL_DATA} ${WRKSRC}/qtl866.desktop \
		${DESTDIR}${PREFIX}/share/applications/qtl866.desktop
.for ff in LICENSE README.md screenshot.png
	${INSTALL_DATA} ${WRKSRC}/${ff} \
		${DESTDIR}${PREFIX}/${DOCDIR}/${ff}
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
