# $NetBSD: buildlink3.mk,v 1.4 2023/05/06 18:57:10 ryoon Exp $

BUILDLINK_TREE+=	libopus

.if !defined(LIBOPUS_BUILDLINK3_MK)
LIBOPUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopus+=	libopus>=1.1
BUILDLINK_ABI_DEPENDS.libopus+=	libopus>=1.4
BUILDLINK_PKGSRCDIR.libopus?=	../../audio/libopus
.endif	# LIBOPUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopus
