# $NetBSD: select.mk,v 1.5 2018/10/03 22:27:53 rillig Exp $
#
# Selects the proper version of pkglint, depending on whether the
# platform supports the Go programming language.
#

.include "../../mk/bsd.fast.prefs.mk"

# See lang/go/version.mk
# While it's wrong in the above, go14 does not build on NetBSD 5.
.if ${MACHINE_ARCH:Ni386:Nx86_64:Nevbarm} || ${MACHINE_PLATFORM:MSunOS-*-i386} || ${MACHINE_PLATFORM:MNetBSD-[1-5].*-*}
DEPENDS+=	pkglint4>=4.82<5:../../pkgtools/pkglint4
.else
DEPENDS+=	pkglint>=5:../../pkgtools/pkglint
.endif
