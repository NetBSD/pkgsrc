# $NetBSD: freebsd.mk,v 1.3 2007/10/13 11:04:17 dsl Exp $
#
# FreeBSD binary emulation framework
#

.if !empty(OPSYS:MFreeBSD*)
EMUL_TYPE.freebsd?=	native
.else
EMUL_TYPE.freebsd?=	builtin
.endif
EMUL_MODULES.freebsd?=	# empty

EMULSUBDIR=		emul/freebsd
EMULDIR=		${PREFIX}/${EMULSUBDIR}
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.freebsd}

# _EMUL_TYPES
#	List of recognized FreeBSD types that a user may request.
#
# _EMUL_MODULES
#	List of recognized FreeBSD "modules" that packages may request.
#
_EMUL_TYPES=		builtin
_EMUL_TYPES+=		native
_EMUL_TYPE?=		${EMUL_TYPE.freebsd}

_EMUL_MODULES=		# empty

.if ${_EMUL_TYPE} == "builtin"
EMUL_DISTRO=		builtin-freebsd		# managed outside pkgsrc
.elif ${_EMUL_TYPE} == "native"
EMUL_DISTRO=		native-freebsd		# native FreeBSD installation
EMULDIR=		${PREFIX}
EMULSUBDIR=		# empty
.else
.  include "freebsd-${_EMUL_TYPE}.mk"
.endif

.if (${_EMUL_TYPE} == "builtin") || (${_EMUL_TYPE} == "native")
.  for _mod_ in ${_EMUL_MODULES}
DEPENDS_${EMUL_DISTRO}.${_mod_}?=	# empty
.  endfor
.endif
