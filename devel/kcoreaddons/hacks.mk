# $NetBSD: hacks.mk,v 1.1 2016/05/26 08:29:04 markd Exp $
#
.include "../../mk/bsd.fast.prefs.mk"

# NetBSD >= 7 has posix_fallocate() but doesnt define _POSIX_ADVISORY_INFO

.if ${OPSYS} == "NetBSD" && empty(MACHINE_PLATFORM:MNetBSD-[0-6].*-*)
CXXFLAGS+=	-DKSDC_POSIX_FALLOCATE_SUPPORTED=1
.endif
