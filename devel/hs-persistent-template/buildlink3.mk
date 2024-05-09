# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:07 pho Exp $

BUILDLINK_TREE+=	hs-persistent-template

.if !defined(HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK)
HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-persistent-template+=	hs-persistent-template>=2.12.0
BUILDLINK_ABI_DEPENDS.hs-persistent-template+=	hs-persistent-template>=2.12.0.0nb2
BUILDLINK_PKGSRCDIR.hs-persistent-template?=	../../devel/hs-persistent-template
.endif	# HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-persistent-template
