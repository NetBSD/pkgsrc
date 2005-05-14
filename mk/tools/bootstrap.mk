# $NetBSD: bootstrap.mk,v 1.2 2005/05/14 21:15:07 jlam Exp $
#
# bootstrap.mk contains settings matching the contents of
# pkgsrc/bootstrap/bootstrap.  Where we install the bootstrap versions
# of tools, we point TOOLS_PLATFORM.* to them so that pkgsrc knows
# that they are system-supplied and won't need replacement by pkgsrc
# versions of those tools.
#
# XXX This file should go away and the bootstrap script should be
# XXX taught to write out the correct TOOLS_PLATFORM.* definitions
# XXX on its own, based on the configuration used.
# 

.if ${OPSYS} == "AIX"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.install?=	${LOCALBASE}/bin/install-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.strip?=		${LOCALBASE}/bin/strip
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "Darwin"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "DragonFly"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "FreeBSD"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "HPUX"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "Interix"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.install?=	${LOCALBASE}/bin/install-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "IRIX"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.install?=	${LOCALBASE}/bin/install-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "Linux"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "NetBSD"
# NetBSD has everything.

.elif ${OPSYS} == "OpenBSD"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "OSF1"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.install?=	${LOCALBASE}/bin/install-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "SunOS"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.elif ${OPSYS} == "UnixWare"
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.mkdir?=		${LOCALBASE}/sbin/mkdir-sh
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar

.else
TOOLS_PLATFORM.gtar?=		${TOOLS_PLATFORM.tar}
TOOLS_PLATFORM.mtree?=		${LOCALBASE}/sbin/mtree
TOOLS_PLATFORM.pax?=		${LOCALBASE}/bin/pax
TOOLS_PLATFORM.sed?=		${LOCALBASE}/bin/nbsed
TOOLS_PLATFORM.tar?=		${LOCALBASE}/bin/tar
.endif
