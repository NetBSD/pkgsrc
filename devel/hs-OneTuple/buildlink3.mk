# $NetBSD: buildlink3.mk,v 1.3 2022/02/26 03:57:47 pho Exp $

BUILDLINK_TREE+=	hs-OneTuple

.if !defined(HS_ONETUPLE_BUILDLINK3_MK)
HS_ONETUPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-OneTuple+=	hs-OneTuple>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-OneTuple+=	hs-OneTuple>=0.3.1nb2
BUILDLINK_PKGSRCDIR.hs-OneTuple?=	../../devel/hs-OneTuple
.endif	# HS_ONETUPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-OneTuple
