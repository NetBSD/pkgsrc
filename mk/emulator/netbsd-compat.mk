# $NetBSD: netbsd-compat.mk,v 1.3 2007/12/31 20:06:41 jlam Exp $
#
# COMPAT_* for NetBSD -- see options(4).
#
# Variables defined by this file:
#
# EMUL_EXEC_FMT
#       The executable format of the emulated operating system.
#
# NATIVE_EXEC_FMT
#       The executable format of the native operating system.
#

NATIVE_EXEC_FMT=	${_NATIVE_EXEC_FMT_cmd:sh}
_NATIVE_EXEC_FMT_cmd=	sh ${.CURDIR}/../../mk/scripts/shlib-type	\
				${_OPSYS_SHLIB_TYPE:Q} ${MAKE:Q}

# Most NetBSD (i386) software need netbsd>=1.6
.for _version_ in ${EMUL_REQD:Mnetbsd>=*:S/netbsd>=//}
NETBSD_VERSION_REQD?=	${_version_}
.endfor
NETBSD_VERSION_REQD?=	1.6

# When building a NetBSD "compat" package, force the NetBSD type to be
# the specific version of NetBSD compatibility that is being built.
#
.if defined(NETBSD_PKG) && defined(NETBSD_VERSION)
EMUL_TYPE.netbsd=	compat-${NETBSD_VERSION}
.endif

# The _EMUL_PKG.* table maps ${EMUL_TYPE.netbsd} to the NetBSD shared libs
# package that provides that compatibility version.
#
_EMUL_PKG.compat-1.2=	compat12
_EMUL_PKG.compat-1.3=	compat13
_EMUL_PKG.compat-1.4=	compat14
_EMUL_PKG.compat-1.5=	compat15
_EMUL_PKG.compat-1.6=	compat16
_EMUL_PKG.compat-2.0=	compat20
_EMUL_PKG.compat-3.0=	compat30
_EMUL_PKG.compat-4.0=	compat40
_EMUL_PKG.compat=	# defined, but empty

# EMUL_TYPE.netbsd can be "compat" or "compat-[0-9]*".  If a particular
# EMUL_TYPE.netbsd is requested, then always use it, regardless of the
# value of NETBSD_VERSION_REQD.
#
.if defined(_EMUL_PKG.${EMUL_TYPE.netbsd})
.  if !empty(_EMUL_PKG.${EMUL_TYPE.netbsd})
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.${EMUL_TYPE.netbsd}}/emulator.mk"

.  elif !empty(NETBSD_VERSION_REQD:M1.2*)
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.compat-1.2}/emulator.mk"

.  elif !empty(NETBSD_VERSION_REQD:M1.3*)
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.compat-1.3}/emulator.mk"

.  elif !empty(NETBSD_VERSION_REQD:M1.4*)
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.compat-1.4}/emulator.mk"

.  elif !empty(NETBSD_VERSION_REQD:M1.5*)
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.compat-1.5}/emulator.mk"

.  elif !empty(NETBSD_VERSION_REQD:M1.6*)
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.compat-1.6}/emulator.mk"

.  elif !empty(NETBSD_VERSION_REQD:M2.*)
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.compat-2.0}/emulator.mk"

.  elif !empty(NETBSD_VERSION_REQD:M3.*)
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.compat-3.0}/emulator.mk"

.  elif !empty(NETBSD_VERSION_REQD:M4.*)
.    include "${PKGSRCDIR}/emulators/${_EMUL_PKG.compat-4.0}/emulator.mk"

.  endif

.else
EMUL_DISTRO=		netbsd-0
PKG_FAIL_REASON+=	"[netbsd-compat.mk] ${EMUL_TYPE.netbsd} is not a supported EMUL_TYPE.netbsd"
.endif
