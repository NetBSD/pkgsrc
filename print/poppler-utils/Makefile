# $NetBSD: Makefile,v 1.69 2024/08/25 06:19:11 wiz Exp $

USE_CXX_FEATURES+=	filesystem
PKGREVISION= 1
.include "../../print/poppler/Makefile.common"

PKGNAME=	poppler-utils-${POPPLER_VERS}
COMMENT=	PDF utilities (from poppler)

CONFLICTS+=	poppler-0.5.1{,nb*}
CONFLICTS+=	xpdf<3.02pl4nb1

# for pdfsig
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NSS3:BOOL=ON

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
# Don't build libcurl based HTTP support. ## might want to include
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LIBCURL=OFF

BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"

INSTALL_DIRS=		utils

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		PTHREAD_STUBLIB=

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
