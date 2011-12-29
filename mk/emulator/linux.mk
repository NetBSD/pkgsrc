# $NetBSD: linux.mk,v 1.12 2011/12/29 22:17:20 wiz Exp $
#
# Linux binary emulation framework
#

.if ${OPSYS} == "Linux"
EMUL_TYPE.linux?=	native
.else

# NetBSD 5.99.50 or later default to 11.3, otherwise 10.0
.if ${OPSYS} == "NetBSD" && (empty(OS_VERSION:M[0-5].*) || \
	!empty(OS_VERSION:M5.99.[5-9][0-9]) || \
	!empty(OS_VERSION:M5.99.[0-9][0-9][0-9]*))
SUSE_PREFER?=	11.3
.else
SUSE_PREFER?=	10.0
.endif

.for _version_ in ${EMUL_REQD:Msuse>=*:S/suse>=//}
SUSE_VERSION_REQD?=	${_version_}
.endfor
.if !defined(SUSE_VERSION_REQD) || ${SUSE_PREFER} > ${SUSE_VERSION_REQD}
SUSE_VERSION_REQD=	${SUSE_PREFER}
.endif

EMUL_TYPE.linux?=	suse-${SUSE_VERSION_REQD}
.endif
EMUL_MODULES.linux?=	# empty

.if ((${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")) || \
    ((${EMUL_ARCH} == "sparc") && (${MACHINE_ARCH} == "sparc64"))
_LINUX_BASE=		linux32
EMULSUBDIR=		emul/linux32
.else
_LINUX_BASE=		linux
EMULSUBDIR=		emul/linux
.endif

EMULDIR=		${PREFIX}/${EMULSUBDIR}
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.${_LINUX_BASE}}

# _EMUL_TYPES
#	List of recognized Linux types that a user may request.
#
# _EMUL_MODULES
#	List of recognized Linux "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		native
_EMUL_TYPES+=		suse

.if !empty(EMUL_TYPE.linux:Msuse-*)
_EMUL_TYPE?=		suse
.endif
_EMUL_TYPE?=		${EMUL_TYPE.linux}

_EMUL_MODULES=		alsa
_EMUL_MODULES+=		aspell
_EMUL_MODULES+=		base
_EMUL_MODULES+=		compat
_EMUL_MODULES+=		cups
_EMUL_MODULES+=		curl
_EMUL_MODULES+=		drm
_EMUL_MODULES+=		expat
_EMUL_MODULES+=		fontconfig
_EMUL_MODULES+=		freetype2
_EMUL_MODULES+=		gdk-pixbuf
_EMUL_MODULES+=		glx
_EMUL_MODULES+=		gtk
_EMUL_MODULES+=		gtk2
_EMUL_MODULES+=		jpeg
_EMUL_MODULES+=		krb5
_EMUL_MODULES+=		libsigc++2
_EMUL_MODULES+=		locale
_EMUL_MODULES+=		motif
_EMUL_MODULES+=		openssl
_EMUL_MODULES+=		png
_EMUL_MODULES+=		qt3
_EMUL_MODULES+=		qt4
_EMUL_MODULES+=		resmgr
_EMUL_MODULES+=		slang
_EMUL_MODULES+=		tiff
_EMUL_MODULES+=		vmware
_EMUL_MODULES+=		x11
_EMUL_MODULES+=		xml2

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-linux	# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "native"
EMUL_DISTRO=		native-linux	# native Linux installation
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "linux-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_native-linux.${_mod_}=	# empty
.  endfor
.endif

LDCONFIG_ADD_CMD?=	${EMULDIR}/sbin/ldconfig -r ${EMULDIR}
LDCONFIG_REMOVE_CMD?=	${EMULDIR}/sbin/ldconfig -r ${EMULDIR}
