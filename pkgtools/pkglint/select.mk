# $NetBSD: select.mk,v 1.2 2016/02/01 21:40:39 rillig Exp $
#
# Selects the proper version of pkglint, depending on whether the
# platform supports the Go programming language.
#

.include "../../mk/bsd.fast.prefs.mk"

# See lang/go/version.mk
.if ${MACHINE_ARCH:Ni386:Nx86_64:Nevbarm} || ${MACHINE_PLATFORM:MSunOS-*-i386}
DEPENDS+=	pkglint>=4.82<5:../../pkgtools/pkglint4
.else
DEPENDS+=	pkglint>=5:../../pkgtools/pkglint
.endif
