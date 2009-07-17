# $NetBSD: license.mk,v 1.2 2009/07/17 06:44:46 sno Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install perl5 modules and by the perl5 package.
#
# The following variables may be set prior to including this file:
#
# PERL5_LICENSE		If set, it'll not overwritten with gnu-gpl-v2.
#			Allowed values: gnu-gpl-v2 and artistic until
#			pkgsrc can handle dual licenses correctly.
#
PERL5_LICENSE?=		gnu-gpl-v2 OR artistic
