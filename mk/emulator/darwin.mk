# $NetBSD: darwin.mk,v 1.3 2007/10/13 11:04:17 dsl Exp $
#
# Darwin (Mac OS X) binary emulation framework
#

.if !empty(OPSYS:MDarwin*)
EMUL_TYPE.darwin?=	native
.else
EMUL_TYPE.darwin?=	opendarwin
.endif
EMUL_MODULES.darwin?=	# empty

EMULSUBDIR=		emul/darwin
EMULDIR=		${PREFIX}/${EMULSUBDIR}
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.darwin}

# _EMUL_TYPES
#	List of recognized Darwin types that a user may request.
#
# _EMUL_MODULES
#	List of recognized Darwin "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		native
_EMUL_TYPES+=		opendarwin
_EMUL_TYPE?=		${EMUL_TYPE.darwin}

_EMUL_MODULES=		# empty

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-darwin	# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "native"
EMUL_DISTRO=		native-darwin	# native OSF/1 (Tru64)
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "darwin-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_${EMUL_DISTRO}.${_mod_}?=	# empty
.  endfor
.endif
