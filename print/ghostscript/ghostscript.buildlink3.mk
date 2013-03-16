# $NetBSD: ghostscript.buildlink3.mk,v 1.1 2013/03/16 22:34:03 dholland Exp $
#
# This file selects the proper buildlink3 file for ghostscript.
#


.include "../../mk/bsd.prefs.mk"

#
# Use ACCEPTABLE_LICENSES to pick the ghostscript package, on the
# theory that the agpl version is newer and therefore preferable if
# it's acceptable.
#
# This should probably support an explicit GS_TYPE or similar setting,
# and we might need GS_ACCEPTED, etc. too.
#

.if !empty(ACCEPTABLE_LICENSES:Mgnu-agpl-*)
.include "../../print/ghostscript-agpl/buildlink3.mk"
.else
.include "../../print/ghostscript-gpl/buildlink3.mk"
.endif
