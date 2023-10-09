# $NetBSD: buildlink3.mk,v 1.5 2023/10/09 04:54:06 pho Exp $

BUILDLINK_TREE+=	hs-OneTuple

.if !defined(HS_ONETUPLE_BUILDLINK3_MK)
HS_ONETUPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-OneTuple+=	hs-OneTuple>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-OneTuple+=	hs-OneTuple>=0.3.1nb4
BUILDLINK_PKGSRCDIR.hs-OneTuple?=	../../devel/hs-OneTuple
.endif	# HS_ONETUPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-OneTuple
