# $NetBSD: automake.mk,v 1.2 2002/10/03 19:36:36 wiz Exp $
#
# makefile fragment for packages that use automake
# AUTOMAKE_REQD can be set to the minimum version required.
# It adds a build dependency on the appropriate automake and autoconf
# packages and sets the following variables:
#	AUTOMAKE:	automake binary to use
#	ACLOCAL:	aclocal binary to use
# autoconf required version will default to 2.13 if automake 1.4* is used,
# and to 2.50 otherwise.
#

.if !defined(AUTOMAKE_MK)
AUTOMAKE_MK=	# defined

# minimal required version
AUTOMAKE_REQD?= 1.7

.if ${AUTOMAKE_REQD:M1.4*} == ""
BUILD_DEPENDS+=		automake>=${AUTOMAKE_REQD}:../../devel/automake
_AUTOMAKE_API_VERSION=	1.7
AUTOCONF_REQD?=		2.50
.else
BUILD_DEPENDS+=		automake14>=${AUTOMAKE_REQD}:../../devel/automake14
_AUTOMAKE_API_VERSION=	1.4
AUTOCONF_REQD?=		2.13
.endif

AUTOMAKE=		${LOCALBASE}/bin/automake-${_AUTOMAKE_API_VERSION}
ACLOCAL=		${LOCALBASE}/bin/aclocal-${_AUTOMAKE_API_VERSION}

.include "../../mk/autoconf.mk"
.endif # AUTOMAKE_MK
