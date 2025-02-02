# $NetBSD: buildlink3.mk,v 1.13 2025/02/02 13:05:05 pho Exp $

BUILDLINK_TREE+=	hs-file-embed

.if !defined(HS_FILE_EMBED_BUILDLINK3_MK)
HS_FILE_EMBED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-file-embed+=	hs-file-embed>=0.0.16
BUILDLINK_ABI_DEPENDS.hs-file-embed+=	hs-file-embed>=0.0.16.0nb2
BUILDLINK_PKGSRCDIR.hs-file-embed?=	../../devel/hs-file-embed
.endif	# HS_FILE_EMBED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-file-embed
