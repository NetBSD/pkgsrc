# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:39:47 riastradh Exp $

BUILDLINK_TREE+=	hs-file-embed

.if !defined(HS_FILE_EMBED_BUILDLINK3_MK)
HS_FILE_EMBED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-file-embed+=	hs-file-embed>=0.0.11.2
BUILDLINK_ABI_DEPENDS.hs-file-embed+=	hs-file-embed>=0.0.11.2
BUILDLINK_PKGSRCDIR.hs-file-embed?=	../../devel/hs-file-embed
.endif	# HS_FILE_EMBED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-file-embed
