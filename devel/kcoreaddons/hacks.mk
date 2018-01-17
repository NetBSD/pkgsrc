# $NetBSD: hacks.mk,v 1.2 2018/01/17 20:00:20 markd Exp $
#
.include "../../mk/bsd.fast.prefs.mk"

# NetBSD >= 7 has posix_fallocate() but doesnt define _POSIX_ADVISORY_INFO

.if ${OPSYS} == "NetBSD" && empty(MACHINE_PLATFORM:MNetBSD-[0-6].*-*)
CXXFLAGS+=	-DKSDC_POSIX_FALLOCATE_SUPPORTED=1
.endif

BUILDLINK_TRANSFORM.NetBSD+=l:Qt5Widgets:execinfo:Qt5Widgets
