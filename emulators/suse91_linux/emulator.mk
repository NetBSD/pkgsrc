# $NetBSD: emulator.mk,v 1.3 2007/07/30 13:38:41 jlam Exp $
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

EMUL_DISTRO=		suse-9.1

.if defined(SUSE_PKG)
_SUSE_VERSION_REQD=	-${SUSE_VERSION_REQD}{,nb*}
.else
_SUSE_VERSION_REQD=	>=${SUSE_VERSION_REQD}
.endif

# DEPENDS_suse-9.1.* maps Linux "modules" to SuSE package dependencies.
DEPENDS_suse-9.1.aspell?=	suse_aspell${_SUSE_VERSION_REQD}:../../emulators/suse91_aspell
DEPENDS_suse-9.1.base?=		suse_base${_SUSE_VERSION_REQD}:../../emulators/suse91_base
DEPENDS_suse-9.1.compat?=	suse_compat${_SUSE_VERSION_REQD}:../../emulators/suse91_compat
DEPENDS_suse-9.1.expat?=	suse_expat${_SUSE_VERSION_REQD}:../../emulators/suse91_expat
DEPENDS_suse-9.1.fontconfig?=	suse_fontconfig${_SUSE_VERSION_REQD}:../../emulators/suse91_fontconfig
DEPENDS_suse-9.1.freetype2?=	suse_freetype2${_SUSE_VERSION_REQD}:../../emulators/suse91_freetype2
DEPENDS_suse-9.1.gdk-pixbuf?=	suse_gdk-pixbuf${_SUSE_VERSION_REQD}:../../emulators/suse91_gdk-pixbuf
DEPENDS_suse-9.1.glx?=		suse_glx${_SUSE_VERSION_REQD}:../../emulators/suse91_glx
DEPENDS_suse-9.1.gtk?=		suse_gtk${_SUSE_VERSION_REQD}:../../emulators/suse91_gtk
DEPENDS_suse-9.1.gtk2?=		suse_gtk2${_SUSE_VERSION_REQD}:../../emulators/suse91_gtk2
DEPENDS_suse-9.1.jpeg?=		suse_libjpeg${_SUSE_VERSION_REQD}:../../emulators/suse91_libjpeg
DEPENDS_suse-9.1.locale?=	suse_locale${_SUSE_VERSION_REQD}:../../emulators/suse91_locale
DEPENDS_suse-9.1.motif?=	suse_openmotif${_SUSE_VERSION_REQD}:../../emulators/suse91_openmotif
DEPENDS_suse-9.1.png?=		suse_libpng${_SUSE_VERSION_REQD}:../../emulators/suse91_libpng
DEPENDS_suse-9.1.slang?=	suse_slang${_SUSE_VERSION_REQD}:../../emulators/suse91_slang
DEPENDS_suse-9.1.tiff?=		suse_libtiff${_SUSE_VERSION_REQD}:../../emulators/suse91_libtiff
DEPENDS_suse-9.1.vmware?=	suse_vmware${_SUSE_VERSION_REQD}:../../emulators/suse91_vmware
DEPENDS_suse-9.1.x11?=		suse_x11${_SUSE_VERSION_REQD}:../../emulators/suse91_x11

.if (${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_suse-9.1.${_mod_}:=	\
	${DEPENDS_suse-9.1.${_mod_}:S/^suse_/suse32_/:S/suse91_/&32_/}
.  endfor
.endif
