# $NetBSD: Makefile,v 1.29 2011/08/13 04:43:51 cheusov Exp $
#

DISTNAME=	xawtv-3.95
PKGREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://dl.bytesex.org/releases/xawtv/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.bytesex.org/xawtv/
COMMENT=	TV application for Brooktree 848 compatible cards

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl bash:run

REPLACE_BASH=		scripts/subtitles

CONFIGURE_ARGS+=	--disable-aalib
CONFIGURE_ARGS+=	--disable-motif

LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	Fixing path to OSS audio device.
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	console/record.c libng/devices.c x11/pia.c
SUBST_FILES.devoss+=	man/motv.1 man/record.1 man/streamer.1 man/xawtv.1
SUBST_FILES.devoss+=	man/es/streamer.1 man/es/xawtv.1 man/fr/xawtv.1
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
PKG_OPTIONS_VAR=	PKG_OPTIONS.xawtv
PKG_SUPPORTED_OPTIONS=	mmx
.include "../../mk/bsd.options.mk"
.endif

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif

CFLAGS+=		-I${X11BASE}/include/X11/fonts

MAKE_FLAGS+=		SUID_ROOT= FS_LIBS=-lFS

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
