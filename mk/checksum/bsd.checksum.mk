# $NetBSD: bsd.checksum.mk,v 1.10 2009/07/15 09:40:30 joerg Exp $
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
# depends-checksum:
#	Run checksum for the current package and all dependencies.
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
#	When defined, no checksums are validated for patches or
#	distfiles.
#
#	Note: This does not alter the behaviour of FAILOVER_FETCH.
#
#	Default value: undefined
#

.PHONY: checksum checksum-phase
.PHONY: makesum makepatchsum mps mdi makedistinfo distinfo

checksum checksum-phase distinfo makesum: fetch
makedistinfo mdi: distinfo
mps: makepatchsum

.include "checksum.mk"
