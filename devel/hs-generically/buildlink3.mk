# $NetBSD: buildlink3.mk,v 1.1 2022/08/19 12:10:41 wiz Exp $

BUILDLINK_TREE+=	hs-generically

.if !defined(HS_GENERICALLY_BUILDLINK3_MK)
HS_GENERICALLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generically+=	hs-generically>=0.1
BUILDLINK_PKGSRCDIR.hs-generically?=	../../devel/hs-generically
.endif	# HS_GENERICALLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generically
