# $NetBSD: nroff.buildlink3.mk,v 1.1.2.2 2005/03/21 15:43:00 tv Exp $
#
# This fragment provides a NROFF macro, and includes a dependency
# on textproc/groff if needed.  This does not depend on the OS providing
# groff; if any system-supplied nroff is available, it is accepted.
#

.include "../../mk/bsd.prefs.mk"

.if !defined(NROFF)
.  if exists(/usr/bin/nroff)
NROFF?=			/usr/bin/nroff
.  else
.    include "../../textproc/groff/buildlink3.mk"
NROFF?=			${BUILDLINK_PREFIX.groff}/bin/nroff
.  endif
.endif
