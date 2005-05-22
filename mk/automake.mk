# $NetBSD: automake.mk,v 1.10 2005/05/22 19:11:12 jlam Exp $
#
# makefile fragment for packages that use automake
# AUTOMAKE_REQD can be set to the minimum version required.
# It adds a build dependency on the appropriate automake and autoconf
# packages and sets the following variables:
#	AUTOMAKE:	automake binary to use
#	ACLOCAL:	aclocal binary to use
# autoconf required version will default to 2.13 if automake 1.4* is used,
# and to 2.58 otherwise.
#

.if !defined(AUTOMAKE_MK)
AUTOMAKE_MK=	# defined

# minimal required version
AUTOMAKE_REQD?= 1.9

.include "../../mk/bsd.prefs.mk"

.if !empty(AUTOMAKE_REQD:M1.4*)
USE_TOOLS+=		automake14
.else
USE_TOOLS+=		automake
.endif

.endif # AUTOMAKE_MK
