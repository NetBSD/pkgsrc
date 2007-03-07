# $NetBSD: bsd.checksum.mk,v 1.5 2007/03/07 01:06:11 rillig Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines the
# relevant variables and targets for the "checksum" phase.
#
# Public targets for pkgsrc users:
#
# checksum:
#	Check that the distfiles have the correct checksums. If they
#	aren't yet fetched, fetch them.
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

.PHONY: checksum makesum makepatchsum mps mdi makedistinfo distinfo

checksum makesum: fetch
makedistinfo distinfo mdi: makepatchsum makesum
mps: makepatchsum

.if defined(NO_CHECKSUM)
checksum makesum makepatchsum mps mdi makedistinfo distinfo:
	@${DO_NADA}
.else
.  include "${PKGSRCDIR}/mk/checksum/checksum.mk"
.endif
