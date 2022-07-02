# $NetBSD: Makefile,v 1.241 2022/07/02 16:53:15 ryoon Exp $

DISTNAME=	wine-5.0.5
PKGREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	https://dl.winehq.org/wine/source/${PKGVERSION_NOREV:R}/
MASTER_SITES+=	http://mirrors.ibiblio.org/wine/source/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.winehq.org/
COMMENT=	Compatibility layer for running Microsoft Windows applications
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex gmake mktemp msgfmt perl pkg-config
GNU_CONFIGURE=	yes

REPLACE_PERL+=	tools/winemaker/winemaker
REPLACE_PERL+=	tools/winedump/function_grep.pl

CHECK_PIE_SUPPORTED=	no

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

UNLIMIT_RESOURCES=	datasize

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--without-capi
CONFIGURE_ARGS+=	--without-gphoto
CONFIGURE_ARGS+=	--without-gssapi
CONFIGURE_ARGS+=	--without-hal
# LDAP causes build failures on NetBSD 9.99.x and newer.
CONFIGURE_ARGS+=	--without-ldap
CONFIGURE_ARGS+=	--without-krb5
CONFIGURE_ARGS+=	--without-opencl
CONFIGURE_ARGS+=	--without-udev
CONFIGURE_ARGS+=	--without-v4l2
CONFIGURE_ARGS+=	--without-vkd3d
CONFIGURE_ARGS+=	--without-vulkan

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		desktop lp32 lp64 oss

.if ${MACHINE_ARCH} == "x86_64"
PLIST.lp64=		yes
CONFIGURE_ARGS+=	--enable-win64
NOT_PAX_MPROTECT_SAFE+=	bin/wine64
.else
PLIST.lp32=		yes
NOT_PAX_MPROTECT_SAFE+=	bin/wine
.endif

.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} < 090000
# Disable new_dtags as NetBSD versions prior to 9.0 don't honor DT_RUNPATH
CONFIGURE_ENV+=		ac_cv_cflags__Wl___enable_new_dtags=no
.  endif
# gethostbyname_r is in libc, but has a different calling convention
CONFIGURE_ENV+=		wine_cv_linux_gethostbyname_r_6=no
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
PLIST.oss=		yes
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	dlls/wineoss.drv/mmdevdrv.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.else
CONFIGURE_ARGS+=	--without-oss
.endif

# Fix warning due to _FORTIFY_SOURCE being redefined
CONFIGURE_ENV+=		ac_cv_c_fortify_enabled=no

# Wine will use system frameworks on Darwin.
.if ${OPSYS} != "Darwin"
PLIST.desktop=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.endif

.include "options.mk"
.include "../../audio/faudio/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
