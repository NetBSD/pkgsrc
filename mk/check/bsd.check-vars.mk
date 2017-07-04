# $NetBSD: bsd.check-vars.mk,v 1.9 2017/07/04 18:29:24 khorben Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.check.mk is included.
#

CHECK_FILES_SUPPORTED?=		yes
CHECK_RELRO_SUPPORTED?=		yes
CHECK_SHLIBS_SUPPORTED?=	yes

_OPSYS_CAN_CHECK_RELRO?=	${_OPSYS_CAN_CHECK_SHLIBS}

.if ${_OPSYS_CAN_CHECK_RELRO:tl} == "yes"
_USE_CHECK_RELRO_NATIVE=	yes
.else
_USE_CHECK_RELRO_NATIVE=	no
.endif

.if ${_OPSYS_CAN_CHECK_SHLIBS:tl} == "yes"
_USE_CHECK_SHLIBS_NATIVE=	yes
.else
_USE_CHECK_SHLIBS_NATIVE=	no
.endif

USE_TOOLS+=	awk cat cmp diff echo find grep rm sed test touch true
