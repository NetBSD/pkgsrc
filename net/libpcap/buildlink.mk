# $NetBSD: buildlink.mk,v 1.3 2002/02/13 15:25:16 seb Exp $
#
# This Makefile fragment is included by packages that use libpcap. 
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libpcap to the dependency pattern
#     for the version of libpcap desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBPCAP_BUILDLINK_MK)
LIBPCAP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libpcap?=	libpcap>=0.7.1

.if exists(/usr/include/pcap.h)
_NEED_LIBPCAP=		NO
.else
_NEED_LIBPCAP=		YES
.endif

.if ${_NEED_LIBPCAP} == "YES"
DEPENDS+=		${BUILDLINK_DEPENDS.libpcap}:../../net/libpcap
EVAL_PREFIX+=		BUILDLINK_PREFIX.libpcap=libpcap
BUILDLINK_PREFIX.libpcap_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.libpcap=	/usr
.endif

BUILDLINK_FILES.libpcap=	include/pcap.h
BUILDLINK_FILES.libpcap+=	include/pcap-namedb.h
BUILDLINK_FILES.libpcap+=	include/net/bpf.h
BUILDLINK_FILES.libpcap+=	lib/libpcap.*

BUILDLINK_TARGETS.libpcap=	libpcap-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libpcap}

pre-configure: ${BUILDLINK_TARGETS.libpcap}
libpcap-buildlink: _BUILDLINK_USE

.endif	# LIBPCAP_BUILDLINK_MK
