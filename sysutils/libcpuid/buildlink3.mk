# $NetBSD: buildlink3.mk,v 1.2 2025/08/10 13:35:20 ryoon Exp $

BUILDLINK_TREE+=	libcpuid

.if !defined(LIBCPUID_BUILDLINK3_MK)
LIBCPUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcpuid+=	libcpuid>=0.6.5
BUILDLINK_PKGSRCDIR.libcpuid?=		../../sysutils/libcpuid
.endif	# LIBCPUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcpuid
