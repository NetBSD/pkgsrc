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

EMUL_DISTRO=		suse-13.1

.if defined(SUSE_PKG)
_SUSE_VERSION_REQD=	-13.1{,nb*}
.else
_SUSE_VERSION_REQD=	>=13.1<13.2
.endif

# DEPENDS_suse-13.1.* maps Linux "modules" to SuSE package dependencies.
DEPENDS_suse-13.1.alsa?=	suse_alsa${_SUSE_VERSION_REQD}:../../emulators/suse131_alsa
DEPENDS_suse-13.1.aspell?=	suse_aspell${_SUSE_VERSION_REQD}:../../emulators/suse131_aspell
DEPENDS_suse-13.1.base?=	suse_base${_SUSE_VERSION_REQD}:../../emulators/suse131_base
DEPENDS_suse-13.1.compat?=	suse_compat${_SUSE_VERSION_REQD}:../../emulators/suse131_compat
DEPENDS_suse-13.1.cups?=	suse_libcups${_SUSE_VERSION_REQD}:../../emulators/suse131_libcups
DEPENDS_suse-13.1.curl?=	suse_libcurl${_SUSE_VERSION_REQD}:../../emulators/suse131_libcurl
DEPENDS_suse-13.1.cyrus-sasl?=	suse_cyrus-sasl${_SUSE_VERSION_REQD}:../../emulators/suse131_cyrus-sasl
DEPENDS_suse-13.1.drm?=		suse_libdrm${_SUSE_VERSION_REQD}:../../emulators/suse131_libdrm
DEPENDS_suse-13.1.dbus?=	suse_libdbus${_SUSE_VERSION_REQD}:../../emulators/suse131_libdbus
DEPENDS_suse-13.1.expat?=	suse_expat${_SUSE_VERSION_REQD}:../../emulators/suse131_expat
DEPENDS_suse-13.1.fontconfig?=	suse_fontconfig${_SUSE_VERSION_REQD}:../../emulators/suse131_fontconfig
DEPENDS_suse-13.1.freetype2?=	suse_freetype2${_SUSE_VERSION_REQD}:../../emulators/suse131_freetype2
DEPENDS_suse-13.1.glx?=		suse_glx${_SUSE_VERSION_REQD}:../../emulators/suse131_glx
DEPENDS_suse-13.1.gtk2?=	suse_gtk2${_SUSE_VERSION_REQD}:../../emulators/suse131_gtk2
DEPENDS_suse-13.1.jpeg?=	suse_libjpeg${_SUSE_VERSION_REQD}:../../emulators/suse131_libjpeg
DEPENDS_suse-13.1.krb5?=	suse_krb5${_SUSE_VERSION_REQD}:../../emulators/suse131_krb5
DEPENDS_suse-13.1.libidn?=	suse_libidn${_SUSE_VERSION_REQD}:../../emulators/suse131_libidn
DEPENDS_suse-13.1.libjson?=	suse_libjson${_SUSE_VERSION_REQD}:../../emulators/suse131_libjson
DEPENDS_suse-13.1.libsigc++2?=	suse_libsigc++2${_SUSE_VERSION_REQD}:../../emulators/suse131_libsigc++2
DEPENDS_suse-13.1.libsndfile?=	suse_libsndfile${_SUSE_VERSION_REQD}:../../emulators/suse131_libsndfile
DEPENDS_suse-13.1.libssh?=	suse_libssh${_SUSE_VERSION_REQD}:../../emulators/suse131_libssh
DEPENDS_suse-13.1.libwrap?=	suse_libwrap${_SUSE_VERSION_REQD}:../../emulators/suse131_libwrap
DEPENDS_suse-13.1.locale?=	suse_locale${_SUSE_VERSION_REQD}:../../emulators/suse131_locale
DEPENDS_suse-13.1.motif?=	suse_motif${_SUSE_VERSION_REQD}:../../emulators/suse131_motif
DEPENDS_suse-13.1.nss?=		suse_mozilla-nss${_SUSE_VERSION_REQD}:../../emulators/suse131_mozilla-nss
DEPENDS_suse-13.1.nspr?=	suse_mozilla-nspr${_SUSE_VERSION_REQD}:../../emulators/suse131_mozilla-nspr
DEPENDS_suse-13.1.openldap?=	suse_openldap${_SUSE_VERSION_REQD}:../../emulators/suse131_openldap
DEPENDS_suse-13.1.openssl?=	suse_openssl${_SUSE_VERSION_REQD}:../../emulators/suse131_openssl
DEPENDS_suse-13.1.png?=		suse_libpng${_SUSE_VERSION_REQD}:../../emulators/suse131_libpng
DEPENDS_suse-13.1.pulseaudio?=	suse_pulseaudio${_SUSE_VERSION_REQD}:../../emulators/suse131_pulseaudio
DEPENDS_suse-13.1.qt4?=		suse_qt4${_SUSE_VERSION_REQD}:../../emulators/suse131_qt4
DEPENDS_suse-13.1.slang?=	suse_slang${_SUSE_VERSION_REQD}:../../emulators/suse131_slang
DEPENDS_suse-13.1.tiff?=	suse_libtiff${_SUSE_VERSION_REQD}:../../emulators/suse131_libtiff
DEPENDS_suse-13.1.x11?=		suse_x11${_SUSE_VERSION_REQD}:../../emulators/suse131_x11
DEPENDS_suse-13.1.xml2?=	suse_libxml2${_SUSE_VERSION_REQD}:../../emulators/suse131_libxml2

.if (${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_suse-13.1.${_mod_}:=	\
	${DEPENDS_suse-13.1.${_mod_}:S/^suse_/suse32_/:S/suse131_/&32_/}
.  endfor
.endif
