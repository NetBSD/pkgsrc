# $NetBSD: Makefile,v 1.93 2011/08/10 17:43:57 dholland Exp $

DISTNAME=	cairo-1.10.2
# note: PKGREVISION of 2 was used briefly in Feb 2011; next bump should use 3.
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cairographics.org/
COMMENT=	Vector graphics library with cross-device output support
LICENSE=	gnu-lgpl-v2.1 AND mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c99
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	src/cairo.pc.in src/cairo-features.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gl
CONFIGURE_ARGS+=	--enable-pdf
CONFIGURE_ARGS+=	--enable-ps

PLIST_VARS+=		carbon
.if exists(/System/Library/Frameworks/Carbon.framework)
CONFIGURE_ARGS+=	--enable-quartz
CONFIGURE_ARGS+=	--enable-quartz-font
CONFIGURE_ARGS+=	--enable-quartz-image
PLIST.carbon=		yes
.endif

.include "options.mk"

# For snprintf() and ctime_r()
CPPFLAGS.SunOS+=		-D__EXTENSIONS__ -D_POSIX_PTHREAD_SEMANTICS

TEST_TARGET=			check

# PR#43928
.include "../../mk/compiler.mk"
.if ${MACHINE_PLATFORM:MDragonFly-*-x86_64} && ${CC_VERSION:Mgcc-4.1.*}
CONFIGURE_ENV+=		ac_cv_type___uint128_t=no
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.9
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# include?
#.include "../../print/libspectre/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
