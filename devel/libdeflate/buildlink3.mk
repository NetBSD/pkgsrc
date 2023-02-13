# $NetBSD: buildlink3.mk,v 1.1 2023/02/13 08:28:38 wiz Exp $

BUILDLINK_TREE+=	libdeflate

.if !defined(LIBDEFLATE_BUILDLINK3_MK)
LIBDEFLATE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libdeflate?=	build

BUILDLINK_API_DEPENDS.libdeflate+=	libdeflate>=1.10
BUILDLINK_PKGSRCDIR.libdeflate?=	../../devel/libdeflate
.endif	# LIBDEFLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdeflate
