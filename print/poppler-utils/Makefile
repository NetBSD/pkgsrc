# $NetBSD: Makefile,v 1.40 2018/09/01 20:52:24 bsiegert Exp $

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-utils-${POPPLER_VERS}
COMMENT=		PDF utilities (from poppler)
MAINTAINER=		reed@reedmedia.net

CONFLICTS+=		poppler-0.5.1 poppler-0.5.1nb1 poppler-0.5.1nb2
CONFLICTS+=		xpdf<3.02pl4nb1

# Build the splash graphics backend. ## for pdftoppm
CMAKE_ARGS+=    -DENABLE_SPLASH=ON
# Don't compile GTK+ test program.
CMAKE_ARGS+=    -DBUILD_GTK_TESTS=OFF
# Don't compile GLib wrapper which also needs gtk2
CMAKE_ARGS+=    -DENABLE_GLIB=OFF
# Build and install the tools
CMAKE_ARGS+=    -DENABLE_UTILS=ON
# Don't compile poppler cpp wrapper.
CMAKE_ARGS+=    -DENABLE_CPP=OFF
# Don't compile poppler qt5 wrapper.
CMAKE_ARGS+=    -DENABLE_QT5=OFF
# Don't build libcurl based HTTP support. ## might want to include
CMAKE_ARGS+=    -DENABLE_LIBCURL=OFF


BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"

INSTALL_DIRS=		utils

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		PTHREAD_STUBLIB=

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
