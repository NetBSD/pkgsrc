# $NetBSD: bsdi.mk,v 1.1 2007/07/29 05:19:42 jlam Exp $
#
# BSD/OS binary emulation framework
#

EMUL_MODULES.bsdi?=	# empty

# Nothing emulates BSDi -- it's only available natively.
EMUL_TYPE.bsdi?=	native
EMUL_DISTRO=		native
EMULSUBDIR=		# empty
EMULDIR=		${PREFIX}
OPSYS_EMULDIR=		# empty

# _EMUL_TYPES
#	List of recognized BSD/OS types that a user may request.
#
# _EMUL_MODULES
#	List of recognized BSD/OS "modules" that packages may request.
#
_EMUL_TYPES=		native
_EMUL_TYPE=		native
_EMUL_MODULES=		# empty

.for _mod_ in ${_EMUL_MODULES}
DEPENDS_native.${_mod_}?=       # empty
.endfor
