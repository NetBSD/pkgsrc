# $NetBSD: Makefile,v 1.171 2026/01/07 08:48:36 wiz Exp $

DISTNAME=	okular-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	print

HOMEPAGE=	https://kde.org/applications/graphics/okular/
COMMENT=	KDE universal document viewer
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=5.19.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

GCC_REQD+=	8 # std::optional

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/generators/*/CMakeFiles/okularGenerator_*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/CMakeFiles/okularpart_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/chmlib/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../devel/kf6-kpty/buildlink3.mk"
.include "../../devel/kf6-purpose/buildlink3.mk"
.include "../../devel/kf6-threadweaver/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kdegraphics-mobipocket/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../multimedia/phonon-qt6/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-qt6/buildlink3.mk"
.include "../../security/qca2-qt6/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/discount/buildlink3.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
