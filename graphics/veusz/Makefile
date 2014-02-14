# $NetBSD: Makefile,v 1.49 2014/02/14 17:26:15 drochner Exp $
#

DISTNAME=		veusz-1.20.1
CATEGORIES=		graphics
MASTER_SITES=		http://download.gna.org/veusz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/veusz/
COMMENT=		Scientific plotting package
LICENSE=		gnu-gpl-v2

PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

REPLACE_PYTHON=		examples/embedexample.py

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/support/veusz.xml \
		${DESTDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/support/veusz.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/veusz.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	for s in 16 32 48 64 128;do \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/$${s}x$${s}/apps; \
		${INSTALL_DATA} ${WRKSRC}/icons/veusz_$${s}.png \
			${DESTDIR}${PREFIX}/share/icons/hicolor/$${s}x$${s}/apps/veusz.png; \
	done

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
