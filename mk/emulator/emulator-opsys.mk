# $NetBSD: emulator-opsys.mk,v 1.1 2007/08/23 15:59:33 jlam Exp $
#
# This file is included by emulator.mk.
#
# Variables defined by this file:
#
# EMUL_DISTRO
#	The distribution of the emulated operating system being used,
#	e.g. native-linux, suse-10.0, etc.  If the package isn't
#	supported on this machine, then its value is "none".
#
# EMULDIR
#	Convenience variable that expands to ${PREFIX}/${EMULSUBDIR}
#
# EMULSUBDIR
#	Path relative to ${PREFIX} where the files and directories
#	are located, e.g. emul/linux.
#
# OPSYS_EMULDIR
#	Path through which the platform expects to find a "chroot"
#	installation of the files and directories, e.g. /emul/linux.
#

.if !defined(_EMULATOR_EMULATOR_OPSYS_MK)
_EMULATOR_EMULATOR_OPSYS_MK=	defined

.if empty(EMUL_PLATFORMS:M${EMUL_PLATFORM})
PKG_FAIL_REASON+=	"${PKGNAME} is not available for ${MACHINE_PLATFORM}"
.endif

.if ${EMUL_PLATFORM} == "none"
EMUL_DISTRO?=		none
EMULSUBDIR?=		# empty
EMULDIR?=		${PREFIX}
OPSYS_EMULDIR?=		# empty
.else
#
# The ${EMUL_OPSYS}.mk file included here should define the following
# variables either directly or indirectly:
#
#	EMUL_DISTRO, EMULSUBDIR, EMULDIR, OPSYS_EMULDIR
#
.  include "${.PARSEDIR}/${EMUL_OPSYS}.mk"
.endif

.endif	# _EMULATOR_EMULATOR_OPSYS_MK
