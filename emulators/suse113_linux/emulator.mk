# $NetBSD: emulator.mk,v 1.5 2011/12/29 22:17:20 wiz Exp $
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

EMUL_DISTRO=		suse-11.3

.if defined(SUSE_PKG)
_SUSE_VERSION_REQD=	-11.3{,nb*}
.else
_SUSE_VERSION_REQD=	>=11.3<11.4
.endif

# DEPENDS_suse-11.3.* maps Linux "modules" to SuSE package dependencies.
DEPENDS_suse-11.3.alsa?=	suse_alsa${_SUSE_VERSION_REQD}:../../emulators/suse113_alsa
DEPENDS_suse-11.3.aspell?=	suse_aspell${_SUSE_VERSION_REQD}:../../emulators/suse113_aspell
DEPENDS_suse-11.3.base?=	suse_base${_SUSE_VERSION_REQD}:../../emulators/suse113_base
DEPENDS_suse-11.3.compat?=	suse_compat${_SUSE_VERSION_REQD}:../../emulators/suse113_compat
DEPENDS_suse-11.3.cups?=	suse_libcups${_SUSE_VERSION_REQD}:../../emulators/suse113_libcups
DEPENDS_suse-11.3.curl?=	suse_libcurl${_SUSE_VERSION_REQD}:../../emulators/suse113_libcurl
DEPENDS_suse-11.3.drm?=		suse_libdrm${_SUSE_VERSION_REQD}:../../emulators/suse113_libdrm
DEPENDS_suse-11.3.expat?=	suse_expat${_SUSE_VERSION_REQD}:../../emulators/suse113_expat
DEPENDS_suse-11.3.fontconfig?=	suse_fontconfig${_SUSE_VERSION_REQD}:../../emulators/suse113_fontconfig
DEPENDS_suse-11.3.freetype2?=	suse_freetype2${_SUSE_VERSION_REQD}:../../emulators/suse113_freetype2
DEPENDS_suse-11.3.glx?=		suse_glx${_SUSE_VERSION_REQD}:../../emulators/suse113_glx
DEPENDS_suse-11.3.gtk2?=	suse_gtk2${_SUSE_VERSION_REQD}:../../emulators/suse113_gtk2
DEPENDS_suse-11.3.jpeg?=	suse_libjpeg${_SUSE_VERSION_REQD}:../../emulators/suse113_libjpeg
DEPENDS_suse-11.3.krb5?=	suse_krb5${_SUSE_VERSION_REQD}:../../emulators/suse113_krb5
DEPENDS_suse-11.3.libsigc++2?=	suse_libsigc++2${_SUSE_VERSION_REQD}:../../emulators/suse113_libsigc++2
DEPENDS_suse-11.3.locale?=	suse_locale${_SUSE_VERSION_REQD}:../../emulators/suse113_locale
DEPENDS_suse-11.3.motif?=	suse_openmotif${_SUSE_VERSION_REQD}:../../emulators/suse113_openmotif
DEPENDS_suse-11.3.openssl?=	suse_openssl${_SUSE_VERSION_REQD}:../../emulators/suse113_openssl
DEPENDS_suse-11.3.png?=		suse_libpng${_SUSE_VERSION_REQD}:../../emulators/suse113_libpng
DEPENDS_suse-11.3.qt4?=		suse_qt4${_SUSE_VERSION_REQD}:../../emulators/suse113_qt4
DEPENDS_suse-11.3.slang?=	suse_slang${_SUSE_VERSION_REQD}:../../emulators/suse113_slang
DEPENDS_suse-11.3.tiff?=	suse_libtiff${_SUSE_VERSION_REQD}:../../emulators/suse113_libtiff
DEPENDS_suse-11.3.vmware?=	suse_vmware${_SUSE_VERSION_REQD}:../../emulators/suse113_vmware
DEPENDS_suse-11.3.x11?=		suse_x11${_SUSE_VERSION_REQD}:../../emulators/suse113_x11
DEPENDS_suse-11.3.xml2?=	suse_libxml2${_SUSE_VERSION_REQD}:../../emulators/suse113_libxml2

.if (${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_suse-11.3.${_mod_}:=	\
	${DEPENDS_suse-11.3.${_mod_}:S/^suse_/suse32_/:S/suse113_/&32_/}
.  endfor
.endif
