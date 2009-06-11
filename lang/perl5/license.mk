# $NetBSD: license.mk,v 1.1 2009/06/11 10:35:07 sno Exp $
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
PERL5_LICENSE?=		gnu-gpl-v2 # OR artistic
