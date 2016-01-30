# $NetBSD: select.mk,v 1.1.2.2 2016/01/30 13:35:26 bsiegert Exp $
#
# Selects the proper version of pkglint, depending on whether the
# platform supports the Go programming language.
#

.include "../../mk/bsd.fast.prefs.mk"

# See lang/go/version.mk
.if !empty(MACHINE_ARCH:Ni386:Nx86_64:Nevbarm) && !empty(MACHINE_PLATFORM:NSunOS-*-i386)
DEPENDS+=	pkglint>=4.82<5:../../pkgtools/pkglint4
.else
DEPENDS+=	pkglint>=5:../../pkgtools/pkglint
.endif
