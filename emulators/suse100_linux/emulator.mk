# $NetBSD: emulator.mk,v 1.7 2011/09/12 11:34:08 joerg Exp $
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

EMUL_DISTRO=		suse-10.0

.if defined(SUSE_PKG)
_SUSE_VERSION_REQD=	-10.0{,nb*}
.else
_SUSE_VERSION_REQD=	>=10.0<10.1
.endif

# DEPENDS_suse-10.0.* maps Linux "modules" to SuSE package dependencies.
DEPENDS_suse-10.0.alsa?=	suse_alsa${_SUSE_VERSION_REQD}:../../emulators/suse100_alsa
DEPENDS_suse-10.0.aspell?=	suse_aspell${_SUSE_VERSION_REQD}:../../emulators/suse100_aspell
DEPENDS_suse-10.0.base?=	suse_base${_SUSE_VERSION_REQD}:../../emulators/suse100_base
DEPENDS_suse-10.0.compat?=	suse_compat${_SUSE_VERSION_REQD}:../../emulators/suse100_compat
DEPENDS_suse-10.0.cups?=	suse_libcups${_SUSE_VERSION_REQD}:../../emulators/suse100_libcups
DEPENDS_suse-10.0.expat?=	suse_expat${_SUSE_VERSION_REQD}:../../emulators/suse100_expat
DEPENDS_suse-10.0.fontconfig?=	suse_fontconfig${_SUSE_VERSION_REQD}:../../emulators/suse100_fontconfig
DEPENDS_suse-10.0.freetype2?=	suse_freetype2${_SUSE_VERSION_REQD}:../../emulators/suse100_freetype2
DEPENDS_suse-10.0.gdk-pixbuf?=	suse_gdk-pixbuf${_SUSE_VERSION_REQD}:../../emulators/suse100_gdk-pixbuf
DEPENDS_suse-10.0.glx?=	suse_glx${_SUSE_VERSION_REQD}:../../emulators/suse100_glx
DEPENDS_suse-10.0.gtk?=	suse_gtk${_SUSE_VERSION_REQD}:../../emulators/suse100_gtk
DEPENDS_suse-10.0.gtk2?=	suse_gtk2${_SUSE_VERSION_REQD}:../../emulators/suse100_gtk2
DEPENDS_suse-10.0.jpeg?=	suse_libjpeg${_SUSE_VERSION_REQD}:../../emulators/suse100_libjpeg
DEPENDS_suse-10.0.krb5?=	suse_krb5${_SUSE_VERSION_REQD}:../../emulators/suse100_krb5
DEPENDS_suse-10.0.libsigc++2?=	suse_libsigc++2${_SUSE_VERSION_REQD}:../../emulators/suse100_libsigc++2
DEPENDS_suse-10.0.locale?=	suse_locale${_SUSE_VERSION_REQD}:../../emulators/suse100_locale
DEPENDS_suse-10.0.motif?=	suse_openmotif${_SUSE_VERSION_REQD}:../../emulators/suse100_openmotif
DEPENDS_suse-10.0.openssl?=	suse_openssl${_SUSE_VERSION_REQD}:../../emulators/suse100_openssl
DEPENDS_suse-10.0.png?=	suse_libpng${_SUSE_VERSION_REQD}:../../emulators/suse100_libpng
DEPENDS_suse-10.0.qt3?=		suse_qt3${_SUSE_VERSION_REQD}:../../emulators/suse100_qt3
DEPENDS_suse-10.0.resmgr?=	suse_resmgr${_SUSE_VERSION_REQD}:../../emulators/suse100_resmgr
DEPENDS_suse-10.0.slang?=	suse_slang${_SUSE_VERSION_REQD}:../../emulators/suse100_slang
DEPENDS_suse-10.0.tiff?=	suse_libtiff${_SUSE_VERSION_REQD}:../../emulators/suse100_libtiff
DEPENDS_suse-10.0.vmware?=	suse_vmware${_SUSE_VERSION_REQD}:../../emulators/suse100_vmware
DEPENDS_suse-10.0.x11?=	suse_x11${_SUSE_VERSION_REQD}:../../emulators/suse100_x11
DEPENDS_suse-10.0.xml2?=	suse_libxml2${_SUSE_VERSION_REQD}:../../emulators/suse100_libxml2

.if (${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_suse-10.0.${_mod_}:=	\
	${DEPENDS_suse-10.0.${_mod_}:S/^suse_/suse32_/:S/suse100_/&32_/}
.  endfor
.endif
