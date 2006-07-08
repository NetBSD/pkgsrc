# $NetBSD: buildlink3.mk,v 1.19 2006/07/08 23:11:03 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBPCAP_BUILDLINK3_MK:=	${LIBPCAP_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libpcap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibpcap}
BUILDLINK_PACKAGES+=	libpcap
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libpcap

.if !empty(LIBPCAP_BUILDLINK3_MK:M+)
# XXX?
BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.5.0
BUILDLINK_PKGSRCDIR.libpcap?=	../../net/libpcap

# on Solaris, we always need libnsl and libsocket because libpcap.a
# references symbols in them.
.  if ${OPSYS} == "SunOS"
BUILDLINK_LDADD.libpcap+=	-lnsl -lsocket
BUILDLINK_LDFLAGS.libpcap?=	${BUILDLINK_LDADD.libpcap}
.  endif

.endif	# LIBPCAP_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
