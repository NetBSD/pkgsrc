# $NetBSD: bsd.fetch.mk,v 1.5 2007/01/02 17:54:32 rillig Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines the
# relevant variables and targets for the "fetch" step.
#
# The following are the "public" targets provided by this module:
#
# fetch:
#	Downloads all required distfiles for the current package.
#
# fetch-list:
#	Prints a shell script to the standard output that will download
#	the distfiles.
#
# The following targets may be overridden in a package Makefile:
#
# pre-fetch:
#	Can be used to prepare downloading the distfiles.
#
#	Default action: Nothing.
#
# do-fetch:
#	Downloads the distfiles and patches.
#
#	Default action (roughly): Downloads all DISTFILES from
#	MASTER_SITES and puts them into DISTDIR.
#
# post-fetch:
#	Can be used to do something with the downloaded files.
#
#	Default action: Nothing.
#

.include "${PKGSRCDIR}/mk/fetch/sites.mk"
.include "${PKGSRCDIR}/mk/fetch/fetch.mk"
.include "${PKGSRCDIR}/mk/fetch/fetch-list.mk"
.include "${PKGSRCDIR}/mk/fetch/distclean.mk"
