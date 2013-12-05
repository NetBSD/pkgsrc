# $NetBSD: linux-suse.mk,v 1.8 2013/12/05 11:42:12 obache Exp $
#
# SuSE Linux
#

# When building the SuSE packages, force the Linux type to be the specific
# version of SuSE that is being built.
#
.if defined(SUSE_PKG) && defined(SUSE_VERSION)
EMUL_TYPE.linux=	suse-${SUSE_VERSION}
.endif

# EMUL_TYPE.linux can be "suse" or "suse-[0-9]*".  If the former, then use
# the default SuSE version, otherwise use the specific version requested.
#
.if !empty(EMUL_TYPE.linux:Msuse-10.[0x])
.  include "${PKGSRCDIR}/emulators/suse100_linux/emulator.mk"

.elif !empty(EMUL_TYPE.linux:Msuse-12.[1x])
.  include "${PKGSRCDIR}/emulators/suse121_linux/emulator.mk"

.elif !empty(EMUL_TYPE.linux:Msuse-13.[1x])
.  include "${PKGSRCDIR}/emulators/suse131_linux/emulator.mk"

.else
EMUL_DISTRO=		suse-0
PKG_FAIL_REASON+=	"[linux-suse.mk] ${EMUL_TYPE.linux} is not a supported EMUL_TYPE.linux"
.endif

# XXX There should be a check here to verify that ${EMUL_DISTRO} satisfies
# XXX suse>=${SUSE_VERSION_REQD}.
