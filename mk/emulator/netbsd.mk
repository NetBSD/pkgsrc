# $NetBSD: netbsd.mk,v 1.3 2007/10/13 11:04:18 dsl Exp $
#
# NetBSD binary emulation framework
#
# Nothing emulates NetBSD except for newer versions of NetBSD, so we can
# safely assume that ${OPSYS} == "NetBSD".
#

EMUL_TYPE.netbsd?=	compat
EMUL_MODULES.netbsd?=	# empty

EMULDIR=		${PREFIX}/${EMULSUBDIR}

# _EMUL_TYPES
#	List of recognized NetBSD types that a user may request.
#
# _EMUL_MODULES
#	List of recognized NetBSD "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		compat
_EMUL_TYPES+=		native

.if !empty(EMUL_TYPE.netbsd:Mcompat-*)
_EMUL_TYPE?=		compat
.endif
_EMUL_TYPE?=		${EMUL_TYPE.netbsd}

_EMUL_MODULES=		base

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-netbsd		# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "native"
EMUL_DISTRO=		native-netbsd		# native NetBSD
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "netbsd-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_${EMUL_DISTRO}.${_mod_}=	# empty
.  endfor
.endif

LDCONFIG_ADD_CMD?=	/sbin/ldconfig
LDCONFIG_REMOVE_CMD?=	/sbin/ldconfig
