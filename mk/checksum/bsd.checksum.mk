# $NetBSD: bsd.checksum.mk,v 1.2 2006/07/13 18:42:45 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines the
# relevant variables and targets for the "checksum" phase.
#
# The following are the "public" targets provided by this module:
#
#    checksum, makesum, makepatchsum
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
### makedistinfo (PUBLIC)
######################################################################
### makedistinfo is a public target to create ${DISTINFO_FILE}.
###
makedistinfo: makepatchsum makesum
	@${DO_NADA}

# Some short aliases for "makepatchsum" and "makedistinfo".
mps: makepatchsum
mdi: makedistinfo
