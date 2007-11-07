# $NetBSD: bsd.extract.mk,v 1.4 2007/11/07 09:53:15 rillig Exp $
#
# This Makefile fragment is included to bsd.pkg.mk and defines the
# relevant variables and targets for the "extract" phase.
#
# The following are the "public" targets provided by this module:
#
#    extract
#
# The following targets may be overridden in a package Makefile:
#
# pre-extract:
#	Can be used to prepare the distfiles for extraction.
#	For binary-only packages, this can mean to make the distfile
#	executable.
#
#	Default action: Nothing.
#
# do-extract:
#	This target does the "real" work of extracting the distfiles.
#
#	Default action: Extracts the files listed in EXTRACT_ONLY into
#	WRKDIR.
#
# post-extract:
#	Can be used to remove unneeded files that have been extracted.
#	Often, additional files from FILESDIR are copied to WRKSRC here,
#	too.
#
#	Default action: Nothing.
#
#	Typical actions:
#	* chmod -R a+r,u+w,go-w ${WRKSRC}
#

.include "extract.mk"
