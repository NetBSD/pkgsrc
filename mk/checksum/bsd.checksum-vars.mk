# $NetBSD: bsd.checksum-vars.mk,v 1.5 2024/10/22 06:29:21 jperkin Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.checksum.mk is included.
#
# The following variables may be set in a package Makefile:
#
#    DISTINFO_FILE is the path to file containing the checksums.
#
#    ARGMAX_REQ is the minimum ARG_MAX required to correctly create or
#    validate all of the checksums.  In packages that have a large number
#    (many thousands) of distfiles, this should be set to a power of two
#    above the required minimum.  For example 524288 to indicate that the
#    current NetBSD limit of 262144 is insufficient.
#
# Keywords: distinfo

DISTINFO_FILE?=		${PKGDIR}/distinfo

.if !empty(_CKSUMFILES) && empty(TOOLS_PLATFORM.mktool)
USE_TOOLS+=	digest:bootstrap
.endif

# If a package has a number of distfiles that may overflow ARG_MAX then use
# temporary files, otherwise use pipes.  The temporary files need to live in
# a known directory and cannot use WRKDIR for example because it is not
# guaranteed to exist when the target is called.
#
.if ${USE_TMPFILES} == yes
_CKSUMFILES_INPUT_cmd=	${MKTEMP} ${TMPDIR:U/tmp:Q}/pkgsrc.cksumfiles.XXXXXXXX
USE_TOOLS+=		mktemp:bootstrap
.else
_CKSUMFILES_INPUT=	/dev/stdin
.endif
