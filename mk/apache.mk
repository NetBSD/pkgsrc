# $NetBSD: apache.mk,v 1.34 2026/11/25 16:53:31 wiz Exp $
#
# This file is meant to be included by packages that require an apache
# web server.
#
# Package-settable variables:
#
# USE_APR
#	If this variable is set to "yes", a full dependency to the
#	Apache Portable Runtime library will be added.
#

.if !defined(APACHE_MK)
APACHE_MK=			# defined

_VARGROUPS+=		apache
_PKG_VARS.apache=	USE_APR

.include "bsd.fast.prefs.mk"

# Package-settable variables
USE_APR?=		no

.include "../../www/apache24/buildlink3.mk"

.if !empty(USE_APR:M[Yy][Ee][Ss])
.  include "../../devel/apr/buildlink3.mk"
.  include "../../devel/apr-util/buildlink3.mk"
.endif

.endif	# APACHE_MK
