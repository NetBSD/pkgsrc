# $NetBSD: bsd.checksum.mk,v 1.8 2008/01/04 01:46:26 rillig Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines the
# relevant variables and targets for the "checksum" phase.
#
# Public targets for pkgsrc users:
#
# checksum:
#	Check that the distfiles have the correct checksums. If they
#	aren't yet fetched, fetch them.  This target can be run at
#	any time and is meant to be run by the user.
#
# checksum-phase:
#	Same as "checksum" but is meant to run automatically by pkgsrc.
#	This target does not run after the "extract" phase is complete.
#
# Public targets for pkgsrc developers:
#
# makesum:
#	Add or update the checksums of the distfiles to ${DISTINFO_FILE}.
#
#	See also: patchsum
#
# makepatchsum, mps:
#	Add or update the checksums of the patches to ${DISTINFO_FILE}.
#
# makedistinfo, distinfo, mdi:
#	Create or update the checksums in ${DISTINFO_FILE}.
#
# Package-settable variables:
#
# NO_CHECKSUM
#	When defined, no checksums are generated for patches or
#	distfiles.
#
#	Default value: undefined
#

.PHONY: checksum checksum-phase
.PHONY: makesum makepatchsum mps mdi makedistinfo distinfo

checksum checksum-phase distinfo makesum: fetch
makedistinfo mdi: distinfo
mps: makepatchsum

.if defined(NO_CHECKSUM)
checksum checksum-phase makesum makepatchsum mps mdi makedistinfo distinfo:
	@${DO_NADA}
.else
.  include "checksum.mk"
.endif
