# $NetBSD: solaris.mk,v 1.3 2007/10/13 11:04:18 dsl Exp $
#
# Solaris (SVR4) binary emulation framework
#

.if ${OPSYS} == "SunOS"
EMUL_TYPE.solaris?=	native
.else
EMUL_TYPE.solaris?=	builtin
.endif
EMUL_MODULES.solaris?=	# empty

.if ((${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")) || \
    ((${EMUL_ARCH} == "sparc") && (${MACHINE_ARCH} == "sparc64"))
_SOLARIS_BASE=		solaris32
EMULSUBDIR=		emul/svr4_32
.else
_SOLARIS_BASE=		solaris
EMULSUBDIR=		emul/svr4
.endif

EMULDIR=		${PREFIX}/${EMULSUBDIR}
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.${_SOLARIS_BASE}}

# _EMUL_TYPES
#	List of recognized Solaris types that a user may request.
#
# _EMUL_MODULES
#	List of recognized Solaris "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		native
#_EMUL_TYPES+=		opensolaris
_EMUL_TYPE?=		${EMUL_TYPE.solaris}

_EMUL_MODULES=		# empty

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-solaris		# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "native"
EMUL_DISTRO=		native-solaris		# native SunOS 5.x
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "solaris-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_${EMUL_DISTRO}.${_mod_}=	# empty
.  endfor
.endif
