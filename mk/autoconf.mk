# $NetBSD: autoconf.mk,v 1.1 2002/10/02 18:10:15 dillo Exp $
#
# makefile fragment for packages that use autoconf
# AUTOCONF_REQD can be set to the minimum version required.
# It adds a build dependency on the appropriate autoconf package
# and sets the following variables:
#	AUTOCONF:	autoconf binary to use
#	AUTOHEADER;	autoheader binary to use
#

.if !defined(AUTOCONF_MK)
AUTOCONF_MK=	# defined

# minimal required version
AUTOCONF_REQD?= 2.50

.if ${AUTOCONF_REQD:M2.1[0-9]*} == ""
BUILD_DEPENDS+=		autoconf>=${AUTOCONF_REQD}:../../devel/autoconf-devel
AUTOCONF=		${LOCALBASE}/bin/autoconf
AUTOHEADER=		${LOCALBASE}/bin/autoheader
.else
BUILD_DEPENDS+=		autoconf>=${AUTOCONF_REQD}:../../devel/autoconf
AUTOCONF=		${LOCALBASE}/bin/autoconf
AUTOHEADER=		${LOCALBASE}/bin/autoheader
.endif

.endif # AUTOCONF_MK
