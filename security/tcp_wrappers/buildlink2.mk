# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:51 jlam Exp $
#
# This Makefile fragment is included by packages that use tcp_wrappers.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.tcp_wrappers to the dependency
#     pattern for the version of tcp_wrappers desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(TCP_WRAPPERS_BUILDLINK2_MK)
TCP_WRAPPERS_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.tcp_wrappers?=	tcp_wrappers>=7.6.1nb1

.if exists(/usr/include/tcpd.h)
_NEED_TCP_WRAPPERS=	NO
.else
_NEED_TCP_WRAPPERS=	YES
.endif

.if ${_NEED_TCP_WRAPPERS} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.tcp_wrappers}:../../security/tcp_wrappers
EVAL_PREFIX+=	BUILDLINK_PREFIX.tcp_wrappers=tcp_wrappers
BUILDLINK_PREFIX.tcp_wrappers_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.tcp_wrappers=	/usr
.endif

BUILDLINK_FILES.tcp_wrappers=	include/tcpd.h
BUILDLINK_FILES.tcp_wrappers+=	lib/libwrap.*

BUILDLINK_TARGETS+=		tcp_wrappers-buildlink

tcp_wrappers-buildlink: _BUILDLINK_USE

.endif	# TCP_WRAPPERS_BUILDLINK2_MK
