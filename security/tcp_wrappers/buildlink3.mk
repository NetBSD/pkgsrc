# $NetBSD: buildlink3.mk,v 1.4 2004/01/05 11:05:47 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCP_WRAPPERS_BUILDLINK3_MK:=	${TCP_WRAPPERS_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(TCP_WRAPPERS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			tcp_wrappers
BUILDLINK_DEPENDS.tcp_wrappers?=	tcp_wrappers>=7.6.1nb1
BUILDLINK_PKGSRCDIR.tcp_wrappers?=	../../security/tcp_wrappers
.endif	# TCP_WRAPPERS_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.tcp_wrappers?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.tcp_wrappers)
BUILDLINK_IS_BUILTIN.tcp_wrappers=	NO
.  if exists(/usr/include/tcpd.h)
BUILDLINK_IS_BUILTIN.tcp_wrappers=	YES
.  endif
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.tcp_wrappers:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.tcp_wrappers=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.tcp_wrappers)
.  if !empty(BUILDLINK_IS_BUILTIN.tcp_wrappers:M[nN][oO])
BUILDLINK_USE_BUILTIN.tcp_wrappers=	NO
.  else
BUILDLINK_USE_BUILTIN.tcp_wrappers=	YES
.  endif
.endif

.if !empty(BUILDLINK_USE_BUILTIN.tcp_wrappers:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcp_wrappers
.  endif
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
