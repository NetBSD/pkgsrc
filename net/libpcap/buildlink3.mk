# $NetBSD: buildlink3.mk,v 1.5 2004/01/24 03:12:32 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPCAP_BUILDLINK3_MK:=	${LIBPCAP_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(LIBPCAP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libpcap
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.7.2
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
BUILDLINK_USE_BUILTIN.libpcap=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.libpcap)
.  if !empty(BUILDLINK_IS_BUILTIN.libpcap:M[nN][oO])
BUILDLINK_USE_BUILTIN.libpcap=	NO
.  else
BUILDLINK_USE_BUILTIN.libpcap=	YES
.  endif
.endif

.if !empty(BUILDLINK_USE_BUILTIN.libpcap:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libpcap
.  endif
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
