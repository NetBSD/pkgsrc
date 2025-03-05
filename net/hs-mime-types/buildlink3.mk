# $NetBSD: buildlink3.mk,v 1.13 2025/03/05 03:39:46 pho Exp $

BUILDLINK_TREE+=	hs-mime-types

.if !defined(HS_MIME_TYPES_BUILDLINK3_MK)
HS_MIME_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mime-types+=	hs-mime-types>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-mime-types+=	hs-mime-types>=0.1.2.0nb4
BUILDLINK_PKGSRCDIR.hs-mime-types?=	../../net/hs-mime-types
.endif	# HS_MIME_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mime-types
