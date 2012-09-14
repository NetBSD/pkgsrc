# $NetBSD: Makefile,v 1.7 2012/09/14 12:19:31 drochner Exp $

DISTNAME=	okular-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	print
COMMENT=	KDE universal document viewer

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/chmlib/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
