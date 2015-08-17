# $NetBSD: bsd.check-vars.mk,v 1.8 2015/08/17 17:35:23 jperkin Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.check.mk is included.
#

CHECK_FILES_SUPPORTED?=		yes
CHECK_SHLIBS_SUPPORTED?=	yes

.if ${_OPSYS_CAN_CHECK_SHLIBS:tl} == "yes"
_USE_CHECK_SHLIBS_NATIVE=	yes
.else
_USE_CHECK_SHLIBS_NATIVE=	no
.endif

USE_TOOLS+=	awk cat cmp diff echo find grep rm sed test touch true
