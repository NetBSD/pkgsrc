# $NetBSD: buildlink3.mk,v 1.7 2026/11/13 14:39:11 pho Exp $

BUILDLINK_TREE+=	hs-persistent-template

.if !defined(HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK)
HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-persistent-template+=	hs-persistent-template>=2.12.0
BUILDLINK_ABI_DEPENDS.hs-persistent-template+=	hs-persistent-template>=2.12.0.0nb6
BUILDLINK_PKGSRCDIR.hs-persistent-template?=	../../devel/hs-persistent-template
.endif	# HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-persistent-template
