# $NetBSD: emulator.mk,v 1.1 2022/10/02 17:17:19 wiz Exp $
#
# This file is included by linux-suse.mk in the emulator framework.
#
# Variables set by this file:
#
# EMUL_DISTRO
#	The SuSE Linux distribution.
#
# DEPENDS_${EMUL_DISTRO}.*
#	A table that maps "modules" to SuSE package dependencies.
#

EMUL_DISTRO=		suse-15.5

.if defined(SUSE_PKG)
_SUSE_VERSION_REQD=	-15.5{,nb*}
.else
_SUSE_VERSION_REQD=	>=15.5<15.6
.endif

# DEPENDS_suse-15.5.* maps Linux "modules" to SuSE package dependencies.
DEPENDS_suse-15.5.alsa?=	suse_alsa${_SUSE_VERSION_REQD}:../../emulators/suse15_alsa
DEPENDS_suse-15.5.base?=	suse_base${_SUSE_VERSION_REQD}:../../emulators/suse15_base
DEPENDS_suse-15.5.binutils?=	suse_binutils${_SUSE_VERSION_REQD}:../../emulators/suse15_binutils
DEPENDS_suse-15.5.dbus?=	suse_libdbus${_SUSE_VERSION_REQD}:../../emulators/suse15_libdbus
DEPENDS_suse-15.5.drm?=		suse_libdrm${_SUSE_VERSION_REQD}:../../emulators/suse15_libdrm
DEPENDS_suse-15.5.expat?=	suse_expat${_SUSE_VERSION_REQD}:../../emulators/suse15_expat
DEPENDS_suse-15.5.fontconfig?=	suse_fontconfig${_SUSE_VERSION_REQD}:../../emulators/suse15_fontconfig
DEPENDS_suse-15.5.freetype2?=	suse_freetype2${_SUSE_VERSION_REQD}:../../emulators/suse15_freetype2
DEPENDS_suse-15.5.glib2?=	suse_glib2${_SUSE_VERSION_REQD}:../../emulators/suse15_glib2
DEPENDS_suse-15.5.glx?=		suse_glx${_SUSE_VERSION_REQD}:../../emulators/suse15_glx
DEPENDS_suse-15.5.gtk3?=	suse_gtk3${_SUSE_VERSION_REQD}:../../emulators/suse15_gtk3
DEPENDS_suse-15.5.jpeg?=	suse_libjpeg${_SUSE_VERSION_REQD}:../../emulators/suse15_libjpeg
DEPENDS_suse-15.5.libffi?=	suse_libffi${_SUSE_VERSION_REQD}:../../emulators/suse15_libffi
DEPENDS_suse-15.5.libsndfile?=	suse_libsndfile${_SUSE_VERSION_REQD}:../../emulators/suse15_libsndfile
DEPENDS_suse-15.5.libsystemd?=	suse_libsystemd${_SUSE_VERSION_REQD}:../../emulators/suse15_libsystemd
DEPENDS_suse-15.5.locale?=	suse_locale${_SUSE_VERSION_REQD}:../../emulators/suse15_locale
DEPENDS_suse-15.5.openssl?=	suse_openssl${_SUSE_VERSION_REQD}:../../emulators/suse15_openssl
DEPENDS_suse-15.5.png?=		suse_libpng${_SUSE_VERSION_REQD}:../../emulators/suse15_libpng
DEPENDS_suse-15.5.pulseaudio?=	suse_pulseaudio${_SUSE_VERSION_REQD}:../../emulators/suse15_pulseaudio
DEPENDS_suse-15.5.tiff?=	suse_libtiff${_SUSE_VERSION_REQD}:../../emulators/suse15_libtiff
DEPENDS_suse-15.5.x11?=		suse_x11${_SUSE_VERSION_REQD}:../../emulators/suse15_x11
DEPENDS_suse-15.5.xml2?=	suse_libxml2${_SUSE_VERSION_REQD}:../../emulators/suse15_libxml2

.if (${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_suse-15.5.${_mod_}:=	\
	${DEPENDS_suse-15.5.${_mod_}:S/^suse_/suse32_/:S/suse15_/&32_/}
.  endfor
.endif

# SuSE Linux's ld.so(8) uses a cache file of search paths for shared
# libraries which is managed by ldconfig(8).
#
.if !defined(EMUL_IS_NATIVE)
SUSE_LDCONFIG_CMD=	${EMULDIR}/sbin/ldconfig -r ${EMULDIR}
LDCONFIG_ADD_CMD?=	${SUSE_LDCONFIG_CMD}
LDCONFIG_REMOVE_CMD?=	${SUSE_LDCONFIG_CMD}
.endif
