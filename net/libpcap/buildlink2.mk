# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:38 jlam Exp $

.if !defined(LIBPCAP_BUILDLINK2_MK)
LIBPCAP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=	libpcap

.if exists(/usr/include/pcap.h)
_NEED_LIBPCAP=		NO
.else
_NEED_LIBPCAP=		YES
.endif

.if ${_NEED_LIBPCAP} == "YES"
BUILDLINK_DEPENDS.libpcap?=	libpcap>=0.7.1
BUILDLINK_PKGSRCDIR.libpcap?=	../../net/libpcap

EVAL_PREFIX+=		BUILDLINK_PREFIX.libpcap=libpcap
BUILDLINK_PREFIX.libpcap_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.libpcap=	/usr
.endif

BUILDLINK_FILES.libpcap=	include/pcap.h
BUILDLINK_FILES.libpcap+=	include/pcap-namedb.h
BUILDLINK_FILES.libpcap+=	include/net/bpf.h
BUILDLINK_FILES.libpcap+=	lib/libpcap.*

BUILDLINK_TARGETS+=	libpcap-buildlink

libpcap-buildlink: _BUILDLINK_USE

.endif	# LIBPCAP_BUILDLINK2_MK
