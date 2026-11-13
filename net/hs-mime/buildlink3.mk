# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:38 pho Exp $

BUILDLINK_TREE+=	hs-mime

.if !defined(HS_MIME_BUILDLINK3_MK)
HS_MIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mime+=	hs-mime>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-mime+=	hs-mime>=0.4.0.2nb2
BUILDLINK_PKGSRCDIR.hs-mime?=	../../net/hs-mime

.endif	# HS_MIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mime
