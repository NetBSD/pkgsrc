# $NetBSD: buildlink2.mk,v 1.5 2003/11/08 07:40:17 xtraeme Exp $
#

.if !defined(NESSUS_LIBRARIES_BUILDLINK2_MK)
NESSUS_LIBRARIES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			nessus-libraries
BUILDLINK_DEPENDS.nessus-libraries?=		nessus-libraries>=2.0.9
BUILDLINK_PKGSRCDIR.nessus-libraries?=		../../security/nessus-libraries

EVAL_PREFIX+=	BUILDLINK_PREFIX.nessus-libraries=nessus-libraries
BUILDLINK_PREFIX.nessus-libraries_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.nessus-libraries+=	include/nessus/getopt.h
BUILDLINK_FILES.nessus-libraries+=	include/nessus/harglists.h
BUILDLINK_FILES.nessus-libraries+=	include/nessus/libnessus.h
BUILDLINK_FILES.nessus-libraries+=	include/nessus/libvers.h
BUILDLINK_FILES.nessus-libraries+=	include/nessus/net/bpf.h
BUILDLINK_FILES.nessus-libraries+=	include/nessus/pcap-namedb.h
BUILDLINK_FILES.nessus-libraries+=	include/nessus/pcap.h
BUILDLINK_FILES.nessus-libraries+=	lib/libhosts_gatherer.*
BUILDLINK_FILES.nessus-libraries+=	lib/libnessus.*
BUILDLINK_FILES.nessus-libraries+=	lib/libpcap-nessus.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	nessus-libraries-buildlink

nessus-libraries-buildlink: _BUILDLINK_USE

.endif	# NESSUS_LIBRARIES_BUILDLINK2_MK
