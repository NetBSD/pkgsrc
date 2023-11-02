# $NetBSD: buildlink3.mk,v 1.10 2023/11/02 06:36:29 pho Exp $

BUILDLINK_TREE+=	hs-file-embed

.if !defined(HS_FILE_EMBED_BUILDLINK3_MK)
HS_FILE_EMBED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-file-embed+=	hs-file-embed>=0.0.15
BUILDLINK_ABI_DEPENDS.hs-file-embed+=	hs-file-embed>=0.0.15.0nb5
BUILDLINK_PKGSRCDIR.hs-file-embed?=	../../devel/hs-file-embed
.endif	# HS_FILE_EMBED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-file-embed
