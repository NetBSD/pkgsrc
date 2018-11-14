# $NetBSD: Makefile,v 1.79 2018/11/14 22:22:18 kleink Exp $

DISTNAME=	okular-16.08.0
PKGREVISION=	20
CATEGORIES=	print
COMMENT=	KDE universal document viewer
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.08.0/src/}

CFLAGS.SunOS+=	-D__EXTENSIONS__

BROKEN=		Needs poppler with qt4 support.

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/chmlib/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
#.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/libkactivities4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../graphics/kdegraphics-mobipocket/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
