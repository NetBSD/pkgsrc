# $NetBSD: Makefile,v 1.53 2016/03/05 11:28:41 jperkin Exp $

DISTNAME=		veusz-1.21
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://download.gna.org/veusz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/veusz/
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
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
