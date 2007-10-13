# $NetBSD: osf1.mk,v 1.4 2007/10/13 11:04:18 dsl Exp $
#
# OSF/1 (Tru64) binary emulation framework
#

.if !empty(OPSYS:MOSF*)
EMUL_TYPE.osf1?=	native
.else
EMUL_TYPE.osf1?=	netscape
.endif
EMUL_MODULES.osf1?=	# empty

EMULSUBDIR=		emul/osf1
EMULDIR=		${PREFIX}/${EMULSUBDIR}
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.osf1}

# _EMUL_TYPES
#	List of recognized OSF/1 types that a user may request.
#
# _EMUL_MODULES
#	List of recognized OSF/1 "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		native
_EMUL_TYPES+=		netscape
_EMUL_TYPE?=		${EMUL_TYPE.osf1}

_EMUL_MODULES=		# empty

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-osf1	# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "native"
EMUL_DISTRO=		native-osf1	# native OSF/1 (Tru64)
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "osf1-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_${EMUL_DISTRO}.${_mod_}?=	# empty
.  endfor
.endif
