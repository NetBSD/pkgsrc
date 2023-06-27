#	$NetBSD: pkgconfig.mk,v 1.1 2023/06/27 10:43:34 riastradh Exp $

# Fragment to be included by packages that use font-util and detect its
# parameters with pkg-config, so that they get the right paths in
# cross-builds.
#
# used-by fonts/font-adobe-100dpi/Makefile
# used-by fonts/font-adobe-75dpi/Makefile
# used-by fonts/font-adobe-utopia-100dpi/Makefile
# used-by fonts/font-adobe-utopia-75dpi/Makefile
# used-by fonts/font-bh-100dpi/Makefile
# used-by fonts/font-bh-75dpi/Makefile
# used-by fonts/font-bh-lucidatypewriter-100dpi/Makefile
# used-by fonts/font-bh-lucidatypewriter-75dpi/Makefile
# used-by fonts/font-misc-misc/Makefile

USE_TOOLS+=	pkg-config

.include "../../mk/bsd.fast.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
# Set PKG_CONFIG_SYSROOT_DIR so that configure can find MAPFILES_PATH
# from `pkg-config --variable=mapdir fontutil' and read files under it
# at build-time.  There is no way to set it explicitly -- it is only
# discovered through pkg-config.
CONFIGURE_ENV+=		PKG_CONFIG_SYSROOT_DIR=${_CROSS_DESTDIR:Q}

# Set FONTROOTDIR explicitly to override the default of `pkg-config
# --variable=fontrootdir fontutil' which, with PKG_CONFIG_SYSROOT_DIR
# set, includes the cross-destdir, which is wrong, because the build
# treats this as relative to the destdir.
CONFIGURE_ARGS+=	--with-fontrootdir=${LOCALBASE:Q}/share/fonts/X11
.endif

.include "../../fonts/font-util/buildlink3.mk"
