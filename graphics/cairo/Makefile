# $NetBSD: Makefile,v 1.160 2023/11/26 18:45:03 schmonz Exp $

DISTNAME=	cairo-1.18.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cairographics.org/
COMMENT=	Vector graphics library with cross-device output support
LICENSE=	gnu-lgpl-v2.1 AND mpl-1.1

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=		gnu99
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

# For snprintf() and ctime_r()
CPPFLAGS.SunOS+=	-D__EXTENSIONS__ -D_POSIX_PTHREAD_SEMANTICS
LDFLAGS.SunOS+=		-lsocket

MESON_ARGS+=		-Dfreetype=enabled
MESON_ARGS+=		-Dfontconfig=enabled

PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE+=		output/meson-private/*.pc

SUPERSEDES+=	cairo-gobject-[0-9]*

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

# see meson.build for systems that support cairo-trace
PLIST_VARS+=	trace
.if ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
PLIST.trace=	yes
.endif

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../archivers/lzo/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=   glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# include?
#.include "../../print/libspectre/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.36.0
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
