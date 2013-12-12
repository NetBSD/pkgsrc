# $NetBSD: emulator.mk,v 1.2 2013/12/12 02:34:28 obache Exp $
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

EMUL_DISTRO=		suse-12.1

.if defined(SUSE_PKG)
_SUSE_VERSION_REQD=	-12.1{,nb*}
.else
_SUSE_VERSION_REQD=	>=12.1<12.2
.endif

# DEPENDS_suse-12.1.* maps Linux "modules" to SuSE package dependencies.
DEPENDS_suse-12.1.alsa?=	suse_alsa${_SUSE_VERSION_REQD}:../../emulators/suse121_alsa
DEPENDS_suse-12.1.aspell?=	suse_aspell${_SUSE_VERSION_REQD}:../../emulators/suse121_aspell
DEPENDS_suse-12.1.base?=	suse_base${_SUSE_VERSION_REQD}:../../emulators/suse121_base
DEPENDS_suse-12.1.compat?=	suse_compat${_SUSE_VERSION_REQD}:../../emulators/suse121_compat
DEPENDS_suse-12.1.cups?=	suse_libcups${_SUSE_VERSION_REQD}:../../emulators/suse121_libcups
DEPENDS_suse-12.1.curl?=	suse_libcurl${_SUSE_VERSION_REQD}:../../emulators/suse121_libcurl
DEPENDS_suse-12.1.drm?=		suse_libdrm${_SUSE_VERSION_REQD}:../../emulators/suse121_libdrm
DEPENDS_suse-12.1.expat?=	suse_expat${_SUSE_VERSION_REQD}:../../emulators/suse121_expat
DEPENDS_suse-12.1.fontconfig?=	suse_fontconfig${_SUSE_VERSION_REQD}:../../emulators/suse121_fontconfig
DEPENDS_suse-12.1.freetype2?=	suse_freetype2${_SUSE_VERSION_REQD}:../../emulators/suse121_freetype2
DEPENDS_suse-12.1.glx?=		suse_glx${_SUSE_VERSION_REQD}:../../emulators/suse121_glx
DEPENDS_suse-12.1.gtk2?=	suse_gtk2${_SUSE_VERSION_REQD}:../../emulators/suse121_gtk2
DEPENDS_suse-12.1.jpeg?=	suse_libjpeg${_SUSE_VERSION_REQD}:../../emulators/suse121_libjpeg
DEPENDS_suse-12.1.krb5?=	suse_krb5${_SUSE_VERSION_REQD}:../../emulators/suse121_krb5
DEPENDS_suse-12.1.libsigc++2?=	suse_libsigc++2${_SUSE_VERSION_REQD}:../../emulators/suse121_libsigc++2
DEPENDS_suse-12.1.locale?=	suse_locale${_SUSE_VERSION_REQD}:../../emulators/suse121_locale
DEPENDS_suse-12.1.motif?=	suse_openmotif${_SUSE_VERSION_REQD}:../../emulators/suse121_openmotif
DEPENDS_suse-12.1.nss?=		${DEPENDS_suse-12.1.base}
DEPENDS_suse-12.1.nspr?=	${DEPENDS_suse-12.1.base}
DEPENDS_suse-12.1.openssl?=	suse_openssl${_SUSE_VERSION_REQD}:../../emulators/suse121_openssl
DEPENDS_suse-12.1.png?=		suse_libpng${_SUSE_VERSION_REQD}:../../emulators/suse121_libpng
DEPENDS_suse-12.1.qt4?=		suse_qt4${_SUSE_VERSION_REQD}:../../emulators/suse121_qt4
DEPENDS_suse-12.1.slang?=	suse_slang${_SUSE_VERSION_REQD}:../../emulators/suse121_slang
DEPENDS_suse-12.1.tiff?=	suse_libtiff${_SUSE_VERSION_REQD}:../../emulators/suse121_libtiff
DEPENDS_suse-12.1.x11?=		suse_x11${_SUSE_VERSION_REQD}:../../emulators/suse121_x11
DEPENDS_suse-12.1.xml2?=	suse_libxml2${_SUSE_VERSION_REQD}:../../emulators/suse121_libxml2

.if (${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_suse-12.1.${_mod_}:=	\
	${DEPENDS_suse-12.1.${_mod_}:S/^suse_/suse32_/:S/suse121_/&32_/}
.  endfor
.endif
