# $NetBSD: autoconf.mk,v 1.3.4.2 2002/10/03 19:36:37 wiz Exp $
#
# makefile fragment for packages that use autoconf
# AUTOCONF_REQD can be set to the minimum version required.
# It adds a build dependency on the appropriate autoconf package
# and sets the following variables:
#	AUTOCONF:	autoconf binary to use
#	AUTORECONF:	autoreconf binary to use
#	AUTOHEADER:	autoheader binary to use
#

.if !defined(AUTOCONF_MK)
AUTOCONF_MK=	# defined

# minimal required version
AUTOCONF_REQD?= 2.50

.if ${AUTOCONF_REQD:M2.1[0-9]*} == ""
BUILD_DEPENDS+=		autoconf>=${AUTOCONF_REQD}:../../devel/autoconf
AUTOCONF=		${LOCALBASE}/bin/autoconf
AUTORECONF=		${LOCALBASE}/bin/autoreconf
AUTOHEADER=		${LOCALBASE}/bin/autoheader
.else
BUILD_DEPENDS+=		autoconf213>=${AUTOCONF_REQD}:../../devel/autoconf213
AUTOCONF=		${LOCALBASE}/bin/autoconf-2.13
AUTORECONF=		${LOCALBASE}/bin/autoreconf-2.13
AUTOHEADER=		${LOCALBASE}/bin/autoheader-2.13
.endif

.endif # AUTOCONF_MK
