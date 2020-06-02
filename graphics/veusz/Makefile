# $NetBSD: Makefile,v 1.65 2020/06/02 08:24:08 adam Exp $

DISTNAME=		veusz-3.1
PKGREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=veusz/}
GITHUB_RELEASE=		${DISTNAME}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://veusz.github.io/
COMMENT=		Scientific plotting package
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++

REPLACE_PYTHON+=	examples/embedexample.py
REPLACE_PYTHON+=	veusz/veusz_listen.py
REPLACE_PYTHON+=	veusz/veusz_main.py

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/64x64/apps
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
INSTALLATION_DIRS+=	share/mime/packages

ALL_ENV+=		QMAKE_EXE=${QTDIR}/bin/qmake
ALL_ENV+=		SIP_DIR=${PREFIX}/share/sip${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/support/veusz.desktop \
		${DESTDIR}${PREFIX}/share/applications
	for s in 16 32 48 64 128;do \
		${INSTALL_DATA} ${WRKSRC}/icons/veusz_$${s}.png \
			${DESTDIR}${PREFIX}/share/icons/hicolor/$${s}x$${s}/apps/veusz.png; \
	done
	${INSTALL_DATA} ${WRKSRC}/icons/veusz.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/support/veusz.xml \
		${DESTDIR}${PREFIX}/share/mime/packages

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
