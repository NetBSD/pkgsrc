# $NetBSD: hacks.mk,v 1.3 2018/04/07 00:51:28 markd Exp $
#
.include "../../mk/bsd.fast.prefs.mk"

# NetBSD >= 7 has posix_fallocate() but doesnt define _POSIX_ADVISORY_INFO

.if ${OPSYS} == "NetBSD" && empty(MACHINE_PLATFORM:MNetBSD-[0-6].*-*)
CXXFLAGS+=	-DKSDC_POSIX_FALLOCATE_SUPPORTED=1
.endif
