# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:44 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPCAP_BUILDLINK3_MK:=	${LIBPCAP_BUILDLINK3_MK}+

.if !empty(LIBPCAP_BUILDLINK3_MK:M\+)
.  include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.libpcap?=	libpcap>=0.7.2
BUILDLINK_PKGSRCDIR.libpcap?=	../../net/libpcap
.endif	# LIBPCAP_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.libpcap?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.libpcap)
BUILDLINK_IS_BUILTIN.libpcap=	NO
.  if exists(/usr/include/pcap.h)
BUILDLINK_IS_BUILTIN.libpcap=	YES
.  endif
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.libpcap:M[yY][eE][sS])
_NEED_LIBPCAP=	NO
.endif

.if !defined(_NEED_LIBPCAP)
.  if !empty(BUILDLINK_IS_BUILTIN.libpcap:M[nN][oO])
_NEED_LIBPCAP=	YES
.  else
_NEED_LIBPCAP=	NO
.  endif
MAKEFLAGS+=	_NEED_LIBPCAP="${_NEED_LIBPCAP}"
.endif

.if ${_NEED_LIBPCAP} == "YES"
.  if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	libpcap
.  endif
.endif

.if !empty(LIBPCAP_BUILDLINK3_MK:M\+)
.  if ${_NEED_LIBPCAP} == "YES"
BUILDLINK_PACKAGES+=		libpcap
.  else
BUILDLINK_PREFIX.libpcap=	/usr
.  endif
.endif	# LIBPCAP_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
