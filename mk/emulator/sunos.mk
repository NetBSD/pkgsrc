# $NetBSD: sunos.mk,v 1.3 2007/10/13 11:04:18 dsl Exp $
#
# SunOS 4.x binary emulation framework
#

.if ${OPSYS} == "SunOS"
EMUL_TYPE.sunos?=	native
.else
EMUL_TYPE.sunos?=	builtin
.endif
EMUL_MODULES.sunos?=	# empty

EMULSUBDIR=		emul/sunos
EMULDIR=		${PREFIX}/${EMULSUBDIR}
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.sunos}

# _EMUL_TYPES
#	List of recognized SunOS types that a user may request.
#
# _EMUL_MODULES
#	List of recognized SunOS "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		native
_EMUL_TYPE?=		${EMUL_TYPE.sunos}

_EMUL_MODULES=		# empty

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-sunos	# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		native-sunos	# native SunOS 4.x
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "sunos-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_${EMUL_DISTRO}.${_mod_}=	# empty
.  endfor
.endif
