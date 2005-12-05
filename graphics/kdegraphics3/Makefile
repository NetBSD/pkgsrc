# $NetBSD: Makefile,v 1.52 2005/12/05 20:50:21 rillig Exp $

DISTNAME=	kdegraphics-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gs:run

BUILDLINK_DEPENDS.lcms+=	lcms>=1.12

REPLACE_PERL=	kghostview/update-to-xt-names.pl

CONFIGURE_ARGS+=	--with-imlib-config=${X11PREFIX}/bin

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

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
.include "../../mk/bsd.pkg.mk"
