# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:18 pho Exp $

BUILDLINK_TREE+=	hs-persistent-template

.if !defined(HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK)
HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-persistent-template+=	hs-persistent-template>=2.12.0
BUILDLINK_ABI_DEPENDS.hs-persistent-template+=	hs-persistent-template>=2.12.0.0nb3
BUILDLINK_PKGSRCDIR.hs-persistent-template?=	../../devel/hs-persistent-template
.endif	# HS_PERSISTENT_TEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-persistent-template
