# $NetBSD: Makefile,v 1.74 2025/03/12 09:35:45 wiz Exp $

PKGNAME=	poppler-utils-${POPPLER_VERS}
PKGREVISION=	4
COMMENT=	PDF utilities (from poppler)

CONFLICTS+=	poppler-0.5.1{,nb*}
CONFLICTS+=	xpdf<3.02pl4nb1

# Don't compile GTK+ test program.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GTK_TESTS=OFF
# Don't compile GLib wrapper which also needs gtk2
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GLIB=OFF
# Build and install the tools
CMAKE_CONFIGURE_ARGS+=	-DENABLE_UTILS=ON
# Don't compile poppler cpp wrapper.
CMAKE_CONFIGURE_ARGS+=	-DENABLE_CPP=OFF
# Don't compile poppler qt5/6 wrapper.
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT5=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT6=OFF

BUILD_DIRS=		utils
.include "../../print/poppler/Makefile.common"
USE_CXX_FEATURES+=	filesystem

BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
# for nss support for pdfsig - remove on next update
BUILDLINK_API_DEPENDS.poppler+=     poppler>=24.10.0nb5
.include "../../print/poppler/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		PTHREAD_STUBLIB=

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
