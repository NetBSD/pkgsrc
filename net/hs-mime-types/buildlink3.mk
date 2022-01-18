# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:19 pho Exp $

BUILDLINK_TREE+=	hs-mime-types

.if !defined(HS_MIME_TYPES_BUILDLINK3_MK)
HS_MIME_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mime-types+=	hs-mime-types>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-mime-types+=	hs-mime-types>=0.1.0.9nb2
BUILDLINK_PKGSRCDIR.hs-mime-types?=	../../net/hs-mime-types
.endif	# HS_MIME_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mime-types
