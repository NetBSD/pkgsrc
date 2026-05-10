# $NetBSD: Makefile,v 1.35 2026/05/10 18:46:11 wiz Exp $

DISTNAME=	mcomix-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcomix/}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://mcomix.sourceforge.net/
COMMENT=	GTK+ comic book viewer
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.36.0:../../devel/py-gobject3

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

EXTRA_INSTALL+=	share/applications/mcomix.desktop
EXTRA_INSTALL+=	share/icons/hicolor/16x16/apps/mcomix.png
EXTRA_INSTALL+=	share/icons/hicolor/16x16/mimetypes/application-x-cbr.png
EXTRA_INSTALL+=	share/icons/hicolor/16x16/mimetypes/application-x-cbt.png
EXTRA_INSTALL+=	share/icons/hicolor/16x16/mimetypes/application-x-cbz.png
EXTRA_INSTALL+=	share/icons/hicolor/22x22/apps/mcomix.png
EXTRA_INSTALL+=	share/icons/hicolor/22x22/mimetypes/application-x-cbr.png
EXTRA_INSTALL+=	share/icons/hicolor/22x22/mimetypes/application-x-cbt.png
EXTRA_INSTALL+=	share/icons/hicolor/22x22/mimetypes/application-x-cbz.png
EXTRA_INSTALL+=	share/icons/hicolor/24x24/apps/mcomix.png
EXTRA_INSTALL+=	share/icons/hicolor/24x24/mimetypes/application-x-cbr.png
EXTRA_INSTALL+=	share/icons/hicolor/24x24/mimetypes/application-x-cbt.png
EXTRA_INSTALL+=	share/icons/hicolor/24x24/mimetypes/application-x-cbz.png
EXTRA_INSTALL+=	share/icons/hicolor/32x32/apps/mcomix.png
EXTRA_INSTALL+=	share/icons/hicolor/32x32/mimetypes/application-x-cbr.png
EXTRA_INSTALL+=	share/icons/hicolor/32x32/mimetypes/application-x-cbt.png
EXTRA_INSTALL+=	share/icons/hicolor/32x32/mimetypes/application-x-cbz.png
EXTRA_INSTALL+=	share/icons/hicolor/48x48/apps/mcomix.png
EXTRA_INSTALL+=	share/icons/hicolor/48x48/mimetypes/application-x-cbr.png
EXTRA_INSTALL+=	share/icons/hicolor/48x48/mimetypes/application-x-cbt.png
EXTRA_INSTALL+=	share/icons/hicolor/48x48/mimetypes/application-x-cbz.png
EXTRA_INSTALL+=	share/metainfo/mcomix.metainfo.xml
EXTRA_INSTALL+=	share/mime/packages/mcomix.xml

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/mimetypes
INSTALLATION_DIRS+=	share/icons/hicolor/22x22/apps
INSTALLATION_DIRS+=	share/icons/hicolor/22x22/mimetypes
INSTALLATION_DIRS+=	share/icons/hicolor/24x24/apps
INSTALLATION_DIRS+=	share/icons/hicolor/24x24/mimetypes
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/mimetypes
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/mimetypes
INSTALLATION_DIRS+=	share/metainfo
INSTALLATION_DIRS+=	share/mime/packages

post-install:
	zcat ${WRKSRC}/share/man/man1/mcomix.1.gz > ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mcomix.1
.for f in ${EXTRA_INSTALL}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${f}
.endfor

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
