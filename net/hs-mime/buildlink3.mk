# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 17:42:35 pho Exp $

BUILDLINK_TREE+=	hs-mime

.if !defined(HS_MIME_BUILDLINK3_MK)
HS_MIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mime+=	hs-mime>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-mime+=	hs-mime>=0.4.0.2
BUILDLINK_PKGSRCDIR.hs-mime?=	../../net/hs-mime

.endif	# HS_MIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mime
