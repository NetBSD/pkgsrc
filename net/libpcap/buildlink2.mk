# $NetBSD: buildlink2.mk,v 1.8 2004/02/12 02:35:07 jlam Exp $

.if !defined(LIBPCAP_BUILDLINK2_MK)
LIBPCAP_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.libpcap?=	libpcap>=0.7.2
BUILDLINK_PKGSRCDIR.libpcap?=	../../net/libpcap

.if exists(/usr/include/pcap.h)
_BUILTIN_LIBPCAP=	YES
.else
_BUILTIN_LIBPCAP=	NO
.endif

.if ${_BUILTIN_LIBPCAP} == "YES"
_NEED_LIBPCAP=	NO
.else
_NEED_LIBPCAP=	YES
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    ${_BUILTIN_LIBPCAP} == "YES"
_NEED_LIBPCAP=	NO
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_NEED_LIBPCAP=	YES
.endif
.if !empty(PREFER_NATIVE:Mlibpcap) && \
    ${_BUILTIN_LIBPCAP} == "YES"
_NEED_LIBPCAP=	NO
.endif
.if !empty(PREFER_PKGSRC:Mlibpcap)
_NEED_LIBPCAP=	YES
.endif

.if ${_NEED_LIBPCAP} == "YES"
BUILDLINK_PACKAGES+=	libpcap
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
