# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:58 jlam Exp $

.if !defined(TCP_WRAPPERS_BUILDLINK2_MK)
TCP_WRAPPERS_BUILDLINK2_MK=	# defined

BUILDLINK_DEPENDS.tcp_wrappers?=	tcp_wrappers>=7.6.1nb1
BUILDLINK_PKGSRCDIR.tcp_wrappers?=	../../security/tcp_wrappers

.if exists(/usr/include/tcpd.h)
_NEED_TCP_WRAPPERS=	NO
.else
_NEED_TCP_WRAPPERS=	YES
.endif

.if ${_NEED_TCP_WRAPPERS} == "YES"
BUILDLINK_PACKAGES+=	tcp_wrappers
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
