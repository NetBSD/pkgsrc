# $NetBSD: irix.mk,v 1.3 2007/10/13 11:04:17 dsl Exp $
#
# IRIX binary emulation framework
#

.if !empty(OPSYS:MIRIX*)
EMUL_TYPE.irix?=	native
.else
EMUL_TYPE.irix?=	builtin
.endif
EMUL_MODULES.irix?=	# empty

EMULSUBDIR=		emul/irix
EMULDIR=		${PREFIX}/${EMULSUBDIR}
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.irix}

# _EMUL_TYPES
#	List of recognized IRIX types that a user may request.
#
# _EMUL_MODULES
#	List of recognized IRIX "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		native
_EMUL_TYPE?=		${EMUL_TYPE.irix}

_EMUL_MODULES=		# empty

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-irix	# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "native"
EMUL_DISTRO=		native-irix	# native IRIX installation
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "irix-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_${EMUL_DISTRO}.${_mod_}?=	# empty
.  endfor
.endif
