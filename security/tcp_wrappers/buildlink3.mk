# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:45 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCP_WRAPPERS_BUILDLINK3_MK:=	${TCP_WRAPPERS_BUILDLINK3_MK}+

.if !empty(TCP_WRAPPERS_BUILDLINK3_MK:M\+)
.  include "../../mk/bsd.prefs.mk"

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
_NEED_TCP_WRAPPERS=	NO
.endif

.if !defined(_NEED_TCP_WRAPPERS)
.  if !empty(BUILDLINK_IS_BUILTIN.tcp_wrappers:M[nN][oO])
_NEED_TCP_WRAPPERS=	YES
.  else
_NEED_TCP_WRAPPERS=	NO
.  endif
MAKEFLAGS+=	_NEED_TCP_WRAPPERS="${_NEED_TCP_WRAPPERS}"
.endif

.if ${_NEED_TCP_WRAPPERS} == "YES"
.  if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	tcp_wrappers
.  endif
.endif

.if !empty(TCP_WRAPPERS_BUILDLINK3_MK:M\+)
.  if ${_NEED_TCP_WRAPPERS} == "YES"
BUILDLINK_PACKAGES+=		tcp_wrappers
.  else
BUILDLINK_PREFIX.tcp_wrappers=	/usr
.  endif
.endif	# TCP_WRAPPERS_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
