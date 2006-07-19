# $NetBSD: bsd.checksum.mk,v 1.3 2006/07/19 14:54:56 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines the
# relevant variables and targets for the "checksum" phase.
#
# The following are the "public" targets provided by this module:
#
#    checksum, makesum, makepatchsum, distinfo
#

######################################################################
### checksum, makesum, makepatchsum (PUBLIC)
######################################################################
### checksum is a public target to checksum the fetched distfiles
### for the package.
###
### makesum is a public target to add checksums of the distfiles for
### the package to ${DISTINFO_FILE}.
###
### makepatchsum is a public target to add checksums of the patches
### for the package to ${DISTINFO_FILE}.
###
.if defined(NO_CHECKSUM)
.PHONY: checksum makesum makepatchsum
.  if !target(checksum)
checksum:
	@${DO_NADA}
.  endif
makesum makepatchsum:
	@${DO_NADA}
.else
.  include "${PKGSRCDIR}/mk/checksum/checksum.mk"
.endif

######################################################################
### distinfo (PUBLIC)
######################################################################
### distinfo is a public target to create ${DISTINFO_FILE}.
###
.PHONY: distinfo
distinfo: makepatchsum makesum
	@${DO_NADA}

# Some short aliases for "makepatchsum" and "distinfo".
.PHONY: mps mdi makedistinfo
mps: makepatchsum
mdi makedistinfo: distinfo
