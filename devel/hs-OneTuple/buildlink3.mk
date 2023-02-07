# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:26 pho Exp $

BUILDLINK_TREE+=	hs-OneTuple

.if !defined(HS_ONETUPLE_BUILDLINK3_MK)
HS_ONETUPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-OneTuple+=	hs-OneTuple>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-OneTuple+=	hs-OneTuple>=0.3.1nb3
BUILDLINK_PKGSRCDIR.hs-OneTuple?=	../../devel/hs-OneTuple
.endif	# HS_ONETUPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-OneTuple
