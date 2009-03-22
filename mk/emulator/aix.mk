# $NetBSD: aix.mk,v 1.1 2009/03/22 22:31:46 sno Exp $
#
# AIX binary emulation framework
#

.if !empty(OPSYS:MAIX*)
EMUL_TYPE.aix?=	native
.else
EMUL_TYPE.aix?=	builtin
.endif
EMUL_MODULES.aix?=	# empty

EMULSUBDIR=		emul/aix
EMULDIR=		${PREFIX}/${EMULSUBDIR}
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.aix}

# _EMUL_TYPES
#	List of recognized AIX types that a user may request.
#
# _EMUL_MODULES
#	List of recognized AIX "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		native
_EMUL_TYPE?=		${EMUL_TYPE.aix}

_EMUL_MODULES=		# empty

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-aix		# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "native"
EMUL_DISTRO=		native-aix		# native AIX installation
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "aix-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_${EMUL_DISTRO}.${_mod_}?=	# empty
.  endfor
.endif
