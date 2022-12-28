# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 19:10:57 nikita Exp $

BUILDLINK_TREE+=	libcpuid

.if !defined(LIBCPUID_BUILDLINK3_MK)
LIBCPUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcpuid+=	libcpuid>=0.5.1
BUILDLINK_ABI_DEPENDS.libcpuid?=	libcpuid>=0.5.1
BUILDLINK_PKGSRCDIR.libcpuid?=	../../sysutils/libcpuid
.endif	# LIBCPUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcpuid
