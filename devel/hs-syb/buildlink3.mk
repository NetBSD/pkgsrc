# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:08:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-syb

.if !defined(HS_SYB_BUILDLINK3_MK)
HS_SYB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-syb+=	hs-syb>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-syb+=	hs-syb>=0.4.2
BUILDLINK_PKGSRCDIR.hs-syb?=	../../devel/hs-syb
.endif	# HS_SYB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-syb
