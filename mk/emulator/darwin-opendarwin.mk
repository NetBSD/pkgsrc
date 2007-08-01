# $NetBSD: darwin-opendarwin.mk,v 1.1 2007/08/01 16:28:08 jlam Exp $
#
# OpenDarwin
#

# EMUL_TYPE.darwin can be "opendarwin" or "opendarwin-[0-9]*".  If the
# former, then use the default OpenDarwin version, otherwise use the
# specific version requested.
#
.if !empty(EMUL_TYPE.darwin:Mopendarwin-6.x)
.  include "${PKGSRCDIR}/emulators/darwin_lib/emulator.mk"

.elif !empty(EMUL_TYPE.darwin:Mopendarwin)
   # default to highest version of OpenDarwin
.  include "${PKGSRCDIR}/emulators/darwin_lib/emulator.mk"

.else
EMUL_DISTRO=		opendarwin-0
PKG_FAIL_REASON+=	"[darwin-opendarwin.mk] ${EMUL_TYPE.darwin} is not a supported EMUL_TYPE.darwin"
.endif
