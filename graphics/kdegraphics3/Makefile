# $NetBSD: Makefile,v 1.49 2005/09/29 10:24:59 adam Exp $

DISTNAME=	kdegraphics-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_DIRS+=		xdg-1.1

BUILDLINK_DEPENDS.lcms=	lcms>=1.12

REPLACE_PERL=	kghostview/update-to-xt-names.pl

CONFIGURE_ARGS+=	--with-imlib-config=${X11PREFIX}/bin

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	"Fix includehints."
SUBST_FILES.hints=	ksnapshot/ksnapshotwidget.ui \
			kviewshell/pageSizeWidget_base.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
