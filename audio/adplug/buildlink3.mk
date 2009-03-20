# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	adplug

.if !defined(ADPLUG_BUILDLINK3_MK)
ADPLUG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adplug+=	adplug>=2.1
BUILDLINK_PKGSRCDIR.adplug?=	../../audio/adplug

.include "../../devel/libbinio/buildlink3.mk"
.endif # ADPLUG_BUILDLINK3_MK

BUILDLINK_TREE+=	-adplug
