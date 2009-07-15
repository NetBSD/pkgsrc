# $NetBSD: bsd.fetch.mk,v 1.7 2009/07/15 09:40:30 joerg Exp $
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
# depends-fetch:
#	Run fetch for the current package and all dependencies.
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

.include "sites.mk"
.include "fetch.mk"
.include "fetch-list.mk"
.include "distclean.mk"
