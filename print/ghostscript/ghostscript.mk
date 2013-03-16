# $NetBSD: ghostscript.mk,v 1.1 2013/03/16 22:34:03 dholland Exp $
#
# This file is for packages that wish to depend on ghostscript, but do
# not compile against it and therefore do not need it buildlinked.
#
# XXX: It is probable that some or all of these should be instead
# setting USE_TOOLS+=gs or USE_TOOLS+=gs:run, but they currently
# aren't and I don't currently have time to tidy them up. Someone
# please see to this...
#
# Packages that compile against ghostscript should use ghostscript.bl3.mk
# instead.
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
DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
.else
DEPENDS+=	ghostscript-gpl-[0-9]*:../../print/ghostscript-gpl
.endif
